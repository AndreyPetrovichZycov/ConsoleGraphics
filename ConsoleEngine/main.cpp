#include <iostream>
#include <ctime>
#include "Window.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Entity.h"
#include "PhysicsEngine.h"

const int sWidth = 120;
const int sHeight = 30;



int main()
{

	Window w(sWidth, sHeight);

	Rect r(0.2, 0.2, 0.09, 0.05, L'#');

	Circle c(0.2f, 0.05, 0.05f, L'0');
	Circle c1(0.3f, 0.05, 0.05f, L'0');
	
	Entity obj1(&c, { 0.1f, 000.1f });
	Entity obj2(&c1, { 0.2f, 000.1f });


	PhysEngine Physics(0.1, w);


	while (1)
	{
		
		//отрисовка
		//w.draw(c);
		w.draw(c1);
		//w.draw(c2);
		//w.draw(c3);
		//Physics.collision(obj1);
		//Physics.gravityCollision(&obj1);
		Physics.gravityCollision(&obj2);


		w.display();
		w.clear();
		
	}

	return 0;
}