#include "UnitTest.h"
#include "Diablo2.h"
#include <cstdlib> // system
#include <cstring> // strcmp

void unitTest();

int main()
{
	unitTest();

	system("pause");
}

void unitTest()
{
	Character* char1 = new Barbarian();
	Character* char2 = new Paladin();
	Character* char3 = new Wizard();

	bool res1 = (strcmp(char1->getName(), "Barbarian") == 0);
	bool res2 = (strcmp(char2->getName(), "Paladin") == 0);
	bool res3 = (strcmp(char3->getName(), "Wizard") == 0);

	TEST(": getName(...)", res1 && res2 && res3);

	res1 = char1->physicalAttack() == 10;
	res2 = char2->physicalAttack() == 3;
	res3 = char3->physicalAttack() == 0;

	TEST(": physicalAttack(...)", res1 && res2 && res3);

	res1 = char1->magicAttack() == 0;
	res2 = char2->magicAttack() == 3;
	res3 = char3->magicAttack() == 15;

	TEST(": magicAttack(...)", res1 && res2 && res3);

	evaluateAttack(char1, char2);
	res1 = char2->getLifePoints() == 10;
	evaluateAttack(char2, char1);
	res2 = char1->getLifePoints() == 17;
	evaluateAttack(char1, char3);
	res3 = char3->getLifePoints() == 2;
	evaluateAttack(char3, char1);
	bool res4 = char1->getLifePoints() == 2;
	evaluateAttack(char3, char2);
	bool res5 = char2->getLifePoints() == 0;
	evaluateAttack(char2, char3);
	bool res6 = char3->getLifePoints() == 0;

	TEST(": evaluateAttack(...)", res1 && res2 && res3 && res4 && res5 && res6);

	PRINT_TEST_REPORT();

	delete char1;
	delete char2;
	delete char3;
}