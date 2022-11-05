#include "EndScene.h"
#include"GameSceneManeger.h"
#include"Game.h"
#include"EndActor.h"

EndScene::EndScene(GameSceneManeger* maneger):
	GameScene(maneger)
{

}

void EndScene::OnEnter()
{
	Game* game = mManeger->GetGame();
	new EndActor(game);
}

void EndScene::OnExit()
{
	mManeger->GetGame()->RemoveAllActor();
}
