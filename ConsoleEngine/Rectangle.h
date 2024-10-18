#pragma once
#include "Primitive.h"

class Rect: public Primitive 
{
	float m_width;
	float m_height;
public:
	Rect(float startX, float startY, float width, float heigt, wchar_t pixel);

	float* getPosition() const;

	void setPosition(float x, float y);

	bool getShape(float x, float y);

	wchar_t getPixel() const override;
};