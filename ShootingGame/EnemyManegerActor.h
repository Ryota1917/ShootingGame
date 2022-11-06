#pragma once
#include"Actor.h"
#include"RandomXor.h"
#include<vector>

class EnemyManegerActor :public Actor {
public:
	EnemyManegerActor(class Game* game);

	void UpdateActor(float deltaTime)override;

	bool Generate();

	void DeleteEnemy();

	int GetDeleteEnemyNum()const { return mDeleteEnemyNum; }

private:
	RandomXor mRandom;

	int mEnemiyNum;
	int mDeleteEnemyNum;

	float mDeltaElapsedTime;
};
