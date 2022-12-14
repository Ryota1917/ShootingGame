#pragma once
#include"InputState.h"

class InputSystem {
public:
	bool Initialize();
	void Shutdown();

	// SDL_PollEventsの直前に呼び出す
	void PrepareUpdate();
	// SDL_PollEventsの直後に呼び出す
	void Update();

	const InputState& GetState()const { return mState; }

private:
	InputState mState;

};