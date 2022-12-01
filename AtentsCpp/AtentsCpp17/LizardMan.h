#pragma once
#include "Monster.h"
#include <string>

class LizardMan :
	public Monster
{
private:
	int _physicalAttackRegist;

public:
	LizardMan(std::string name, int health, int attack, int defense, int physicalAttackRegist);

	int GetPhysicalAttackRegist();

	void GetDamage(int attack) override;
};

