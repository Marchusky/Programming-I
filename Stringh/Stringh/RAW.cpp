#include <cstring>


int main()
{
	// Declaration
	char str1[10];
	char str2[10];
	// Copy
	strcpy(str1, "Cloud");
	strcpy(str2, "Barret");
	// Compare
	bool equals = strcmp(str1, str2) == 0;
	// Copy and concat
	char str3[20];
	strcpy(str3, str1);
	strcat(str3, str2);
}
