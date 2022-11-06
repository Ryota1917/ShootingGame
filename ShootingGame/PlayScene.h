#pragma once
#include"GameScene.h"

class PlayScene :public GameScene {
public:
	PlayScene(class GameSceneManeger* maneger);
	void OnEnter()override;
	void OnExit()override;

	const char* GetName()const override { return "Play"; }
	const char* GetNextState()const override { return "End"; }
private:
	class EnemyManegerActor* mEnemyManeger;
};