#include <iostream>
#include <stdio.h>


void recursiveFunc(int i)
{
	std::cout << "hola" << i << std::endl;
	recursiveFunc(i+1);
}

int main()
{
	recursiveFunc(0);
	system("pause");
	return 0;
}