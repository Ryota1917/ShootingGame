#include"AutoMoveComponent.h"
#include"MoveActor.h"
#include"Math.h"

AutoMoveComponent::AutoMoveComponent(MoveActor* owner):
	Component(owner),mOwner(owner),mTotalTime(0),mMoveWidth(300)
{

}

void AutoMoveComponent::Update(float deltaTime)
{
	mTotalTime += deltaTime;

	mOwner->SetVelo(Vector2(Math::Cos(mTotalTime)*mMoveWidth, 0));
}
