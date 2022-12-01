#include "LizardMan.h"
#include <iostream>

using namespace std;

LizardMan::LizardMan(std::string name, int health, int attack, int defense, int physicalAttackRegist)
	: Monster(name, health, attack, defense), _physicalAttackRegist(physicalAttackRegist)
{
}

int LizardMan::GetPhysicalAttackRegist() {
	return _physicalAttackRegist;
}

void LizardMan::GetDamage(int attack) {
	cout << "LizardMan::GetDamage" << endl;

	int attackValue = attack - _defense - _physicalAttackRegist;

	if (attackValue <= 0) {
		attackValue = 0;
	}

	_health -= attackValue;

	if (_health <= 0) {
		Dead();
	}
}