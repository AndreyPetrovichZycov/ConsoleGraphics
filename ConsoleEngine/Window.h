#pragma once
#include <Windows.h>
#include "Primitive.h"
#include <iostream>


class Window
{
	int m_screenWidth;
	int m_screenHeight;
	

	HANDLE hConsole;

	//буфер экрана
	wchar_t* screen_buffer;

	DWORD dBytesWritten = 0;


public:
	
	Window(int screenWidth, int screenHeight);

	const int* getWindowSize() const;

	void draw(Primitive& primitive);

	void display();

	void clear();

	~Window();
};