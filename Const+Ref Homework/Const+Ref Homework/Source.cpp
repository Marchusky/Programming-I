#include <iostream>

void Double(unsigned short& g) {
	g = g * 2;
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

struct pirate {
	char name[20];
	int lifeUnits;
};

struct Weapon {
	char name[20];
	int damageUnits;
};

void attack(pirate*lechuck, const Weapon &blade) {
	lechuck->lifeUnits = lechuck->lifeUnits - blade.damageUnits;
}

void printPirate(const pirate &p) {
	std::cout << "Name: " << p.name << "     current HP: " << p.lifeUnits << std::endl;
}

void ex2() {
	pirate Pirate = { "lechuck", 100 };
	Weapon Weapon = { "Oathbringer",10 };
	attack((&Pirate), (Weapon));
	printPirate(Pirate);
}

int main() {
	ex1();
	ex2();
	

	int a = 3;
	int& ra = a;
	increment(a);
	std::cout << ra << std::endl; // prints 4
	


	system("pause");
	return 0;
}