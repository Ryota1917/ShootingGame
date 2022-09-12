#pragma once
#include"Component.h"

class KeyMoveComponent :public Component {
public:
	KeyMoveComponent(class MoveActor* owner);
	void ProcessInput(const struct InputState& state)override;

	void SetSpeed(const Vector2& speed) { mSpeed = speed; }

private:
	class MoveActor* mMoveActor;
	Vector2 mSpeed;
	Vector2 mMaxSpeed;
};