#include "CSprite.h"


CSprite::CSprite()
{
	texture->load("materials/egg.png");
}

CSprite::~CSprite()
{
}

void CSprite::render()
{
	if (texture != NULL)
	{
		texture->render(0, 0);
	}
}