#include "graphics.h"
#include <iostream>
#include <cstdlib>

//			Marc Gallardo Quesada			//



// Cantor set //////////////////////////////////////////////////////////////////

void cantor(int depth, float x1, float x2, float y)
{
	// TODO
}


// Circles /////////////////////////////////////////////////////////////////////

void circles(int depth, float x, float y, float radius)
{
	// TODO
}


// 2D vector utility ///////////////////////////////////////////////////////////

struct vec2
{
	float x, y;
	vec2() : x(0), y(0) {}
	vec2(float X, float Y) :x(X), y(Y) {}
};

vec2 operator+(const vec2 &a, const vec2 &b) { return vec2(a.x + b.x, a.y + b.y); }
vec2 operator-(const vec2 &a, const vec2 &b) { return vec2(a.x - b.x, a.y - b.y); }
vec2 operator-(const vec2 &b) { return vec2(- b.x, - b.y); }
vec2 operator*(float v, const vec2 &a) { return vec2(a.x * v, a.y * v); }
vec2 operator*(const vec2 &a, float v) { return vec2(a.x * v, a.y * v); }
vec2 operator/(const vec2 &a, float v) { return vec2(a.x / v, a.y / v); }
float dot(const vec2 &a, const vec2 &b) { return a.x * b.x + a.y * b.y; }
float length(const vec2 &v) { return sqrt(dot(v, v)); }
vec2 perpendicular(const vec2 &v) { return vec2(v.y, -v.x); }
vec2 normalize(const vec2 &v) { return v / length(v); }


// Sierpinski fractal //////////////////////////////////////////////////////////


void triangle(const vec2 &a, const vec2 &b, const vec2 &c)
{
	line(a.x, a.y, b.x, b.y);
	line(b.x, b.y, c.x, c.y);
	line(c.x, c.y, a.x, a.y);
}

void Square(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2)
{
	line(a1, a2, b1, b2);
	line(b1, b2, c1, c2);
	line(c1, c2, d1, d2);
	line(d1, d2, a1, a2);
}

void Squares(int depth, int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2)
{
	int lenght = (b1-a1);
	float dF = lenght * 0.4; //240
	float dff = (lenght*0.2) / 3; //40
	float df = dF + dff; //320
	
	if (depth < 4)
	{
		Square(a1, a2, b1, b2, c1, c2, d1, d2);
		Squares(depth + 1, a1 + dff, a2 + dff, b1 - (df + dff), b2 + dff, c1 - (df + dff), c2 - (df + dff), d1 + dff, d2 - (df + dff));
		Squares(depth + 1, a1 + (df+dff), a2 + dff, b1 - dff, b2 + dff, c1 - dff, c2 - (df + dff), d1 + (df+dff), d2 - (df+dff));
		Squares(depth + 1, a1 + (df + dff), a2 + (df + dff), b1 - dff, b2 + (df + dff), c1 - dff, c2 - dff, d1 + (df + dff), d2 - dff);
		Squares(depth + 1, a1 + dff, a2 + (df+dff), b1 - (df + dff), b2 + (df+dff), c1 - (df + dff), c2 - dff, d1 + dff, d2 - dff);


	

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

	Square(50, 50, 100, 50, 100, 100, 50, 100);

	Squares(0,200, 200, 800, 200, 800, 800, 200, 800);

	system("pause");
}
