#include "Engine.h"


Engine::Engine(Window *window) 
{
	m_window = window;
}


void Engine::run(float t) 
{

}

void Engine::createEntity(Primitive& prmtv, std::vector<float> speed)
{
	Entity *entity = new Entity(&prmtv, speed);

	entityList.push_back(entity);

}


const std::list<Entity*> Engine::getEntityList()
{
	return entityList;
}


Engine::~Engine() {
	auto it = entityList.begin();
	for (; it != entityList.end(); it++) {
		delete *it;
	}
}