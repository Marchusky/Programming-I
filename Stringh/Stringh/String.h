#include <cstring>


class String {
public:
	// Constructors and destructor
	String();
	String(const char *s);
	String(const String &s);
	~String();
	// Methods
	bool empty() const;
	int size() const;
	void clear();
	const char *c_str() const;
	// Operators
	void operator=(const String &) 
	{

	} // to assign
	void operator+=(const String &)
	{

	}// to concat
	bool operator==(const String &) const
	{

	}// to compare
	bool operator!=(const String &) const
	{

	}// to compare
private:
	char *_str; // Pointer to the array of chars
	int _size; // Size of the string
};