#pragma once
#include"MoveActor.h"

class BulletActor :public MoveActor {
public:
	enum BulletType {
		EPlayer,
		EEnemy,
	};

	BulletActor(class Game* game, BulletType type);
	void UpdateActor(float deltaTime)override;
	virtual void CalcSetVelocity(float deltaTime);

	int GetAttack()const { return mAttack; }
	void SetAttack(int attack) { mAttack = attack; }

	const BulletType& SetBulletType()const { return mType; }

private:
	int mAttack;
	BulletType mType;
};