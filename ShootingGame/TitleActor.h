#pragma once
#include"Actor.h"

class TitleActor :public Actor {
public: 
	TitleActor(class Game* game);

	void ActorInput(const struct InputState& state)override;
};