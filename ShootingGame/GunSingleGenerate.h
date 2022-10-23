#pragma once
#include"GunGenerateInterface.h"
#include"Math.h"

class GunSingleGenerate : public GunGenerateInterface {
public:
	GunSingleGenerate(const Vector2& setOffset,  const Vector2& bulletSpeed);
	void Generate(class GunComponent* gun) override;

private:
	Vector2 mSetOffset;
	Vector2 mBulletSpeed;
};