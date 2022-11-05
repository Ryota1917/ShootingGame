#include "PlayerShip.h"
#include"KeyMoveComponent.h"
#include"PlayerShipSpriteDrawer.h"
#include"CircleCollisionComponent.h"
#include"PlayerGunComponent.h"
#include"GunBangInterface.h"
#include"GunGenerateInterface.h"
#include"PlayerHeartDrawer.h"
#include"GameSceneManeger.h"

PlayerShip::PlayerShip(Game* game):
	ShipActor(game),mShipState(EActive),mDamagedTime(0.0f)
{
	SetPosition(Vector2(500, 600));
	auto c = new KeyMoveComponent(this);
	c->SetSpeed(Vector2(10, 10));
	new PlayerShipSpriteDrawer("../Assets/Ship13.png", this, 200);
	new CircleCollisionComponent(this, 13);
	new PlayerGunComponent(this,new GunBangInterFace(), new GunGenerateInterface());
	new PlayerHeartDrawer("../Assets/hart.png", this, 300);
}

void PlayerShip::UpdateActor(float deltaTime)
{
	if (mHp <= 0) {
		SetState(State::EDead);
		GetGame()->GetGameScene()->SetNextState();
	}

	if (mShipState == EDamaged) {
		mDamagedTime += deltaTime;
		if (mDamagedTime > 3.0f) {
			mShipState = EActive;
			mDamagedTime = 0;
		}
	}
}

void PlayerShip::Damage(BulletActor* bullet)
{
	if (mShipState == EActive) {
		mHp -= bullet->GetAttack();
		mShipState = EDamaged;
	}
}
