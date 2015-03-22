
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

#include "Globals.h"
#include "AwcUtility.h"
#include "AWindow.h"
#include "Configor.h"
#include "EntityFactory.h"
#include "CSprite.h"
#include "ATexture.h"

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

enum Gamestates
{
	STATE_NULL,
	STATE_EXIT,
	STATE_TITLE,
	STATE_MENU,
	STATE_GAME
};

enum RenderLayer
{
	LAYER_FG0,
	LAYER_FG1,
	LAYER_FG2,
	LAYER_FG3,
	LAYER_BG0,
	LAYER_BG1,
	LAYER_BG3
};

int nextGamestate = STATE_NULL;
int Gamestate = STATE_NULL;

int main(int argc, char* args[])
{
	CConfigor cfg;
	cfg.LoadFromFile("config.cfg");

	SCREEN_WIDTH = cfg["Window Information"]["Width"].GetValue<int>(0);
	SCREEN_HEIGHT = cfg["Window Information"]["Height"].GetValue<int>(0);

	AWindow window;
	SDL_Event e;

	Gamestate = STATE_MENU;
	EntityFactory ents;

	
	Entity* ent = new Entity();
	Component* spriteComponent = new CSprite();
	ent->addComponent(spriteComponent);
	ents.Add(ent);

	/* Texture Test
	ATexture* egg = new ATexture();
	egg->load("materials/egg.png");
	*/

	while (Gamestate != STATE_EXIT)
	{
		int start = SDL_GetTicks();

		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				Gamestate = STATE_EXIT;
			}
		}

		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		
		//Render all entity components
		for (int i = 0; i < ents.GetAll().size(); i++)
		{
			Entity* curEnt = ents.GetAll()[i];
			for (int k = 0; k < curEnt->components.size(); k++)
			{
				curEnt->components[k]->render();
			}
		}

		//Update screen
		SDL_RenderPresent(gRenderer);

		//Cap to 60 fps
		if (Gamestate != STATE_EXIT)
		{
//			int delay = Clamp(start + MS_PER_FRAME - SDL_GetTicks(), 0, MS_PER_FRAME);
			SDL_Delay(Clamp(start + MS_PER_FRAME - SDL_GetTicks(), 0, MS_PER_FRAME));
		}
	}

	window.free();
	return 0;
}
