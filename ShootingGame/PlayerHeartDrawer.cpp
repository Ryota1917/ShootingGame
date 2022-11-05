#include"PlayerHeartDrawer.h"
#include"PlayerShip.h"

PlayerHeartDrawer::PlayerHeartDrawer(const std::string& fileName, PlayerShip* owner, int order):
	SpriteDrawer(fileName,owner,order),mPlayerShip(owner)
{
}

void PlayerHeartDrawer::Draw(SDL_Renderer* renderer)
{
	if (mTexture) {
		SDL_Rect r;
		r.w = static_cast<int>(mTexWidth);
		r.h = static_cast<int>(mTexHeight);
		r.x = static_cast<int>(0);
		r.y = static_cast<int>(50);
		for (int i = 0; i < mPlayerShip->GetHP(); i++) {
			r.x += 40;
			SDL_RenderCopyEx(renderer, mTexture, nullptr, &r, -Math::ToDegrees(mOwner->GetRotate()), nullptr, SDL_FLIP_NONE);
		}
	}
}
