#include <iostream>

struct Player
{
	int health;
	float x, y;
};

void printPlayer(Player *p)
{
	std::cout << (*p).health << std::endl; //metes en el parentesis lo 
	std::cout << (*p).x << std::endl;      //que quieres que se haga primero
	std::cout << (*p).y << std::endl;

	std::cout << p->health << std::endl; //same that (*p).algo
	std::cout << p->x << std::endl;
	std::cout << p->y << std::endl;
}

int main()
{
	Player p = { 100,5.0,5.0 };
	printPlayer(&p);

	system("pause");
	return 0;
}