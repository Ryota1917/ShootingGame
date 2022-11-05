#include "ShipActor.h"
#include"BulletActor.h"
#include "GunComponent.h"

ShipActor::ShipActor(Game* game):
	MoveActor(game),mHp(3)
{
}

void ShipActor::UpdateActor(float deltaTime)
{
	if (mHp <= 0) {
		SetState(State::EDead);
	}
}

void ShipActor::Damage(BulletActor* bullet)
{
	mHp -= bullet->GetAttack();
}

void ShipActor::SetGun(GunComponent* gun)
{
	if (gun != nullptr) {
		delete gun;
	}
	mGun = gun;
}
