#include "CollisionComponent.h"
#include"Actor.h"
#include"PhysWorld.h"

CollisionComponent::CollisionComponent(Actor* owner):
	Component(owner)
{
	mOwner->GetGame()->GetPhysWorld()->AddCollision(this);
}

CollisionComponent::~CollisionComponent()
{
	mOwner->GetGame()->GetPhysWorld()->RemoveCollision(this);
}

const CollisionShape2D& CollisionComponent::GetCollision() const 
{
	return CollisionShape2D();
}

void CollisionComponent::OnCollision(Actor* other)
{
	OnComponentCollision(other);
	for (auto f : mOnCollisions) {
		f(other);
	}
}

void CollisionComponent::OnComponentCollision(Actor* other)
{
}

void CollisionComponent::AddCollisionEvent(std::function<void(class Actor*)> f)
{
	mOnCollisions.emplace_back(f);
}
