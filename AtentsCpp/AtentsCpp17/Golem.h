#pragma once
#include <string>
#include "Monster.h"


class Golem : public Monster
{
public:
	Golem(std::string name, int health, int attack, int defense);

	void GetDamage(int attack) override;
};

