#pragma once
#include"Component.h"
#include"Collision2D.h"
#include<functional>
#include<vector>

class CollisionComponent : public Component {
public:
	CollisionComponent(class Actor* owner);
	virtual ~CollisionComponent();

	//TODO: Collisionの機構は要検討
	//std::functionは通常のポインタサイズよりも必要なメモリ量が多く、関数の呼び出しにも若干のオーバーヘッドが存在します[参照：https://qiita.com/hmito/items/44925fca9fca74e78f61]
	virtual const CollisionShape2D& GetCollision()const = 0;
	void OnCollision(class Actor* other);
	/// <summary>
	/// Componentで指定したい関数があるときはここで定義する
	/// </summary>
	virtual void OnComponentCollision(class Actor* other);
	/// <summary>
	/// 外側から関数を注入したいときはこの関数を使う
	/// </summary>
	void AddCollisionEvent(std::function<void(class Actor*)> f);

private:
	std::vector<std::function<void(class Actor*)>> mOnCollisions;
};