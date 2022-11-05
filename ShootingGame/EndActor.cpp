#include "EndActor.h"
#include"InputState.h"
#include"GameSceneManeger.h"
#include"SpriteDrawer.h"

EndActor::EndActor(Game* game):
	Actor(game)
{
	SetPosition(Vector2(1024 / 2, 786 / 2));
	new SpriteDrawer("../Assets/game_over.png", this, 500);
}

void EndActor::ActorInput(const InputState& state)
{
	if (state.Keyboard.GetKeyState(SDL_SCANCODE_SPACE) == ButtonState::EGetDown) {
		GetGame()->GetGameScene()->SetNextState();
	}
}
