#pragma once
#include<unordered_map>
#include<string>

class GameSceneManeger {
public:
	GameSceneManeger(class Game* game);
	~GameSceneManeger();
	void ResisterScene(class GameScene* scene);

	void SetCurrentState(const std::string& sceneName);
	void SetNextState();

	Game* GetGame()const { return mGame; }

private:
	class Game* mGame;
	std::unordered_map<std::string, class GameScene*> mGameScenes;
	class GameScene* mCurrentScene;
};