#pragma once
#include"GunBangInterface.h"

class GunTimeBang : public GunBangInterFace {
public:
	GunTimeBang(float limitTime);
	bool Bang(float deltaTime) override;
private:
	float mLimitTime;
	float mCurrentTime;
};