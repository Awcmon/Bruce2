#pragma once

#include <vector>
#include <map>
#include "Entity.h"

class EntityFactory
{
public:

	EntityFactory()
	{
		//Register everything
		
	}

	~EntityFactory()
	{
		entRegister.clear();
		entities.clear();
		entsToRemove.clear();
	}

	void Register(const std::string _name, Entity _ent)
	{
		entRegister[_name] = _ent;
	}

	Entity* Create(const std::string _name)
	{
		Entity* ent;
		/*
		std::map<std::string, Entity>::iterator it = entRegister.find(_name);
		if (it != entRegister.end())
		{
			ent = new (Entity)entRegister[_name];
		}
		*/
		ent = &entRegister[_name];
	}

	void Remove(Entity* _ent)
	{
		bool dupe = false;
		for (int i = 0; i < (int)entsToRemove.size(); i++)
		{
			if (entsToRemove[i] == _ent)
			{
				printf("\nDuplicate found!\n");
				dupe = true;
			}
		}
		if (!dupe)
		{
			entsToRemove.push_back(_ent);
		}
	}

	std::vector<Entity*> GetAll()
	{
		return entities;
	}

private:
	std::map<std::string, Entity> entRegister;
	std::vector<Entity*> entities;
	std::vector<Entity*> entsToRemove;
};

