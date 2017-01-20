#include "CSprite.h"


CSprite::CSprite()
{
	texture = new ATexture();
//	texture->load("materials/egg.png");
}

CSprite::CSprite(std::string _path, int _renderLayer)
{
	texture = new ATexture();
	path = _path;
	renderLayer = _renderLayer;
	texture->load(path);
}

CSprite::~CSprite()
{
	texture->free();
}

void CSprite::load(std::string _path, int _renderLayer)
{
	path = _path;
	renderLayer = _renderLayer;
	texture->load(path);
}

void CSprite::render()
{
	texture->render(0, 0);
}