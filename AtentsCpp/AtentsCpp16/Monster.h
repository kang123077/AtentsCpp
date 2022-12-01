#pragma once
#include <string>

class Monster
{
private:
	std::string _name;	// 이름
	int _health;	// 생명력
	int _attack;	// 공격력
	int _defense;	// 방어력

public:
	Monster(std::string name, int health, int attack, int defense);

	int GetHealth();
	void SetHealth(int value);
	int GetDefense();
	std::string GetName();


	void Attack(Monster& enemy);

	void Defense();
	void Run();
	void ShowInfo();
};

