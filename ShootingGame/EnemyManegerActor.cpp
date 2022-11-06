#include "EnemyManegerActor.h"
#include"EnemyShipActor.h"
#include"GunComponent.h"
#include"GunTimeBang.h"
#include"GunSingleGenerate.h"
#include"AutoMoveComponent.h"

EnemyManegerActor::EnemyManegerActor(Game* game) :
	Actor(game), mRandom(), mDeltaElapsedTime(0), mEnemiyNum(0), mDeleteEnemyNum(0)
{
}

void EnemyManegerActor::UpdateActor(float deltaTime)
{
	mDeltaElapsedTime += deltaTime;

	if (mDeltaElapsedTime > 3.0f) {
		mDeltaElapsedTime = Generate() ? 0 : 2.0f;
	}
}

bool EnemyManegerActor::Generate()
{
	if (mEnemiyNum >= 10) {
		return false;
	}

	auto enemy = new EnemyShipActor(GetGame(), this, mRandom.rand(1,5));
	enemy->SetPosition(Vector2(mRandom.rand(200, 900), mRandom.rand(100, 300)));
	new GunComponent(enemy, new GunTimeBang(mRandom.randFloat(0.3f,1.0f)), new GunSingleGenerate(Vector2(0, 30), Vector2(0, 100)));
	new AutoMoveComponent(enemy, mRandom.rand(-5, 6)*100);
	mEnemiyNum++;
	return true;
}

void EnemyManegerActor::DeleteEnemy()
{
	mEnemiyNum--;
	mDeleteEnemyNum++;
}
