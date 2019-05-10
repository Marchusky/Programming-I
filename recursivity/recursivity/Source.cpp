#include <iostream>

//void RecursiveFunc2() {
//	std::cout << "hola 2" << std::endl;
//}
//
//void RecursiveFunc(int i) {
//
//	if (i > 0) {
//		RecursiveFunc(i +1);
//		std::cout << "hola " << i << std::endl;
//	}
//	else //caso base (cuando acaba y no vuelve a llamarse a si misma
//	{
//		std::cout << "adios " << std::endl;
//	}
//}

//int factorial(int n) 
//{
//	if (n > 0) 
//	{
//			return n * factorial(n - 1);
//	}
//	else
//	{
//		return 1;
//	}
//}

int fibonacci(int n) {
	if (n > 1) {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	//RecursiveFunc(0);
	int i = 0;
	int j = 0;
	int k = 0;
	std::cin >> i;
	std::cin >> j;
	std::cin >> k;

	//std::cout << "The result is " << factorial(i) << std::endl;
	std::cout << "The result is " << fibonacci(i) << std::endl;
	std::cout << "The result is " << fibonacci(j) << std::endl;
	std::cout << "The result is " << fibonacci(k) << std::endl;




	system("pause");
	return 0;
}