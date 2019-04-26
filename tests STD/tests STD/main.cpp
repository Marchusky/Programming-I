#include <iostream>
#include <string>
#include <vector>

int main()
{
	//*********** string **********//
	std::cout << "*** TEST STD ***" << std::endl;

	std::string s;

	s = "Hello There";
	s += "General Kenobi";

	std::cout << s << std::endl;

	s.clear();

	std::cout << s << std::endl;

	std::string directory = "C:/users/jesus/Project1";
	std::string file = "patricio.3ds";
	std::string path = directory + "/" + file;

	std::cout << path << std::endl;

	//*********** string **********//
	std::vector<float> v;
	v.push_back(50);
	for (int i = 0; i < 3; ++i)
	{
		v.push_back(i);
	}
	for (int i = 0; i < 3; ++i)
	{
		v.insert(v.begin(), i);
	}
	for (int i = 0; i < 3; ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << "\n" << std::endl;





	system("pause");
	return 0;
}