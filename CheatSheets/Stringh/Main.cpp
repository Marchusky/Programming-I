//Memory leaks
#define _CRTDBG_MAP__ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "String.h" // We will implement this
#include "Array.h"  // We will implement this
#

//_CTR_USINGNAMESPACE_STD
//
//int main()
//{
//	// Declaration
//	String str1;
//	String str2;
//	// Copy ( operator= )
//	str1 = "Cloud";
//	str2 = "Barret";
//	// Compare ( operator== )
//	bool equals = (str1 == str2);
//	// Copy and concat ( operator+ )
//	String str3 = str1 += str2;
//
//
//	//Pruebas
//	//cout<<str1()<<endl
//
//	//Memory Leaks
//	_CrtDumpMemoryLeaks();
//
//	system("pause");
//	return 0;
//}