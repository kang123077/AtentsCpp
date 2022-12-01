#include "Golem.h"
#include <iostream>

Golem::Golem(std::string name, int health, int attack, int defense)
	: Monster(name, health, attack, defense) {}


void Golem::GetDamage(int attack) {

	std::cout << "Golem::GetDamage" << std::endl;
	_health -= (attack - _defense);

	if (_health <= 0) {
		Dead();
	}
}