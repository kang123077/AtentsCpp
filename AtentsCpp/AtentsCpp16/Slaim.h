#pragma once
#include <string>
#include "Monster.h"



class Slaim : public Monster {
private:
	int _physicalAttackRegist;	// �������� ���׷�

public:
	Slaim(std::string name, int health, int attack, int defense, int physicalAttackRegist);

	int GetPhysicalAttackRegist();
};