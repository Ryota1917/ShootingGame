#include"Game.h"
#include"Actor.h"
#include"PlayerShip.h"
#include"RockActor.h"

void Game::LoadData() {
	new PlayerShip(this);

	auto r = new RockActor(this);
	r->SetPosition(Vector2(400, 150));

	r = new RockActor(this);
	r->SetPosition(Vector2(500, 100));

	r = new RockActor(this);
	r->SetPosition(Vector2(700, 250));

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