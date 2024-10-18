#pragma once
#include "Primitive.h"

class Entity
{
	Primitive* m_prmtv;
	float m_speedX;
	float m_speedY;

	float m_xPos;
	float m_yPos;


public:
	Entity(Primitive* prmtv, std::vector<float> speed = { 0, 0});
	
	const Primitive* getPrimitive() const;

	std::vector<float> getSpeed();

	void setSpeed(std::vector<float> speed);

	std::vector<float> getPosition();

	void setPosition(std::vector<float> Coord);

	void update(float t);
};