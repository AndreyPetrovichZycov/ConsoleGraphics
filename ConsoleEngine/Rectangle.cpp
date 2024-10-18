#include "Rectangle.h"


Rect::Rect(float startX, float startY, float width, float height, wchar_t pixel) :Primitive(startX, startY, pixel)
{
	m_width = width;
	m_height = height;
}


float* Rect::getPosition() const
{
	float Position[] = { x_pos, y_pos };
	return Position;
}


bool Rect::getShape(float x, float y) {
	y = 0.5 * y;
	if (x < x_pos + m_width && x > x_pos - m_width && y < y_pos + m_height && y > y_pos - m_height) return 1;
	else return 0;

}


wchar_t Rect::getPixel() const
{
	return m_pixel;
}



void Rect::setPosition(float x, float y)
{
	x_pos = x;
	y_pos = y;
}