#include "TitleScene.h"
#include"GameSceneManeger.h"
#include"Game.h"
#include"TitleActor.h"

TitleScene::TitleScene(GameSceneManeger* maneger):
	GameScene(maneger)
{

}

void TitleScene::OnEnter()
{
	Game* game = mManeger->GetGame();
	new TitleActor(game);
}

void TitleScene::OnExit()
{
	mManeger->GetGame()->RemoveAllActor();
}
