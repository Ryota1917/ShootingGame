#pragma once
#include"MoveActor.h"

class ShipActor :public MoveActor {
public:
	ShipActor(class Game* game);
	void UpdateActor(float deltaTime)override;

	virtual void Damage(class BulletActor* bullet);

	int GetHP()const { return mHp; }
	void SetHP(int hp) { mHp = hp; }

	void SetGun(class GunComponent* gun);

private:
	int mHp;
	class GunComponent* mGun;
};