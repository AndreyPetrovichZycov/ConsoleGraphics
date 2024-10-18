#include "PhysicsEngine.h"

PhysEngine::PhysEngine(float gravity, Window& w) {
	m_ScreenWidth = w.getWindowSize()[0];
	m_ScreenHeight = w.getWindowSize()[1];

	m_gravity = gravity;
}

bool PhysEngine::collision(Entity &entity)
{
	
	float x = entity.getPosition()[0];
	float y = entity.getPosition()[1];

	if (x + 0.05 > 1 || x - 0.05 < 0) {
		entity.setSpeed({ -entity.getSpeed()[0], entity.getSpeed()[1] });
		return 1;
	}
	
	if (y + 0.05 > 1 || y - 0.05 < 0) {
		entity.setSpeed({ entity.getSpeed()[0], -entity.getSpeed()[1] });
		return 1;
	}

	else return 0;
}


void PhysEngine::gravityCollision(Entity *entity) 
{
	float y = entity->getPrimitive()->getPosition()[1];
	float x = entity->getPrimitive()->getPosition()[0];

	float Vx = entity->getSpeed()[0];

	if (y + 0.05 < 1) {
		x += 0.001*Vx;
		y += 0.001 * m_gravity;
		m_gravity += 0.001;
	}

	else {
		x += 0.001*Vx;
		m_gravity *= -0.5;
		y += m_gravity * 0.05;
	}
	
	entity->setPosition({ x, y });

}