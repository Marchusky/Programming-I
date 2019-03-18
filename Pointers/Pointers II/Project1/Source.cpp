#include <iostream>

void ArraySum(int *p)
{

	std::cout << "Sum equals:" << *p + *(p + 1) + *(p + 2) << std::endl;
}

int ArraySumBucle(int *p, int size)
{
	int Sum = 0;
	for (int i = 0; i < size; ++i)
	{
		Sum += *(p + i);
	}
	return Sum;
}

void PrintString(int *p)
{
	while ( *p != '\0')
	{
		std::cout<<*p<<
	}
}

int main()
{
	int array[3] = { 1,2,3 };
	int *pointer = array;
	ArraySum(pointer);
	int Sum= ArraySumBucle(pointer, 3);
	std::cout << "Sum equals:" << Sum << std::endl;

	const char*p = "Hello world of pointers";
	PrintString(*p);

	system("pause");
	return 0;
}