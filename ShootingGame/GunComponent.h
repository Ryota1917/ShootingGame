#pragma once
#include<string>
#include"Component.h"
#include"BulletActor.h"
#include"GunBangInterface.h"
#include"GunGenerateInterface.h"

class GunComponent :public Component {
public:
	GunComponent(class ShipActor* owner, GunBangInterFace* bang, GunGenerateInterface* generate);
	virtual ~GunComponent();

	void Update(float deltaTime)override;

	BulletActor* BulletCreate();

private:
	BulletActor* BulletFactory(const std::string& bulletName, BulletActor::BulletType type);
	std::string mBulletName;
	BulletActor::BulletType mType;

	GunBangInterFace* mBang;
	GunGenerateInterface* mGenerate;
};