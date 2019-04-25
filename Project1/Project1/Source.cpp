#include <stdlib.h>
#include <stdio.h>

#define MAXHEALTH 7200

int main(){

	int life = MAXHEALTH;
	printf("Your Health is: %d\n", life);

	int Kdamage;
	int Pdamage;

	int Kincrease = 100;
	int Pincrease = 200;

	int RageBar = 0.5;

	int Haokick = 350;
	int Haopunch = 600 + RageBar * Pincrease;

	Kdamage = Haokick + RageBar * Kincrease;
	Pdamage = Haopunch + RageBar * Pincrease;

	int TotDamage = Kdamage + Pdamage;

	life = MAXHEALTH - TotDamage;

	printf("Your Health is: %d\n", life);



	system("pause");
	return 0;
}