#include <iostream>
#include <stdlib.h>

using namespace std;

class Point {
private:
	int x, y;
public:
	void move(int dx, int dy){
		x += dx;
		y += dy;	}
	int getx()const { return x; }
	int gety()const { return y; }
	void setx(int newx) { x = newx; }
	void sety(int newy) { y = newy; }
};

class point {
private:
	int x, y;
public:
	int getx()const { return x; }
	int gety()const { return y; }
	void setx(int newx) { x = newx; }
	void sety(int newy) { y = newy; }
	point() {
		cout << "constructor" << endl; //se lee al crear el nuevo point
	}
	~point() {
		cout << "destructor " << x << " " << y << endl; //se lee al borrar el point
	}
	
};


int main() {
	Point p;
	{
		point p1;
		p1.setx(1);
		p1.sety(2);
	}
	point *p2 = new point;
	p2->setx(3);
	p2->sety(4);
	delete p2;

	//cout << p.getx() << " " << p.gety() << endl;
	system("pause");
	return 0;
}