#pragma once
#include"GunComponent.h"

class PlayerGunComponent : public  GunComponent{
public:
	PlayerGunComponent(class ShipActor* owner, GunBangInterFace* bang, GunGenerateInterface* generate);
	void ProcessInput(const struct InputState& state) override;
};