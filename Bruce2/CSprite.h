#pragma once

#include "Component.h"
#include "ATexture.h"

extern SDL_Renderer* gRenderer;

class CSprite : public Component
{
public:
	CSprite();
	~CSprite();

	void render();

	ATexture* texture;
};

