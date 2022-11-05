#include "PlayScene.h"
#include"GameSceneManeger.h"
#include"Game.h"
#include"PlayerShip.h"
#include"RockActor.h"
#include"GunComponent.h"
#include"GunTimeBang.h"
#include"GunSingleGenerate.h"
#include"AutoMoveComponent.h"
#include"ScrollSpriteDrawerY.h"

PlayScene::PlayScene(GameSceneManeger* maneger):
	GameScene(maneger)
{
}

void PlayScene::OnEnter()
{
	Game* game = mManeger->GetGame();

	new PlayerShip(game);

	auto r = new RockActor(game);
	r->SetPosition(Vector2(400, 150));
	new GunComponent(r, new GunTimeBang(1.0f), new GunSingleGenerate(Vector2(0, 30), Vector2(0, 100)));


	r = new RockActor(game);
	r->SetPosition(Vector2(500, 100));
	new GunComponent(r, new GunTimeBang(0.5f), new GunSingleGenerate(Vector2(0, 30), Vector2(0, 100)));
	new AutoMoveComponent(r);


	r = new RockActor(game);
	r->SetPosition(Vector2(700, 250));
	new GunComponent(r, new GunTimeBang(1.0f), new GunSingleGenerate(Vector2(0, 30), Vector2(0, 100)));

	Actor* bg = new Actor(game);
	new ScrollSpriteDrawerY(100.0f, "../Assets/star_map.png", bg, 10);
}

void PlayScene::OnExit()
{
}
