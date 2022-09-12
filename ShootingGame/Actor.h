#pragma once
#include<vector>
#include"Math.h"
#include"Game.h"

class Actor {
public:
	enum State {
		EActive,
		EPaused,
		EDead,
	};

	Actor(class Game* game);
	virtual ~Actor();

	// Update Actor
	void Update(float deltaTime);
	// Update all Components
	void UpdateComponents(float deltaTime);
	// Actor 特有の更新
	virtual void UpdateActor(float deltaTime);
	// Update->LastUpdateの順番で呼び出される
	void LastUpdate(float deltaTime);
	virtual void LastUpdateActor(float deltaTime);

	// 入力用関数
	void ProcessInput(const struct InputState& state);
	virtual void ActorInput(const struct InputState& state);

	//描画用の処理を呼び出す
	void Draw(SDL_Renderer* renderer);

	//Componentに関する処理
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	//Drawerに関する処理
	void AddDrawer(class Drawer* drawer);
	void RemoveDrawer(class Drawer* drawer);

	Game* GetGame() { return mGame; }
	State GetState() { return mState; }
	void SetState(State state) { mState = state; }

	void ComputeWorldTransform();

	const Vector2& GetPosition()const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	const Vector2& GetScale()const { return mScale; }
	void SetScale(const Vector2& scale) { mScale = scale; }
	float GetRotate()const { return mRotate; }
	void SetRotate(float rot) { mRotate = rot; }

	Vector2 GetForward() { return Vector2(Math::Cos(mRotate), -Math::Sin(mRotate)); }

private:
	State mState;

	//Transform 情報
	Vector2 mPosition;
	Vector2 mScale;
	float mRotate;

	std::vector<class Component*> mComponents;
	std::vector<class Drawer*> mDrawers;
	Game* mGame;
};