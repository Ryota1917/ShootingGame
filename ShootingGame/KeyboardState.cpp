#include "KeyboardState.h"
#include "SDL.h"
#include<cstring>

bool KeyboardState::Initialze()
{
    mCurrState = SDL_GetKeyboardState(NULL);
    // ‘O‚Ìó‘Ô‚Ìƒƒ‚ƒŠ‚ğƒNƒŠƒA‚·‚é
    memset(mPreState, 0, SDL_NUM_SCANCODES);

    return true;
}

void KeyboardState::PrepareUpdate()
{
	memcpy(mPreState, mCurrState, SDL_NUM_SCANCODES);
}

bool KeyboardState::GetKeyValue(SDL_Scancode keyCode) const
{
    return mCurrState[keyCode] == 1;
}

ButtonState KeyboardState::GetKeyState(SDL_Scancode keyCode) const
{
	if (mPreState[keyCode] == 0)
	{
		if (mCurrState[keyCode] == 0)
		{
			return ENone;
		}
		else
		{
			return EGetDown;
		}
	}
	else // Prev state must be 1
	{
		if (mCurrState[keyCode] == 0)
		{
			return EGetUp;
		}
		else
		{
			return EHeld;
		}
	}
}
