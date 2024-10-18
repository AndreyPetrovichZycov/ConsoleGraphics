#pragma once
#include "Entity.h"
#include "Window.h"

class PhysEngine
{
	int m_ScreenWidth;
	int m_ScreenHeight;
	float m_gravity;
	bool isFly = 0;
	bool isFall = 1;

public:
	PhysEngine(float gravity, Window& w);

	static bool collision(Entity &entity);

	void gravityCollision(Entity* entity);

};

