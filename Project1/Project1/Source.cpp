#include <iostream>
#include <stdlib.h>

int main()
{
	int* numss = (int*)malloc(4* sizeof(int));


	for (int i = 0; i < 4; ++i)
	{
		numss[i] = i + 1;
		std::cout << *(numss + i) << std::endl;

	}

	free(numss);
	numss = nullptr;
	
	std::cout << "\n" << std::endl;
	
	
	int* nums = (int*)calloc(4 , sizeof(int));
	
	nums[1] = 2;
	for (int i = 0; i < 4; ++i)
	{
		
		std::cout << *(nums + i) << std::endl;

	}
	
	free(nums);
	nums = nullptr;


	system("pause");
	return 0;
}