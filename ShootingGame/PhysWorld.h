#pragma once
#include<functional>
#include<vector>

class PhysWorld {
public:
	PhysWorld(class Game* game);

	// �i�C�[�u�Ȏ�����O(n^2)
	// TODO: �X�C�[�v���v���[���̎��� 
	void TestPairwise(std::function<void(class Actor*, class Actor*)> f);

	void AddCollision(class CollisionComponent* collision);
	void RemoveCollision(class CollisionComponent* collision);
private:
	class Game* mGame;
	std::vector<class CollisionComponent*> mCollisions;
};