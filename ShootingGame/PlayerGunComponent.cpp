#include "PlayerGunComponent.h"
#include"InputState.h"
#include"BulletActor.h"
#include"ShipActor.h"

PlayerGunComponent::PlayerGunComponent(ShipActor* owner, GunBangInterFace bang, GunGenerateInterface generate):
	GunComponent(owner,bang,generate)
{
}

void PlayerGunComponent::ProcessInput(const InputState& state)
{
	if (state.Keyboard.GetKeyState(SDL_SCANCODE_SPACE) == ButtonState::EGetDown) {
		auto b = new BulletActor(mOwner->GetGame(),BulletActor::BulletType::EPlayer);
		b->SetPosition(mOwner->GetPosition() + Vector2(0, -20));
		b->SetMaxVelo(Vector2(0, 500));
		b->SetVelo(Vector2(0, -300));
	}
}
