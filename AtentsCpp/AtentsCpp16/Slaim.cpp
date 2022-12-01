#include "Slaim.h"

Slaim::Slaim(std::string name, int health, int attack, int defense, int physicalAttackRegist)
	: Monster(name, health, attack, defense), _physicalAttackRegist(physicalAttackRegist)
{
}

int Slaim::GetPhysicalAttackRegist() {
	return _physicalAttackRegist;
}

