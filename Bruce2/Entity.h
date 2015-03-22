#pragma once

#include <vector>
#include "Component.h"
#include "AwcVector2D.h"

class Entity
{
public:
	Entity() {}
	~Entity() {}

	Vector2D pos;
	Vector2D vel;

private:
	std::vector<Component*> components;
};

