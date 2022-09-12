#include "MoveActor.h"
#include"MoveComponent.h"

MoveActor::MoveActor(Game* game):
	Actor(game),mVelocity(Vector2::Zero),mAnglerVelo(0),mMaxVelocity(Vector2(100,100)),mMaxAngulerVelo(7)
{
	new MoveComponent(this);

}
