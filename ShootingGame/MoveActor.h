#pragma once
#include"Actor.h"

/// <summary>
/// 動かしたいActor用のクラス
/// このActorは自動的にMoveComponentを所持します
/// </summary>
class MoveActor :public Actor {
public:
	MoveActor(class Game* game);
	virtual ~MoveActor() {};

	const Vector2& GetVelo()const { return mVelocity; }
	void SetVelo(const Vector2& velo) { mVelocity = velo; }
	float GetAngleVelo()const { return mAnglerVelo; }
	void SetAngleVelo(float angleVelo) { mAnglerVelo = angleVelo; }

	const Vector2& GetMaxVelocity()const { return mMaxVelocity; }
	void SetMaxVelo(const Vector2& maxVelo) { mMaxVelocity = maxVelo; }
	float GetMaxAngulerVelo()const { return mMaxAngulerVelo; }
	void SetMaxAngulerVelo(float maxAnglerVelo) { mMaxAngulerVelo = maxAnglerVelo; }

private:
	Vector2 mVelocity;
	Vector2 mMaxVelocity;
	float mAnglerVelo;
	float mMaxAngulerVelo;
};