#pragma once
#include"ShipActor.h"

class PlayerShip :public ShipActor {
public:
	enum PlayerShipState {
		EActive,
		EDamaged
	};

	PlayerShip(class Game* game);

	void UpdateActor(float deltaTime)override;
	void Damage(class BulletActor* bullet)override;

	PlayerShipState GetPlayerShipState()const { return mShipState; }

private:
	PlayerShipState mShipState;
	float mDamagedTime;
};