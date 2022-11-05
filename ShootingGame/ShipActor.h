#pragma once
#include"MoveActor.h"

class ShipActor :public MoveActor {
public:
	ShipActor(class Game* game);
	void UpdateActor(float deltaTime)override;

	virtual void Damage(class BulletActor* bullet);

	int GetHP()const { return mHp; }
	void SetHP(int hp) { mHp = hp; }
	int GetMaxHp()const { return mMaxHp; }

	void SetGun(class GunComponent* gun);

protected:
	int mHp;
	int mMaxHp;
	class GunComponent* mGun;
};