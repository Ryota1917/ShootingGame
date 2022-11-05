#pragma once
#include"SpriteDrawer.h"

class PlayerShipSpriteDrawer :public SpriteDrawer {
public:
	PlayerShipSpriteDrawer(const std::string& fileName, class PlayerShip* owner, int order = 100);

	void Draw(SDL_Renderer* renderer)override;
	void Update(float deltaTime)override;

private:
	PlayerShip* mPlayerShip;
	float mCntTime;
	bool mIsClear;
};