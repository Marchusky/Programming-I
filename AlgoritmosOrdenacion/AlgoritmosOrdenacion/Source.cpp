#include <iostream>	
#include <cstdlib>


void print(int *array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void bubbleSort(int *arr, int size)
{
	int numSwaps = 0;
	int temp = 0;
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (arr[i] < arr[i - 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			if (arr[j] < arr[j - 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
}

int main()
{
	int v[10] = { 9,1,8,2,7,3,6,4,5,0 };
	print(v, 10);
	bubbleSort(v, 10);
	print(v, 10);

	system("pause");
	return 0;
}