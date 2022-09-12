#pragma once
#include"SDL_scancode.h"
#include"ButtonState.h"

class KeyboardState {
public: 
	friend class InputSystem;
	bool Initialze();
	void PrepareUpdate();
	bool GetKeyValue(SDL_Scancode keyCode) const;
	ButtonState GetKeyState(SDL_Scancode keyCode) const;

private:
	const Uint8* mCurrState;
	Uint8 mPreState[SDL_NUM_SCANCODES];
};