#ifndef __MEMLEAKS_H__
#define __MEMLEAKS_H__

//To enable all the debug heap functions
//include the following statements in your C++ program.

#define _CRTDBG_MAP_ALLOC
//The #define statement maps a base version of the CRT heap functions to the corresponding debug version.
//If you leave out the #define statement,the memory leak dump will be less detailed.

#include <stdlib.h>

#include <crtdbg.h>
#ifdef _DEBUG
//Including crtdbg.h maps the malloc and free functions to their debug versions. 
//This mapping occurs only in debug builds, which have _DEBUG

#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//Leerse con la calma: 
/*https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2017*/

#define new DBG_NEW 
//?

#endif
#endif  // _DEBUG

#define ReportMemoryLeaks() _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF)
//CrtDumpMemoryLeaks() is a function that displays a memory leak report when the app exits.
//Since it must be called in each program exit, we must use '_CrtSetDbgFlag()' 
//that calls CrtDumpMemoryLeaks() automatically before the aplication stops.

#endif // __MEMLEAKS_H__