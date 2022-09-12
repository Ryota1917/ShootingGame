#include "PhysWorld.h"
#include"Collision2D.h"
#include"CollisionComponent.h"

PhysWorld::PhysWorld(Game* game):mGame(game)
{
}

void PhysWorld::TestPairwise(std::function<void(class Actor*, class Actor*)> f)
{
	for (int i = 0; i < mCollisions.size(); i++) {
		for (int j = i + 1; j < mCollisions.size(); j++) {
			CollisionComponent* a = mCollisions[i];
			CollisionComponent* b = mCollisions[j];

			if (IntersectMediator(a->GetCollision(), b->GetCollision())) {
				if(f)
					f(a->GetOwner(), b->GetOwner());
				a->OnCollision(b->GetOwner());
				b->OnCollision(a->GetOwner());
			}

		}
	}
}

void PhysWorld::AddCollision(CollisionComponent* collision)
{
	mCollisions.emplace_back(collision);
}

void PhysWorld::RemoveCollision(CollisionComponent* collision)
{
	auto iter = std::find(mCollisions.begin(), mCollisions.end(), collision);
	if (iter != mCollisions.end())
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, mCollisions.end() - 1);
		mCollisions.pop_back();
	}
}

