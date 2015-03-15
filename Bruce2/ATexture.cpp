#include "ATexture.h"

extern SDL_Renderer *gRenderer;

ATexture::ATexture()
{
	mTexture = NULL;
	width = 0;
	height = 0;
}

ATexture::ATexture(std::string path, Color colorkey)
{
	mTexture = NULL;
	width = 0;
	height = 0;

	load(path, colorkey);
}

ATexture::~ATexture()
{
	free();
}

bool ATexture::load(std::string path, Color colorkey)
{
	free();

	//Final texture
	SDL_Texture* texture = NULL;
	//Load image
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		width = loadedSurface->w;
		height = loadedSurface->h;

		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, (Uint8)colorkey.r, (Uint8)colorkey.g, (Uint8)colorkey.b));

		texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

		SDL_FreeSurface(loadedSurface);

		mTexture = texture;
	}

	return mTexture != NULL;
}

void ATexture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		width = 0;
		height = 0;
	}
}

void ATexture::setColor(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetTextureColorMod(mTexture, r, g, b);
}

void ATexture::setBlendMode(SDL_BlendMode blendmode)
{
	SDL_SetTextureBlendMode(mTexture, blendmode);
}

void ATexture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(mTexture, alpha);
}
