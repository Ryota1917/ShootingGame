#pragma once
#include"Component.h"

/// <summary>
/// ���ŃT�C���J�[�u�œ������܂�
/// </summary>
class AutoMoveComponent :public Component {
public:
	AutoMoveComponent(class MoveActor* owner);

	void Update(float deltaTime)override;

	void SetMoveWidth(float width) { mMoveWidth = width; }
	float GetMoveWidth()const { return mMoveWidth; }

private:
	class MoveActor* mOwner;
	float mMoveWidth;
	float mTotalTime;
};