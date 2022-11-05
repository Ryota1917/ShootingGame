#pragma once
#include"Actor.h"

class EndActor :public Actor {
public:
	EndActor(class Game* game);

	void ActorInput(const struct InputState& state)override;
};