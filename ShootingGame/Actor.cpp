#include"Actor.h"
#include"Game.h"
#include"Component.h"
#include"Drawer.h"

Actor::Actor(Game* game) :mGame(game), mState(Actor::EActive),mPosition(Vector2::Zero),mScale(Vector2::Unit),mRotate(0.0f) {
	mGame->AddActor(this);
}

Actor::~Actor() {
	mGame->RemoveActor(this);
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
	while (!mDrawers.empty()) {
		delete mDrawers.back();
	}
}

void Actor::Update(float deltaTime) {
	if (mState == Actor::EActive) {
		ComputeWorldTransform();
		UpdateActor(deltaTime);
		UpdateComponents(deltaTime);
	}
}

void Actor::UpdateComponents(float deltaTime) {
	for (auto component : mComponents) {
		component->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime) {

}

void Actor::LastUpdate(float deltaTime) {
	if (mState == Actor::EActive) {
		LastUpdateActor(deltaTime);
		ComputeWorldTransform();
	}
}

void Actor::LastUpdateActor(float deltaTime) {

}

void Actor::ProcessInput(const struct InputState& state) {
	if (mState == EActive) {
		ActorInput(state);
		for (auto c : mComponents) {
			c->ProcessInput(state);
		}
	}
}

void Actor::ActorInput(const InputState& state)
{
}

void Actor::Draw(SDL_Renderer* renderer) {
	for (auto drawer : mDrawers) {
		drawer->Draw(renderer);
	}
}

void Actor::AddComponent(Component* component) {
	mComponents.emplace_back(component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		std::iter_swap(iter, mComponents.end() - 1);
		mComponents.pop_back();
	}
}

void Actor::AddDrawer(Drawer* drawer) {
	mDrawers.emplace_back(drawer);
}

void Actor::RemoveDrawer(Drawer* drawer) {
	auto iter = std::find(mDrawers.begin(), mDrawers.end(), drawer);
	if (iter != mDrawers.end()) {
		std::iter_swap(iter, mDrawers.end() - 1);
		mDrawers.pop_back();
	}
}

void Actor::ComputeWorldTransform()
{

	// mIsTransformUpdate‚ÌŽÀ‘•‚ðŒŸ“¢
	for (auto comp : mComponents)
	{
		comp->OnUpdateWorldTransform();
	}
}
