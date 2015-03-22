#pragma once

#include "AwcVector2D.h"
#include "SDL.h"
#include <stdio.h>

class Component
{
public:

	Component() 
	{
		printf("rip");
	}

	virtual ~Component() 
	{
		Remove();
	}

	virtual void Remove()
	{
		printf("rip");
	}

	virtual void handleEvents(SDL_Event _e) 
	{
		printf("rip");
	}

	virtual void think() 
	{
		printf("rip");
	}

	virtual void render() 
	{
		printf("rip");
	}

	Vector2D offset;
	float ang;
};

