#include "GameSceneManeger.h"
#include"GameScene.h"
#include"SDL.h"
#include"TitleScene.h"
#include"PlayScene.h"
#include"EndScene.h"

GameSceneManeger::GameSceneManeger(Game* game):
	mCurrentScene(nullptr),mGame(game)
{
	ResisterScene(new TitleScene(this));
	ResisterScene(new PlayScene(this));
	ResisterScene(new EndScene(this));
}

GameSceneManeger::~GameSceneManeger()
{
	for (auto state : mGameScenes) {
		delete state.second;
	}
	mGameScenes.clear();
}

void GameSceneManeger::ResisterScene(GameScene* scene)
{
	if (mGameScenes.find(scene->GetName()) != mGameScenes.end()) {
		SDL_Log("�V�[��%s�͊��ɓo�^����Ă��܂�", scene->GetName());
		return;
	}
	mGameScenes[scene->GetName()] = scene;
}

void GameSceneManeger::SetCurrentState(const std::string& sceneName)
{
	if (mGameScenes.find(sceneName) == mGameScenes.end()) {
		SDL_Log("�V�[��%s���o�^����Ă��Ȃ��̂Ő���ɏ������s���܂���ł����D", sceneName);
		return;
	}


	if (mCurrentScene != nullptr) {
		mCurrentScene->OnExit();
	}

	mCurrentScene = mGameScenes[sceneName];
	mCurrentScene->OnEnter();
}

void GameSceneManeger::SetNextState()
{
	SetCurrentState(mCurrentScene->GetNextState());
}
