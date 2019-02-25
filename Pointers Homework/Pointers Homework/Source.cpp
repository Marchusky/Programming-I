#include <iostream>
#include <stdlib.h>
#include <stdio.h>


void ex1(){
	int arr[10];
	for (int i = 0; i < 10; ++i){
		int *ptr = &arr[i];
		std::cout << ptr << std::endl;
	}
}


void ex2function(int v1, int v2, int*ptr){
	*ptr = v1 + v2;
}

void ex2(){
	std::cout << "Write two valors" << std::endl;
	int val1;
	int val2;
	std::cin >> val1;
	std::cin >> val2;
	
	int result;
	ex2function(val1, val2, &result);
	std::cout << "The result is:" << result << std::endl;
}

//void reverse(int *values, int sizeArray){
//	for (int c = (sizeArray - 1); c >= 0; --c){
//		std::cout << *(values + c) << " ";
//	}
//}
//
//
//void ex3(){
//	int arr[10];
//
//	for (int i = 0; i < 10; ++i){
//		std::cin >> values[i];
//	}
//	reverse(values, 10);
//}
//
//void absSwap(int*arr1, int sizeArr1, int*arr2, int sizeArr2){
//	for (int i = 0; i < sizeArr1&&i < sizeArr2; ++i) {
//
//		if (arr[i])
//	}
//}
//
//
//void ex4(){
//	int*arr1 = (int*)calloc(20, sizeof(int));
//	int*arr2 = (int*)malloc(20 * sizeof(int));
//
//	absSwap(arr1, 20, arr2, 20);
//
//
//
//
//	free(arr1);
//	free(arr2);
//	arr1 = arr2 = nullptr;
//}


//void ex5() {
//
//}






int main(){
	ex1();
	ex2();
	//ex3();
	//ex4();
	//ex5();





	system("pause");
	return 0;
}