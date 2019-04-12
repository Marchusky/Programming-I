#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string.h>


class String {
public:
	// Constructors and destructor
	String() {
		array = nullptr;
		size = 0;
	};
	String(const char *str)
	{
		size = strlen(str);
		array = new char[size + 1];
		strcpy(array, str);
	};
	String(const String &str)
	{
		size = str.size;
		array = new char[size + 1];
		strcpy(array, str.c_str());
	};
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
		delete[] array;
		array = nullptr;
		size = 0;
	}
	const char *c_str() const 
	{
		if (array == nullptr) { return ""; }
		else { return array; }
	}
	// Operators
	void operator=(const String &str) 
	{
		size = str.size;
		char*buffer = new char[size + 1];
		strcpy(array, str.c_str());
	} // to assign
	void operator+=(const String &str)
	{
		size += str.size;
		char*buffer = new char[size + str.size + 1];
		strcpy(buffer, array);
		strcat(buffer, str.c_str());
		delete[] array;
		array = buffer;
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
	char *array; // Pointer to the array of chars
	int size; //Size of the string, '\0' no cuenta.
};