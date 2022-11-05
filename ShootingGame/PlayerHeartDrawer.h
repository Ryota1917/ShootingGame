#pragma once
#include"SpriteDrawer.h"

class PlayerHeartDrawer :public SpriteDrawer {
public:
	PlayerHeartDrawer(const std::string& fileName, class PlayerShip* owner, int order = 100);
	void Draw(SDL_Renderer* renderer)override;

private:
	PlayerShip* mPlayerShip;
};