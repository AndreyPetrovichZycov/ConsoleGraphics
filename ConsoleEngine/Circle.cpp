#include "Circle.h"



Circle::Circle(float x_start, float y_start, float radius, wchar_t pixel) :
	Primitive(x_start, y_start, pixel)
{

	m_radius = radius;
	x_pos = x_start;
	y_pos = y_start;

	
}


void Circle::setPosition(float x, float y) {
	x_pos = x;
	y_pos = y;
}


float* Circle::getPosition() const{
	float position[] = { x_pos, y_pos };
	return position;
}


float Circle::getRadius() {
	return m_radius;
}


wchar_t Circle::getPixel() const
{
	return m_pixel;
}


bool Circle::getShape(float x, float y) {

	return x * x + y * y * 0.36 < m_radius * m_radius;
}
