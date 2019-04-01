/* ----------------------------------------------------------------------- */
/*                          Marc Gallardo Quesada                           */
/* ----------------------------------------------------------------------- */

#ifndef DIABLO2_H
#define DIABLO2_H
#include <string.h>

//////////////CHARACTER
class Character
{
private:
	char name[25];
protected:
	int lifePoints;
public:
	Character(const char *string, int hp) 
	{
		strcpy_s(name, string);
		lifePoints = hp;
	}
	virtual~Character(){}
	const char *getName() const { return name; }
	int const getLifePoints() const { return lifePoints; }
	virtual int const physicalAttack() = 0;
	virtual int const magicAttack() = 0;
	virtual void applyDamage(int physicalDamage, int magicDamage) = 0;
	
};

//////////////BARBARIAN
class Barbarian : public Character
{
public:
	Barbarian(): Character("Barbarian", 20){}
	int const physicalAttack()override { return 10; }
	int const magicAttack()override { return 0; }
	void applyDamage(int physicalDamage, int magicDamage)override 
	{
		physicalDamage = (physicalDamage - 5);
		magicDamage = (magicDamage - 0);
		if (physicalDamage < 0)
		{
			physicalDamage = 0;
		}
		if (magicDamage < 0)
		{
			magicDamage = 0;
		}
		lifePoints = lifePoints - (magicDamage + physicalDamage);
		if (lifePoints < 0) { lifePoints = 0; }
	}
};


//////////////PALADIN
class Paladin :public Character
{
public:
	Paladin():Character("Paladin",15){}
	int const physicalAttack()override { return 3; }
	int const magicAttack()override { return 3; }
	void applyDamage(int physicalDamage, int magicDamage)override 
	{
		physicalDamage = (physicalDamage - 5);
		magicDamage = (magicDamage - 5);
		if (physicalDamage < 0) 
		{
			physicalDamage = 0;
		}
		if (magicDamage < 0)
		{
			magicDamage = 0;
		}
		lifePoints = lifePoints - (magicDamage + physicalDamage);
		if (lifePoints < 0) { lifePoints = 0; }
	}
};


//////////////WIZARD
class Wizard :public Character
{
public:
	Wizard():Character("Wizard",12){}
	int const physicalAttack()override { return 0; }
	int const magicAttack()override { return 15; }
	void applyDamage(int physicalDamage, int magicDamage)override 
	{
		physicalDamage = (physicalDamage - 0);
		magicDamage = (magicDamage - 5);
		if (physicalDamage < 0)
		{
			physicalDamage = 0;
		}
		if (magicDamage < 0)
		{
			magicDamage = 0;
		}
		lifePoints = lifePoints - (magicDamage + physicalDamage);
		if (lifePoints < 0) { lifePoints = 0; }

	}
};


//////////////EVALUATE ATTACK
void evaluateAttack(Character* attacker, Character* defender)
{
	defender->applyDamage(attacker->physicalAttack(), attacker->magicAttack());
}

#endif