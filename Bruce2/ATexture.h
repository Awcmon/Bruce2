#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "AwcColor.h"

class ATexture
{
	public:
	ATexture();
	ATexture(std::string path, Color colorkey = Color(255, 0, 255));
	~ATexture();

	bool load(std::string path, Color colorkey = Color(255, 0, 255));
	void free();

	void setColor(Uint8 r, Uint8 g, Uint8 b);
	void setBlendMode(SDL_BlendMode blendmode);
	void setAlpha(Uint8 alpha);

	int width;
	int height;

	private:
	SDL_Texture *mTexture;
};