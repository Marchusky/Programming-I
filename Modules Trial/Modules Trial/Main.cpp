#include <cstdlib>

#include "Application.h"

int main()
{
	Application *app = new Application;

	app->start();

	for (int i = 0; i < 3; ++i)
	{
		app->update();
	}

	app->stop();

	delete app;

	system("pause");
	return 0;
}
