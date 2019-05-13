#include "graphics.h"
#include <iostream>


//                   Drawing Exercises                  //

//void Triangle(const point2d &a,const point2d &b, const point2d &c)
//{
//	line(a, b, c);
//}

struct point2d {
	float x;
	float y;
};

//void slevskyTriangle(a, b, c, level) {
//	if (level < 6)
//	{
//		Triangle(a, b, c);
//
//
//	}
//}

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

void line_entreTres(int level,
	int x1,
	int y1,
	int x2,
	int y2)
{
	if (level < 5) {
		line(x1, y1, x2, y2);

		line_entreTres(level+1, x1, y1 + 10, x2 - (x2 / 3), y2 + 10);


	}
}

//                     Normal Exercises                  //

int numTrues(bool vec[], int sizeVec, unsigned int index)
{

	if (index < sizeVec) 
	{
		int count = numTrues(vec, sizeVec, index + 1);
		if (vec[index] == true) 
		{
			count++;
		}

		return count;
		
	}
	else{
		return 0;
	}
	
}

//bool searchRec(int vec[], int sizeVec, unsigned int index, int val)
//{
//	if (index < sizeVec)
//	{
//		searchRec(vec,)
//	}
//
//}

void main()
{
	/*
	Basic drawing functions.
	void putpixel(int x, int y, int color);
	void line(int x1, int y1, int x2, int y2);
	void rectangle(int left, int top, int right, int bottom);
	void circle(int x, int y, int radius);
	*/
	//                   Drawing Exercises                  //

	initwindow(1000, 1000, "Graphics");

	int level = 0;
	//concentric_circles(level, 500, 500, 400);
	//line_entreTres(level, 1, 1, 1000, 1);


	//                     Normal Exercises                  //
	bool vec[] = { true,true,false,true,false,false,false };
	int count = numTrues(vec, 7, 0);
	std::cout << "There are " << count << " trues in vec." << std::endl;


	system("pause");
}
