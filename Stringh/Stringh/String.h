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
	bool empty() const
	{
		if (strlen(array) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	int _size()const { return size; }
	void clear()
	{
		array = nullptr;
		size = 0;
	}
	const char *c_str() const { return array; }
	// Operators
	void operator=(const char *str) 
	{
		delete[] array; //if algo apuntado de antes
		size = strlen(str);
		str = new char[size + 1]; //el +1 es para el '\0'.
		strcpy(array, str);
	} // to assign
	void operator+=(const char *str)
	{
		strcat(array, str);
	}// to concat
	bool operator==(const char *str) const
	{
		if (strcmp(array, str)==1)
		{
			return true;
		}
	}// to compare
	bool operator!=(const char *str) const
	{
		if (strcmp(array, str))
		{
			return false;
		}
	}// to compare
private:
	char *array = nullptr; // Pointer to the array of chars
	int size = 0; //Size of the string, '\0' no cuenta.
};