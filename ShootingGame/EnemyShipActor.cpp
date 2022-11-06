#include "EnemyShipActor.h"
#include"SpriteDrawer.h"
#include"CircleCollisionComponent.h"
#include"HPBarDrawer.h"
#include"EnemyManegerActor.h"
#include"BulletActor.h"

EnemyShipActor::EnemyShipActor(Game* game, EnemyManegerActor* maneger, int hp):
	ShipActor(game, hp),mManeger(maneger)
{
	new SpriteDrawer("../Assets/Enemy24.png", this, 200);
	new CircleCollisionComponent(this, 24);
	new HPBarDrawer(this, 200);
}

void EnemyShipActor::UpdateActor(float deltaTime)
{
	if (mHp <= 0) {
		mManeger->DeleteEnemy();
		SetState(State::EDead);
	}
}