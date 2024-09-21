#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

struct {
	int health;
	int dmg;
	string name;
	int critChance;
}Player1;

struct Enemy{
	int health;
	int dmg;
	string name;
};

Enemy generateEnemy() {
	Enemy newEnemy;
	string enemies[6] = {"Goblin", "Wizard", "Witch", "Mouse", "Theif", "Demon"};
	int choice = rand() % 6 + 1;
	newEnemy.name = enemies[choice];
	switch (choice) {
		case 0 : {
			newEnemy.health = 10;
			newEnemy.dmg = 5;
			break;
		}
		case 1 : {
			newEnemy.health = 20;
			newEnemy.dmg = 10;
			break;
		}
		case 2 : {
			newEnemy.health = 15;
			newEnemy.dmg = 8;
			break;
		}
		case 3 : {
			newEnemy.health = 5;
			newEnemy.dmg = 20;
			break;
		}
		case 4 : {
			newEnemy.health = 15;
			newEnemy.dmg = 10;
			break;
		}
		case 5 : {
			newEnemy.health = 100;
			newEnemy.dmg = 10;
			break;
		}
		default:
			newEnemy.health = 10;
			newEnemy.dmg = 10;
			break;
	}
	return newEnemy;
}

void attack(Enemy &enemy) {
	int chance = rand() % Player1.critChance + 1;
	if (chance == 1) {
		enemy.health -= Player1.dmg * 2;
		cout << "CRITICAL HIT:" << Player1.dmg * 2 << " damage!!!" << endl;
	} else {
		enemy.health -= Player1.dmg;
		cout << "You did " <<  Player1.dmg << " damage!" << endl;
	}
}

int encounter(Enemy enemy) {
	system("clear");	
	cout << "You encountered a " << enemy.name << "!" << endl;
	while (enemy.health > 0 && Player1.health > 0) {
		cout << Player1.name << " Health: " << Player1.health << endl;
		cout << enemy.name << " Health: " << enemy.health << endl << endl;
		cout << "Choose your move:" << endl;
		cout << "1 - Attack" << endl;
		cout << "2 - Heal" << endl;
		cout << "3 - Dodge" << endl;
		cout << "4 - View Items" << endl;
		cout << " -->";
		int choice;
		cin >> choice;
		if (choice == 1) {
			attack(enemy);
		} else if (choice == 2) {
			cout << "+5 HEALTH" << endl;
			Player1.health += 5;
		} else if (choice == 3) {
			int chance = rand() % Player1.critChance + 1;
			if (chance == 1) {
				cout << "YOU DODGED!";
				//make later
			} else {
				cout << "YOU FAILED TO DODGE!" << endl;
			}
		}
	}
	if (Player1.health > 0) { return 0; } else { return 1; }
}

int main() {
	srand(time(0));
	Player1.health = 25;
	Player1.dmg = 5;
	cout << "Enter a name!" << endl;
	cin >> Player1.name;
	Player1.name[0] = toupper(Player1.name[0]);
	Player1.critChance = 10;
	while (encounter(generateEnemy()) != 1) {
		cout << "You defeated the enemy! Moving on!" << endl;
	}
	cout << "You died :(" << endl;
	return 0;
}
