#include "PlayerShip.h"
#include"KeyMoveComponent.h"
#include"SpriteDrawer.h"
#include"CircleCollisionComponent.h"
#include"PlayerGunComponent.h"
#include"GunBangInterface.h"
#include"GunGenerateInterface.h"


PlayerShip::PlayerShip(Game* game):
	ShipActor(game)
{
	SetPosition(Vector2(500, 600));
	auto c = new KeyMoveComponent(this);
	c->SetSpeed(Vector2(10, 10));
	new SpriteDrawer("../Assets/Test12.png", this, 200);
	new CircleCollisionComponent(this, 12);
	new PlayerGunComponent(this,GunBangInterFace(),GunGenerateInterface());
}
