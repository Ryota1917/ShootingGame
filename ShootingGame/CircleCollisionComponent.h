#pragma once
#include"CollisionComponent.h"
#include"Collision2D.h"

class CircleCollisionComponent :public CollisionComponent {
public:
	CircleCollisionComponent(class Actor* owner,float r);
	const CollisionShape2D& GetCollision()const override;
	void OnUpdateWorldTransform()override;

private:
	Circle2D mCircle;
};