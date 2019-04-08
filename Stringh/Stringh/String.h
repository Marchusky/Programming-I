#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string.h>


class String {
public:
	// Constructors and destructor
	String();
	String(const char *s);
	String(const String &s);
	~String()
	{
		delete[] array;
	};
	// Methods
	bool empty() const;
	void clear();
	const char *c_str() const;
	// Operators
	void operator=(const char *str) 
	{
		delete[] array; //if algo apuntado de antes
		size = strlen(str);
		str = new char[size + 1]; //
		strcpy(array, str);
	} // to assign
	void operator+=(const char *str)
	{

	}// to concat
	bool operator==(const char *str) const
	{

	}// to compare
	bool operator!=(const char *str) const
	{

	}// to compare
private:
	char *array = nullptr; // Pointer to the array of chars
	int size = 0; //Size of the string, '\0' no cuenta.
};