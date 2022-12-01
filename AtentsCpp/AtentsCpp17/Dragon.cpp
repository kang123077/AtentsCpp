#include "Dragon.h"
#include <iostream>

Dragon::Dragon(std::string name, int health, int attack, int defense)
	: Monster(name, health, attack, defense) {}

void Dragon::GetDamage(int attack) {

	std::cout << "Dragon::GetDamage" << std::endl;
	_health -= (attack - _defense);

	if (_health <= 0) {
		Dead();
	}
}