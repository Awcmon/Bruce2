#include "ASurface.h"


ASurface::ASurface()
{
}

ASurface::~ASurface()
{
	texture = NULL;
}

//Geometric Primitives
void ASurface::DrawPoint(Vector2D pos)
{
	SDL_RenderDrawPoint(gRenderer, (int)pos.x, (int)pos.y);
}

void ASurface::DrawLine(Vector2D p1, Vector2D p2)
{
	SDL_RenderDrawLine(gRenderer, (int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);
}

void ASurface::DrawRect(Vector2D pos, int w, int h)
{
	SDL_Rect rect{ (int)pos.x, (int)pos.y, w, h };
	SDL_RenderDrawRect(gRenderer, &rect);
}

void ASurface::DrawFillRect(Vector2D pos, int w, int h)
{
	SDL_Rect rect{ (int)pos.x, (int)pos.y, w, h };
	SDL_RenderFillRect(gRenderer, &rect);
}

void ASurface::DrawQuad(Vector2D p1, Vector2D p2)
{
	Vector2D pos;
	
	float w = abs(p1.x - p2.x);
	float h = abs(p1.y - p2.y);

	if (p1.x <= p2.x)
	{
		pos.x = p1.x;
	}
	else
	{
		pos.x = p2.x;
	}

	if (p1.y <= p2.y)
	{
		pos.y = p1.y;
	}
	else
	{
		pos.y = p2.y;
	}

	SDL_Rect rect{ (int)pos.x, (int)pos.y, (int)w, (int)h };
	SDL_RenderDrawRect(gRenderer, &rect);
}

void ASurface::DrawFillQuad(Vector2D p1, Vector2D p2)
{
	Vector2D pos;

	float w = abs(p1.x - p2.x);
	float h = abs(p1.y - p2.y);

	if (p1.x <= p2.x)
	{
		pos.x = p1.x;
	}
	else
	{
		pos.x = p2.x;
	}

	if (p1.y <= p2.y)
	{
		pos.y = p1.y;
	}
	else
	{
		pos.y = p2.y;
	}

	SDL_Rect rect{ (int)pos.x, (int)pos.y, (int)w, (int)h };
	SDL_RenderFillRect(gRenderer, &rect);
}

//Texture stuff
void ASurface::DrawTexturedRect(Vector2D pos, int _w, int _h, double angle)
{
	int w = _w;
	int h = _h;

	if ((w == NULL) || (h == NULL))
	{
		w = texture->getWidth();
		h = texture->getHeight();
	}

	SDL_Rect renderQuad = { pos.x, pos.y, w, h };

	//Render to screen
	SDL_RenderCopyEx(gRenderer, texture->getTexture(), NULL, &renderQuad, angle, NULL, SDL_FLIP_NONE);
}

void ASurface::DrawTexturedQuad(Vector2D p1, Vector2D p2)
{

}

//Setting stuff
void ASurface::SetTexture(ATexture* _texture)
{
	/*
	texture->free();
	texture = new ATexture;
	texture->load(path);
	*/
	texture = _texture;
}
