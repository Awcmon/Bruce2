#pragma once

#include <vector>
#include <string>
#include "Component.h"
#include "AwcVector2D.h"

class Entity
{
public:
	Entity() { printf("Spawned: %s\n", className.c_str()); }
	~Entity() {}

	void addComponent(Component* _component)
	{
		components.push_back(_component);
	}

	Vector2D pos;
	Vector2D vel;

	std::string className = "Entity";

	std::vector<Component*> components;
};

