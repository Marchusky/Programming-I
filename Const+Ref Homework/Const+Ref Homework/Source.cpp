#include <iostream>

void Double(unsigned short& g) {
	g * 2;
}

void ex1() {
	std::cout << "Write a number from 0 to 100" << std::endl;
	unsigned short num;
	std::cin >> num;
	unsigned short& pedo = num;
	Double(num);

	std::cout << "The double of your number is: " << pedo << std::endl;
}

void increment(int& n)
{
	++n;
}


int main() {
	ex1();

	

	int a = 3;
	int& ra = a;
	increment(a);
	std::cout << ra << std::endl; // prints 4
	

	system("pause");
	return 0;
}