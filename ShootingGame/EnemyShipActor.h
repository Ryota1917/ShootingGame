#pragma once
#include"ShipActor.h"

class EnemyShipActor :public ShipActor {
public:
	EnemyShipActor(class Game* game,class EnemyManegerActor* maneger,int hp);
	void UpdateActor(float deltaTime)override;

private:
	class EnemyManegerActor* mManeger;
};