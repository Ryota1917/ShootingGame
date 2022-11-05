#include"Game.h"
#include"Actor.h"
#include"PlayerShip.h"
#include"RockActor.h"
#include"GunComponent.h"
#include"GunTimeBang.h"
#include"GunSingleGenerate.h"
#include"AutoMoveComponent.h"
#include"ScrollSpriteDrawerY.h"

void Game::LoadData() {
	new PlayerShip(this);

	auto r = new RockActor(this);
	r->SetPosition(Vector2(400, 150));
	new GunComponent(r, new GunTimeBang(1.0f), new GunSingleGenerate(Vector2(0, 30), Vector2(0, 100)));

	
	r = new RockActor(this);
	r->SetPosition(Vector2(500, 100));
	new GunComponent(r, new GunTimeBang(0.5f), new GunSingleGenerate(Vector2(0, 30), Vector2(0, 100)));
	new AutoMoveComponent(r);


	r = new RockActor(this);
	r->SetPosition(Vector2(700, 250));
	new GunComponent(r, new GunTimeBang(1.0f), new GunSingleGenerate(Vector2(0, 30), Vector2(0, 100)));

	Actor* bg = new Actor(this);
	new ScrollSpriteDrawerY(100.0f,"../Assets/bg_test.png", bg, 10);
	

}

void Game::UnloadData() {
	while (!mActors.empty()) {
		delete mActors.back();
	}

	for (auto t : mTextures) {
		SDL_DestroyTexture(t.second);
	}
	mTextures.clear();
}