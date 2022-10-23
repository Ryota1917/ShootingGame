#include"GunSingleGenerate.h"
#include"GunComponent.h"

GunSingleGenerate::GunSingleGenerate(const Vector2& setOffset, const Vector2& bulletSpeed):
	mSetOffset(setOffset), mBulletSpeed(bulletSpeed)
{
}

void GunSingleGenerate::Generate(GunComponent* gun)
{
	auto b = gun->BulletCreate();
	b->SetVelo(mBulletSpeed);
	b->SetPosition(gun->GetOwner()->GetPosition() + mSetOffset);
}