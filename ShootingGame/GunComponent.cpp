#include "GunComponent.h"
#include"ShipActor.h"

GunComponent::GunComponent(ShipActor* owner, GunBangInterFace* bang, GunGenerateInterface* generate):
	Component(owner),mBang(bang),mGenerate(generate),mBulletName("normal"),mType(BulletActor::BulletType::EEnemy)
{
}

GunComponent::~GunComponent()
{
	delete mBang;
	delete mGenerate;
}

BulletActor* GunComponent::BulletFactory(const std::string& bulletName, BulletActor::BulletType type)
{
	if (bulletName == "normal") {
		return new BulletActor(mOwner->GetGame(), type);
	}
	else {
		return new BulletActor(mOwner->GetGame(), type);
	}
}


void GunComponent :: Update(float deltaTime) {
	if (mBang->Bang(deltaTime)) {
		mGenerate->Generate(this);
	}
}

BulletActor* GunComponent::BulletCreate() {
	return BulletFactory(mBulletName, mType);
}