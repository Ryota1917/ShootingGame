#include"SpriteDrawer.h"
#include"Actor.h"

SpriteDrawer::SpriteDrawer(const std::string& fileName, Actor* owner, int order) :
	Drawer(owner, order), mTexture(nullptr), mTexHeight(0), mTexWidth(0),mOffset(Vector2::Zero)
{
	SetTexture(mOwner->GetGame()->GetTexture(fileName));
}

SpriteDrawer::~SpriteDrawer()
{
}

void SpriteDrawer::Draw(SDL_Renderer* renderer) {
	if (mTexture) {
		SDL_Rect r;
		r.w = static_cast<int>(mTexWidth * mOwner->GetScale().x);
		r.h = static_cast<int>(mTexHeight * mOwner->GetScale().y);
		r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2 + mOffset.x);
		r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2 + mOffset.y);

		SDL_RenderCopyEx(renderer, mTexture, nullptr, &r, -Math::ToDegrees(mOwner->GetRotate()), nullptr, SDL_FLIP_NONE);
	}
}

void SpriteDrawer::SetTexture(SDL_Texture* texture) {
	mTexture = texture;
	SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}
