#include "Goblin.h"
#include <iostream>

using namespace std;

Goblin::Goblin(std::string name, int health, int attack, int defense, int physicalAttackRegist)
	: Monster(name, health, attack, defense), _physicalAttackRegist(physicalAttackRegist)
{
}

int Goblin::GetPhysicalAttackRegist() {
	return _physicalAttackRegist;
}

void Goblin::GetDamage(int attack) {
	cout << "Goblin GetDamage" << endl;
	_health = attack - _defense - _physicalAttackRegist;
}