#pragma once
#include"InputState.h"

class InputSystem {
public:
	bool Initialize();
	void Shutdown();

	// SDL_PollEvents�̒��O�ɌĂяo��
	void PrepareUpdate();
	// SDL_PollEvents�̒���ɌĂяo��
	void Update();

	const InputState& GetState()const { return mState; }

private:
	InputState mState;

};