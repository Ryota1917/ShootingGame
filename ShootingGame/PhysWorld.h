#pragma once
#include<functional>
#include<vector>

class PhysWorld {
public:
	PhysWorld(class Game* game);

	// ナイーブな実装でO(n^2)
	// TODO: スイープ＆プルーンの実装 
	void TestPairwise(std::function<void(class Actor*, class Actor*)> f);

	void AddCollision(class CollisionComponent* collision);
	void RemoveCollision(class CollisionComponent* collision);
private:
	class Game* mGame;
	std::vector<class CollisionComponent*> mCollisions;
};