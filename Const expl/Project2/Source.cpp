#include <iostream>

int val;
int *ptr1 = &val; //nothing const, can chane val & pointer.
const int *ptr2 = &val; //const int, cannot change val.
int * const ptr3 = &val; //const ptr3, cannot change pointer.
int array[30]; //like a pointer to the FIRST VALUE of the array, ptr cannot change.
const int* const ptr4 = &val; //const int, cannot change val & const ptr4, cannot change pointer.
const int MAX_PLAYERS = 4; //


class Player
{
private:
	int x;
	public:
		void copyFrom(const Player &player) //const Player, cannot change Player.
		{
			//code
		}
		void copyTo(Player &player)const //const player implicito(el "invisible"), cannot change implicit player.
		{
			player.x = x; //Example to see that we have 2 players in this function.
		}
};

int main()
{
	Player p1, p2;
	p1.copyFrom(p2);
	p2.copyTo(p1);
}