#include "TitleActor.h"
#include"InputState.h"
#include"GameSceneManeger.h"
#include"SpriteDrawer.h"

TitleActor::TitleActor(Game* game):
	Actor(game)
{
	SetPosition(Vector2(1024 / 2, 786 / 2));
	new SpriteDrawer("../Assets/title.png", this);
	auto sd = new SpriteDrawer("../Assets/click_space.png",this);
	sd->SetOffset(Vector2(0, 200));
}

void TitleActor::ActorInput(const InputState& state)
{
	if (state.Keyboard.GetKeyState(SDL_SCANCODE_SPACE) == ButtonState::EGetDown) {
		GetGame()->GetGameScene()->SetNextState();
	}
}
