
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

#include "Globals.h"
#include "AwcUtility.h"
#include "AWindow.h"

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

int main(int argc, char* args[])
{
	AWindow window;

	SDL_Event e;

	bool quit = false;

	while (!quit)
	{
		int start = SDL_GetTicks();

		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Render red filled quad
		SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(gRenderer, &fillRect);

		//Render green outlined quad
		SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderDrawRect(gRenderer, &outlineRect);

		//Draw blue horizontal line
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

		//Draw vertical line of yellow dots
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
		for (int i = 0; i < SCREEN_HEIGHT; i += 4)
		{
			SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
		}

		//Update screen
		SDL_RenderPresent(gRenderer);

		//Cap to 60 fps
		if (!quit)
		{
//			int delay = Clamp(start + MS_PER_FRAME - SDL_GetTicks(), 0, MS_PER_FRAME);
			SDL_Delay(Clamp(start + MS_PER_FRAME - SDL_GetTicks(), 0, MS_PER_FRAME));
		}
	}

	window.free();
	return 0;
}
