#include"Game.h"
#include"Actor.h"
#include"GameSceneManeger.h"

void Game::LoadData() {
	mScene->SetCurrentState("Title");
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