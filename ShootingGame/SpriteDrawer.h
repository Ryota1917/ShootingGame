#pragma once
#include"Drawer.h"
#include"SDL.h"
#include<string>

class SpriteDrawer:public Drawer {
public:
	SpriteDrawer(const std::string& fileName, class Actor* owner, int order = 100);

	void Draw(SDL_Renderer* renderer)override;

	void SetTexture(SDL_Texture* texture);
	
	int GetHeight() const { return mTexHeight; }
	void SetHeight(int height) { mTexHeight = height; }
	int GetWidth()const { return mTexWidth; }
	void SetWidth(int width) { mTexWidth = width; }

private:
	SDL_Texture* mTexture;

	int mTexHeight;
	int mTexWidth;
};