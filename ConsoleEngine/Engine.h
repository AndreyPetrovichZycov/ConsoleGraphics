#pragma once
#include "Entity.h"
#include "Window.h"
#include <iterator>
#include <list>


class Engine
{
	Window* m_window;
	std::list<Entity*> entityList;

public:
	Engine(Window *window);

	void run(float t);

	void createEntity(Primitive& prmtv, std::vector<float> speed);

	const std::list<Entity*> getEntityList();

	~Engine();
};


