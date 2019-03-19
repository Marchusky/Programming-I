#include <iostream>



using namespace std;

char avg(float num1, float num2) {
	return (num1 + num2) / 2;
}

class Pixel {
private:
	short int red, green, blue;
public:
	Pixel() :red(0), green(0), blue(0){}
	Pixel(short int r, short int g, short int b) : red(r), green(g), blue(b){}
	Pixel mix(Pixel p) {
		Pixel newp(avg(this->red, p.red), avg(this->green, p.green), avg(this->blue, p.blue));
		return newp;
	}
	short int r()const { return red; }
	short int g()const { return green; }
	short int b()const { return blue; }

};


class Clock {
private:
	short int hours;
	short int minutes;
	short int seconds;
public:
	Clock() :hours(0), minutes(0), seconds(0){}
	Clock(short int h,short int m, short int s):hours(h),minutes(m),seconds(s){}

	short int h()const { return hours; }
	short int m()const { return minutes; }
	short int s()const { return seconds; }
};

void ex1() {
	Pixel black;
	Pixel blue(0, 0, 255);
	Pixel red(255, 0, 0);;
	Pixel mixed = red.mix(blue);

	cout << black.r() << "  " << black.g() << "  " << black.b() << endl;
	cout << mixed.r() << "  " << mixed.g() << "  " << black.b() << endl;
}
int main() {
	ex1();
	//ex2()


	system("pause");
	return 0;
}