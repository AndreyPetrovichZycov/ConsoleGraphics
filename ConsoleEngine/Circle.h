#pragma once
#include <windows.h>
#include "Primitive.h"
#include <iostream>


class Circle :public Primitive
{
	float m_radius;


public:
	Circle(float x_start, float y_start, float radius, wchar_t pixel);
		

	void setPosition(float x, float y) override;

	float* getPosition() const override;

	float getRadius();

	bool getShape(float x, float y) override;

	wchar_t getPixel() const override;
};

