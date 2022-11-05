#include "RockActor.h"
#include"SpriteDrawer.h"
#include"CircleCollisionComponent.h"
#include"HPBarDrawer.h"

RockActor::RockActor(Game* game):
	ShipActor(game)
{
	SetHP(3);
	new SpriteDrawer("../Assets/rock_24.png", this, 200);
	new CircleCollisionComponent(this, 24);
	new HPBarDrawer(this, 200);
}
