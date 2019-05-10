#include "graphics.h"
#include <iostream>

void concentric_circles(
	int level,
	int x,
	int y,
	int radius)
{
	float D = 3;
	if (level < 5) {
		
		circle(x, y, radius);
		//circle(x - radius/2, y, radius / D);
		//circle(x + radius/2, y, radius / D);
		//circle(x, y - radius / 2, radius / D);
		//circle(x, y + radius / 2, radius / D);



		concentric_circles(level + 1, x - radius / D - radius / D, y, radius / D);
		concentric_circles(level + 1, x + radius / D + radius / D, y, radius / D);
		concentric_circles(level + 1, x, y - radius / D - radius / D, radius / D);
		concentric_circles(level + 1, x, y + radius / D + radius / D, radius / D);

		
	}
}



void main()
{
	/*
	Basic drawing functions.
	void putpixel(int x, int y, int color);
	void line(int x1, int y1, int x2, int y2);
	void rectangle(int left, int top, int right, int bottom);
	void circle(int x, int y, int radius);
	*/

	initwindow(1000, 1000, "Graphics");

	int level = 0;
	concentric_circles(level, 500, 500, 500);

	// polla
	/*circle(200, 600, 100);
	circle(400, 600, 100);
	line(200, 500, 200, 100);
	line(400, 500, 400, 100);
	line(200, 100, 300, 50);
	line(400, 100, 300, 50);*/


	system("pause");
}
