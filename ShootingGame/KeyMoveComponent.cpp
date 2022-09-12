#include "KeyMoveComponent.h"
#include"MoveActor.h"
#include"InputState.h"

KeyMoveComponent::KeyMoveComponent(MoveActor* owner):
	Component(owner),mMoveActor(owner),mSpeed(Vector2::Zero),mMaxSpeed(Vector2(200,200))
{
}

void KeyMoveComponent::ProcessInput(const InputState& state)
{
	bool isChange = false;
	Vector2 nVelo = mMoveActor->GetVelo();

	if (state.Keyboard.GetKeyValue(SDL_SCANCODE_W)) {
		nVelo.y += -mSpeed.y;
		isChange = true;
	}
	if(state.Keyboard.GetKeyValue(SDL_SCANCODE_S)){
		nVelo.y += mSpeed.y;
		isChange = true;
	}
	if(state.Keyboard.GetKeyValue(SDL_SCANCODE_D)){
		nVelo.x += mSpeed.x;
		isChange = true;
	}
	if(state.Keyboard.GetKeyValue(SDL_SCANCODE_A)){
		nVelo.x += -mSpeed.x;
		isChange = true;
	}

	if (!isChange) {
		nVelo *= 0.9f;
	}

	if (Math::Abs(nVelo.x) > mMaxSpeed.x) {
		nVelo.x = nVelo.x > 0 ? mMaxSpeed.x : -mMaxSpeed.x;
	}
	if (Math::Abs(nVelo.y) > mMaxSpeed.y) {
		nVelo.y = nVelo.y > 0 ? mMaxSpeed.y : -mMaxSpeed.y;
	}

	mMoveActor->SetVelo(nVelo);
}
