#pragma once
#include"SpriteDrawer.h"

class ScrollSpriteDrawerY :public SpriteDrawer {
public:
	ScrollSpriteDrawerY(float speed,const std::string& fileName, Actor* owner, int order = 100);

	void Update(float deltaTime)override;
	void Draw(SDL_Renderer* renderer)override;

	void SetSpeed(float speed) { mScrollSpeed = speed; }

private:
	float mScrollSpeed;
	float mScrollOffset;
};