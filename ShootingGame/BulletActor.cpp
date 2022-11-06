#include "BulletActor.h"
#include"SpriteDrawer.h"
#include"CircleCollisionComponent.h"
#include"ShipActor.h"
#include"PlayerShip.h"

BulletActor::BulletActor(Game* game, BulletType type):
	MoveActor(game),mAttack(1), mType(type)
{
	new SpriteDrawer("../Assets/circle_bullet4.png", this , 150);
	auto c = new CircleCollisionComponent(this, 4.0f);
	c->AddCollisionEvent(
		[&](Actor* other) {
			switch (mType) {
			case EPlayer: {
				auto ship = dynamic_cast<ShipActor*>(other);
				if (ship == NULL) {
					return;
				}
				//SDL_Log("Collision ShipActor and Bullt Eplayer!");
				ship->Damage(this);
				SetState(State::EDead);
				break;
			}

			case EEnemy: {
				auto pship = dynamic_cast<PlayerShip*>(other);
				if (pship == NULL) {
					return;
				}
				//SDL_Log("Collision PlayerShip and Bullt EEnemy!");
				pship->Damage(this);
				SetState(State::EDead);
				break;
			}
			}

		}
	);
}

void BulletActor::UpdateActor(float deltaTime) {
	this->CalcSetVelocity(deltaTime);
	const Vector2& pos = GetPosition();
	if (pos.x < -10 || pos.x > 1034 || pos.y < -10 || pos.y > 774) {
		SetState(State::EDead);
	}
}

void BulletActor::CalcSetVelocity(float deltaTime)
{
}
