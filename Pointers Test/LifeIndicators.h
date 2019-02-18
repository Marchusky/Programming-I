/* ----------------------------------------------------------------------- */
/*                         INSERT YOUR NAME HERE                           */
/* ----------------------------------------------------------------------- */

#ifndef LIFEINDICATORS_H
#define LIFEINDICATORS_H

#include <iostream>

typedef unsigned short ushort;


void updateLifeIndicatorPlayer1(ushort* lifeIndicatorP1, ushort damage)
{
	// TO DO: Insert your code here
	/*for(int i=0;i<10;++i)     OPCION B
	{
		if (damage != 0 && *lifeIndicatorP1 == 1)
		{
			*lifeIndicatorP1 = 0;
			damage--;
		}
	}*/
	for (int i = 0; i <= 9; i++)
	{
		if (damage == 0)
		{
			return;
		}
		if (*(lifeIndicatorP1 + i) == 1)
		{
			*(lifeIndicatorP1 + i) = 0;
			damage--;
		}
	}
}
	
void updateLifeIndicatorPlayer2(ushort* lifeIndicatorP2, ushort damage)
{
	// TO DO: Insert your code here
	for (int i = 9; i >= 0; i--)
	{
		if (damage == 0)
		{
			return;
		}
		if (*(lifeIndicatorP2 + i) == 1)
		{
			*(lifeIndicatorP2 + i) = 0;
			damage--;
		}
	}
}


#endif