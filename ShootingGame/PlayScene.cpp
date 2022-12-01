#include "PlayScene.h"
#include"GameSceneManeger.h"
#include"Game.h"
#include"PlayerShip.h"
#include"EnemyShipActor.h"
#include"ScrollSpriteDrawerY.h"
#include"EnemyManegerActor.h"
#include"SpriteDrawer.h"

PlayScene::PlayScene(GameSceneManeger* maneger):
	GameScene(maneger)
{
}

void PlayScene::OnEnter()
{
	Game* game = mManeger->GetGame();

	auto ps = new PlayerShip(game);
	ps->SetHP(3);

	Actor* bg = new Actor(game);
	new ScrollSpriteDrawerY(100.0f, "../Assets/star_map.png", bg, 10);

	mEnemyManeger = new EnemyManegerActor(game);
	for (int i = 0; i < 3; i++) {
		mEnemyManeger->Generate();
	}
}

void PlayScene::OnExit()
{
	//SDL_Log("Your delete enemy count: %d !!!", mEnemyManeger->GetDeleteEnemyNum());
	auto scoreActor = new Actor(mManeger->GetGame());
	auto sd = new SpriteDrawer("../Assets/your_score.png", scoreActor, 500);
	sd->SetOffset(Vector2(300, 100));

	int score = mEnemyManeger->GetDeleteEnemyNum();

	sd = new SpriteDrawer("../Assets/"+std::to_string(score/10)+".png", scoreActor, 500);
	sd->SetOffset(Vector2(650, 100));

	sd = new SpriteDrawer("../Assets/"+std::to_string(score%10)+".png", scoreActor, 500);
	sd->SetOffset(Vector2(730, 100));
}
