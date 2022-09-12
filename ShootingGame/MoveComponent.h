#pragma once
#include"Component.h"

class MoveComponent :public Component {
public:
	MoveComponent(class MoveActor* owner);

	void Update(float deltaTime)override;

private:
	class MoveActor* mMoveOwner;
};