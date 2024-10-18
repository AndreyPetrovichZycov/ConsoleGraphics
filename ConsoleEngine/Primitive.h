#pragma once
#include <iostream>
#include <vector>

class Primitive
{
protected:
	float x_pos; //координаты центра
	float y_pos;
	wchar_t m_pixel;

public:
	Primitive(float x, float y, wchar_t pixel) : x_pos(x), y_pos(y), m_pixel(pixel)
	{

	}

	virtual float* getPosition() const = 0;

	virtual void setPosition(float x, float y) = 0;

	virtual bool getShape(float x, float y) = 0;
	
	virtual wchar_t getPixel() const = 0;
};
