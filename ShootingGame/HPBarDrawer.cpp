#include"HPBarDrawer.h"
#include"ShipActor.h"

HPBarDrawer::HPBarDrawer(ShipActor* owner, int order):
	Drawer(owner,order),mShip(owner)
{}

void HPBarDrawer::Draw(SDL_Renderer* renderer)
{
	SDL_Rect r;
	r.w = static_cast<int>(20);
	r.h = static_cast<int>(5);
	r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2);
	r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2 + 30);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &r);

	int range = 18-18 * mShip->GetHP() / mShip->GetMaxHp();
	r.w = static_cast<int>(18-range);
	r.h = static_cast<int>(3);
	r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2 - range / 2);
	r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2 + 30);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &r);
}