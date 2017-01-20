#pragma once

#include "Component.h"
#include "ATexture.h"

extern SDL_Renderer* gRenderer;

class CSprite : public Component
{
public:
	CSprite();
	CSprite(std::string _path, int _renderLayer);
	~CSprite();

	void render();
	void load(std::string _path, int _renderLayer);

	std::string path;
	int renderLayer;
	ATexture* texture;
};

