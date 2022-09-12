#include "CircleCollisionComponent.h"
#include"Actor.h"

CircleCollisionComponent::CircleCollisionComponent(Actor* owner, float r):
	CollisionComponent(owner),mCircle(owner->GetPosition(),r)
{
}

const CollisionShape2D& CircleCollisionComponent::GetCollision() const
{
	return mCircle;
}

void CircleCollisionComponent::OnUpdateWorldTransform()
{
	auto pos = mOwner->GetPosition();
	mCircle.mCenter.x = pos.x;
	mCircle.mCenter.y = pos.y;
}
