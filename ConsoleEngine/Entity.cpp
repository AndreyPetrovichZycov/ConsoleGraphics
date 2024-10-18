#include "Entity.h"

Entity::Entity(Primitive* prmtv, std::vector<float> speed) {
	m_prmtv = prmtv;
	m_speedX = speed[0];
	m_speedY = speed[1];
	m_xPos = prmtv->getPosition()[0];
	m_yPos = prmtv->getPosition()[1];

}


const Primitive* Entity::getPrimitive() const
{
	return m_prmtv;
}


std::vector<float> Entity::getSpeed() {
	return { m_speedX, m_speedY};
}


void Entity::setSpeed(std::vector<float> speed) {
	m_speedX = speed[0];
	m_speedY = speed[1];
}


std::vector<float> Entity::getPosition() {
	return { m_xPos, m_yPos };
}


void Entity::setPosition(std::vector<float> Pos)
{
	m_prmtv->setPosition(Pos[0], Pos[1]);
}


void Entity::update(float t) 
{
	

	m_prmtv->setPosition(m_xPos, m_yPos);
}