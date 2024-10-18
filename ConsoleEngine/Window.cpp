#include "Window.h"


Window::Window(int screenWidth, int screenHeight) {

	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, 0, CONSOLE_TEXTMODE_BUFFER, 0);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

	SetConsoleActiveScreenBuffer(hConsole);

	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	screen_buffer = new wchar_t[m_screenWidth * m_screenHeight];
	
	clear();
}


const int* Window::getWindowSize() const
{
	const int size[] = {m_screenWidth, m_screenHeight};
	return size;
}


void Window::draw(Primitive& primitive)
{
	for (int i = 0; i < m_screenHeight; i++) {
		for (int j = 0; j < m_screenWidth; j++) {

			float x = static_cast<float>(j) / (m_screenWidth - 1);
			float y = static_cast<float>(i) / (m_screenHeight - 1);

			x -= primitive.getPosition()[0];
			y -= primitive.getPosition()[1];


			if (primitive.getShape(x, y)) {
				screen_buffer[i * m_screenWidth + j] = primitive.getPixel();
			}

		}
	}
}


void Window::display()
{

	WriteConsoleOutputCharacter(hConsole, screen_buffer, m_screenWidth * m_screenHeight, { 0,0 }, &dBytesWritten);

}


void Window::clear()
{
	for (int i = 0; i < m_screenWidth * m_screenHeight; i++) {
		screen_buffer[i] = L' ';
	}
}



Window::~Window() {
	delete[] screen_buffer;
}
