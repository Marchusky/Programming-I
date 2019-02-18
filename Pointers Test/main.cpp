#include "SimpleUnitTest.h"
#include "lifeIndicators.h"

void testExercises();

int main()
{
	/* -- Auto evaluation -- */
	/* Uncomment the line below if you want to evaluate your code */
	testExercises();

	system("pause");
	return 0;
}


/* ----------------------------------------------------------------------- */
/*                     DO NOT TOUCH THE CODE BELOW                         */
/* ----------------------------------------------------------------------- */

void testExercises()
{
	unsigned short lifeIndP1[10];

	lifeIndP1[0] = 1; lifeIndP1[1] = 1; lifeIndP1[2] = 1; lifeIndP1[3] = 1; lifeIndP1[4] = 1;
	lifeIndP1[5] = 1; lifeIndP1[6] = 1; lifeIndP1[7] = 1; lifeIndP1[8] = 1; lifeIndP1[9] = 1;

	updateLifeIndicatorPlayer1(lifeIndP1, 0);

	int res1 = (lifeIndP1[0] == 1 && lifeIndP1[1] == 1 && lifeIndP1[2] == 1 && lifeIndP1[3] == 1 && lifeIndP1[4] == 1 &&
				lifeIndP1[5] == 1 && lifeIndP1[6] == 1 && lifeIndP1[7] == 1 && lifeIndP1[8] == 1 && lifeIndP1[9] == 1);

	updateLifeIndicatorPlayer1(lifeIndP1, 3);

	int res2 = (lifeIndP1[0] == 0 && lifeIndP1[1] == 0 && lifeIndP1[2] == 0 && lifeIndP1[3] == 1 && lifeIndP1[4] == 1 &&
				lifeIndP1[5] == 1 && lifeIndP1[6] == 1 && lifeIndP1[7] == 1 && lifeIndP1[8] == 1 && lifeIndP1[9] == 1);

	updateLifeIndicatorPlayer1(lifeIndP1, 1);

	int res3 = (lifeIndP1[0] == 0 && lifeIndP1[1] == 0 && lifeIndP1[2] == 0 && lifeIndP1[3] == 0 && lifeIndP1[4] == 1 &&
				lifeIndP1[5] == 1 && lifeIndP1[6] == 1 && lifeIndP1[7] == 1 && lifeIndP1[8] == 1 && lifeIndP1[9] == 1);

	updateLifeIndicatorPlayer1(lifeIndP1, 10);

	int res4 = (lifeIndP1[0] == 0 && lifeIndP1[1] == 0 && lifeIndP1[2] == 0 && lifeIndP1[3] == 0 && lifeIndP1[4] == 0 &&
				lifeIndP1[5] == 0 && lifeIndP1[6] == 0 && lifeIndP1[7] == 0 && lifeIndP1[8] == 0 && lifeIndP1[9] == 0);

	updateLifeIndicatorPlayer1(lifeIndP1, 5);

	int res5 = (lifeIndP1[0] == 0 && lifeIndP1[1] == 0 && lifeIndP1[2] == 0 && lifeIndP1[3] == 0 && lifeIndP1[4] == 0 &&
				lifeIndP1[5] == 0 && lifeIndP1[6] == 0 && lifeIndP1[7] == 0 && lifeIndP1[8] == 0 && lifeIndP1[9] == 0);
	
	TEST(": updateLifeIndicatorPlayer1(...)", res1 == 1 && res2 == 1 && res3 == 1 && res4 == 1 && res5 == 1);
	
	
	
	unsigned short lifeIndP2[10];

	lifeIndP2[0] = 1; lifeIndP2[1] = 1; lifeIndP2[2] = 1; lifeIndP2[3] = 1; lifeIndP2[4] = 1;
	lifeIndP2[5] = 1; lifeIndP2[6] = 1; lifeIndP2[7] = 1; lifeIndP2[8] = 1; lifeIndP2[9] = 1;

	updateLifeIndicatorPlayer2(lifeIndP2, 0);

	res1 = (lifeIndP2[0] == 1 && lifeIndP2[1] == 1 && lifeIndP2[2] == 1 && lifeIndP2[3] == 1 && lifeIndP2[4] == 1 &&
			lifeIndP2[5] == 1 && lifeIndP2[6] == 1 && lifeIndP2[7] == 1 && lifeIndP2[8] == 1 && lifeIndP2[9] == 1);

	updateLifeIndicatorPlayer2(lifeIndP2, 3);

	res2 = (lifeIndP2[0] == 1 && lifeIndP2[1] == 1 && lifeIndP2[2] == 1 && lifeIndP2[3] == 1 && lifeIndP2[4] == 1 &&
			lifeIndP2[5] == 1 && lifeIndP2[6] == 1 && lifeIndP2[7] == 0 && lifeIndP2[8] == 0 && lifeIndP2[9] == 0);

	updateLifeIndicatorPlayer2(lifeIndP2, 1);

	res3 = (lifeIndP2[0] == 1 && lifeIndP2[1] == 1 && lifeIndP2[2] == 1 && lifeIndP2[3] == 1 && lifeIndP2[4] == 1 &&
			lifeIndP2[5] == 1 && lifeIndP2[6] == 0 && lifeIndP2[7] == 0 && lifeIndP2[8] == 0 && lifeIndP2[9] == 0);

	updateLifeIndicatorPlayer2(lifeIndP2, 10);

	res4 = (lifeIndP2[0] == 0 && lifeIndP2[1] == 0 && lifeIndP2[2] == 0 && lifeIndP2[3] == 0 && lifeIndP2[4] == 0 &&
			lifeIndP2[5] == 0 && lifeIndP2[6] == 0 && lifeIndP2[7] == 0 && lifeIndP2[8] == 0 && lifeIndP2[9] == 0);

	updateLifeIndicatorPlayer2(lifeIndP2, 5);

	res5 = (lifeIndP2[0] == 0 && lifeIndP2[1] == 0 && lifeIndP2[2] == 0 && lifeIndP2[3] == 0 && lifeIndP2[4] == 0 &&
			lifeIndP2[5] == 0 && lifeIndP2[6] == 0 && lifeIndP2[7] == 0 && lifeIndP2[8] == 0 && lifeIndP2[9] == 0);

	TEST(": updateLifeIndicatorPlayer2(...)", res1 == 1 && res2 == 1 && res3 == 1 && res4 == 1 && res5 == 1);

	PRINT_TEST_REPORT();

	
}