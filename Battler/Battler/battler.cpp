#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int playerHP = 20;
	int enemyHP = 20;

	int attackDamage[3] = { 4, 5, 2 };
	int attackHitChance[3] = { 50, 40, 100 };

	while (true)
	{
		int playerChoice;
		int hitRoll = rand() % 100;
		cout << "Choose an attack 1-3:" << endl;
		cout << "1) Sword Smash" << endl;
		cout << "2) Fire Exploder" << endl;
		cout << "3) Sneaky Dagger" << endl;

		cin >> playerChoice;

		switch (playerChoice)
		{
		case 1:
			cout << " You swing away with your sword!" << endl;
			break;
		case 2:
			cout << "You shoot a ton of fire out of your hands!" << endl;
			break;
		case 3:
			cout << "You poke at the enemy with your dagger!" << endl;
			break;
		default:
			cout << "You trip over your own feet and skip your turn!" << endl;
		}

		if (attackHitChance[playerChoice - 1] > hitRoll)
		{
			cout << "You hit him!" << endl;
			enemyHP -= attackDamage[playerChoice - 1];
		}
		else
		{
			cout << "You miss!" << endl;
		}

		int enemyChoice = rand() % 3;
		hitRoll = rand() % 100;

		switch (enemyChoice)
		{
		case 0:
			cout << "Your enemy runs at you with his sword" << endl;
			break;
		case 1:
			cout << "Your enemy shoots fireballs at you" << endl;
			break;
		case 2:
			cout << "Your enemy disapears, only to reapear next to you holding a dagger" << endl;
			break;
		}

		if (attackHitChance[enemyChoice] < hitRoll)
		{
			cout << "He hits you!" << endl;
			playerHP -= attackDamage[enemyChoice];
		}
		else
		{
			cout << "He misses!" << endl;
		}

		if (playerHP < 1)
		{
			cout << "You Lose!" << endl;
			break;
		}
		if (enemyHP < 1)
		{
			cout << "You win!" << endl;
			break;
		}
	}
	return 0;
}