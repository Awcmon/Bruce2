#pragma once

#include "SDL.h"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	void handle_events(SDL_Event ev);
};
