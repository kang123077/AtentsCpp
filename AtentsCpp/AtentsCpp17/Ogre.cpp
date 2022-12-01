#include "Ogre.h"
#include <iostream>

using namespace std;


Ogre::Ogre(std::string name, int health, int attack, int defense, int physicalAttackRegist) 
	: Monster(name, health, attack, defense), _physicalAttackRegist(physicalAttackRegist)
{
}

int Ogre::GetPhysicalAttackRegist() {
	return _physicalAttackRegist;
}


void Ogre::GetDamage(int attack) {
	cout << "Ogre::GetDamage" << endl;

	int attackValue = attack - _defense - _physicalAttackRegist;

	if (attackValue <= 0) {
		attackValue = 0;
	}

	_health -= attackValue;

	if (_health <= 0) {
		Dead();
	}
}