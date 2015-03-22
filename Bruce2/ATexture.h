#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include "AwcColor.h"

class ATexture
{
	public:
	ATexture();
	ATexture(std::string path, Color colorkey = Color(255, 0, 255));
	~ATexture();

	bool load(std::string path, Color colorkey = Color(255, 0, 255));
	void free();
	SDL_Texture* getTexture();

	void setColor(Uint8 r, Uint8 g, Uint8 b);
	void setBlendMode(SDL_BlendMode blendmode);
	void setAlpha(Uint8 alpha);

	void render(int x, int y, double angle = 0.0, SDL_Point* center = NULL, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	int width;
	int height;

	private:
	SDL_Texture *mTexture;
};
