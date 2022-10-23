#include"GunTimeBang.h"
#include"SDL.h"

GunTimeBang::GunTimeBang(float limitTime):
	mLimitTime(limitTime),mCurrentTime(0)
{}

bool GunTimeBang::Bang(float deltaTime)
{
	mCurrentTime += deltaTime;
	if (mCurrentTime > mLimitTime) {
		mCurrentTime = 0;
		SDL_Log("Bang!!");
		return true;
	}
	return  false;
}
