#pragma once
#include "Monster.h"
#include <string>
class Ogre :
	public Monster
{
private:
	int _physicalAttackRegist;

public:
	Ogre(std::string name, int health, int attack, int defense, int physicalAttackRegist);

	int GetPhysicalAttackRegist();

	void GetDamage(int attack) override;
};

