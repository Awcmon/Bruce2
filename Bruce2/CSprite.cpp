#include "CSprite.h"


CSprite::CSprite()
{
	texture = new ATexture();
	texture->load("materials/egg.png");
}

CSprite::~CSprite()
{
	texture->free();
}

void CSprite::render()
{
	texture->render(0, 0);
}