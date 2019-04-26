#include <iostream>
// Has all functions from Windows API library
#include <Windows.h>
#include <stdio.h>

// Gets together all these variables, files, etc in a unique string.
void log(const char file[], int line, const char* format, ...) {

	/* Statics variable are initialized the first time its definition is encountered, but not destructed when the function exits. 
	So it keeps its value between invocations of the function.*/
	static char tmp_string[4096];
	static char tmp_string2[4096];
	// Type to hold information about variable arguments and retrieves(recuperar) additional arguments
	static va_list ap;

	// Construct the string from variable arguments. As va_list is called, other va_functions should be called.
	// Initialize a variable argument list.
	va_start(ap, format);
	vsprintf_s(tmp_string, 4096, format, ap);
	//End using variable argument list.
	va_end(ap);
	sprintf_s(tmp_string2, 4096, "\n%s(%d) : %s", file, line, tmp_string);
	// Sends a string to the debugger if there is any error.
	OutputDebugString(tmp_string2);

}