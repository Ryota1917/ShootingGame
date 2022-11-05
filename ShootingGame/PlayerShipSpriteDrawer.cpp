#include"PlayerShipSpriteDrawer.h"
#include"PlayerShip.h"

PlayerShipSpriteDrawer::PlayerShipSpriteDrawer(const std::string& fileName, PlayerShip* owner, int order):
	SpriteDrawer(fileName,owner,order),mPlayerShip(owner),mCntTime(0),mIsClear(false)
{
}

void PlayerShipSpriteDrawer::Draw(SDL_Renderer* renderer)
{
	if (!mIsClear) {
		if (mTexture) {
			SDL_Rect r;
			r.w = static_cast<int>(mTexWidth * mOwner->GetScale().x);
			r.h = static_cast<int>(mTexHeight * mOwner->GetScale().y);
			r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2);
			r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2);

			SDL_RenderCopyEx(renderer, mTexture, nullptr, &r, -Math::ToDegrees(mOwner->GetRotate()), nullptr, SDL_FLIP_NONE);
		}
	}
	else {

	}
}

void PlayerShipSpriteDrawer::Update(float deltaTime)
{
	if (mPlayerShip->GetPlayerShipState() == PlayerShip::PlayerShipState::EDamaged) {
		mCntTime += deltaTime;
		if (mCntTime > 0.15f) {
			mIsClear = !mIsClear;
			mCntTime = 0;
		}
	}
	else {
		mIsClear = false;
	}
}
