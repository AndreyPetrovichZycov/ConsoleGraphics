#include <windows.h>
#include <conio.h>
#include <string>
#include<iostream>
#include <chrono>

const int sWidth = 120;
const int sHeight = 30;

class Primitive
{
public:
	virtual void draw(wchar_t* screen_buffer) = 0;
};


class Circle : Primitive
{
	float m_radius;
	float m_speed;
	float x_pos; //координаты центра
	float y_pos;
	wchar_t m_pixel;


	float (*m_traect_X)(float) = 0;
	float (*m_traect_Y)(float) = 0;

	HANDLE m_hConsole;

	float dt = 0;

public:
	Circle(float x_start, float y_start, float radius, float speed, wchar_t pixel, HANDLE hConsole)
	{
		m_hConsole = hConsole;
		m_radius = radius;
		m_speed = speed;
		m_pixel = pixel;
		x_pos = x_start;
		y_pos = y_start;

		SetConsoleActiveScreenBuffer(m_hConsole);
	}

	void setPosition(float x, float y) {
		x_pos = x;
		y_pos = y;
	}

	float getPositionX() {
		return x_pos;
	}

	float getPositionY() {
		return y_pos;
	}

	float getRadius() {
		return m_radius;
	}

	void draw(wchar_t* screen_buffer) override
	{
		for (int i = 0; i < sHeight; i++) {
			for (int j = 0; j < sWidth; j++) {
				float x = (float)j / (sWidth - 1);
				float y = (float)i / (sHeight - 1);

				x -= x_pos;
				y -= y_pos;

				if (x * x + y * y * 0.36 < m_radius) {
					screen_buffer[i * sWidth + j] = m_pixel;
				}


			}
		}

	}


};


void clear(wchar_t* screen_buffer) {
	for (int i = 0; i < sWidth * sHeight; i++) {
		screen_buffer[i] = ' ';
	}
}


int main()
{
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, 0, CONSOLE_TEXTMODE_BUFFER, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

	Circle c1(0.2, 0.5, 0.002, 0.5, L'@', hConsole);
	Circle c2(0.4, 0.2, 0.003, 0.003, L'0', hConsole);
	Circle c3(0.1, 0.2, 0.004, 0.006, L'0', hConsole);

	wchar_t* screen_buffer = new wchar_t[sWidth * sHeight];
	DWORD dBytesWritten = 0;

	WORD attribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	DWORD numberOfAttrsWritten;

	//попытка разукрасить шарик
	//WriteConsoleOutputAttribute(hConsole, &attribute, 100, { 10,10 }, &numberOfAttrsWritten);


	//0 <= x <= 1, 0 <= y <= 1 screen size

	float t = 0.F;

	//vector speed

	double v[2] = { 0.05, 0.05 };
	float s[] = { c1.getPositionX(), c1.getPositionY() };

	std::cout << v[0] << std::endl;
	clear(screen_buffer);

	while (1)
	{
		t = t / 60.f;

		s[0] = s[0] + v[0] * t;
		s[1] = s[1] + v[1] * t;
		c1.draw(screen_buffer);
		c1.setPosition(s[0], s[1]);

		//collision
		if (c1.getPositionX() + c1.getRadius() > 1) {
			v[0] = -v[0];
			v[1] = v[1];
			//break;
		}
		if (c1.getPositionY() + c1.getRadius() > 1) {
			v[0] = v[0];
			v[1] = -v[1];
			//break;
		}
		if (c1.getPositionX() - c1.getRadius() < 0) {
			v[0] = -v[0];
			v[1] = v[1];
			//break;
		}
		if (c1.getPositionY() - c1.getRadius() < 0.10) {
			v[0] = v[0];
			v[1] = -v[1];
			//break;
		}

		std::cout << c1.getPositionX() << std::endl;

		screen_buffer[sWidth * sHeight - 1] = L'\0';

		WriteConsoleOutputCharacter(hConsole, screen_buffer, sWidth * sHeight, { 0,0 }, &dBytesWritten);
		clear(screen_buffer);

		t += 1;
	}

	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;

	std::cout << c1.getPositionX();

	return 0;
}