#pragma once
#include <string>

class Monster
{
private:
	std::string _name;	// �̸�
	int _health;	// �����
	int _attack;	// ���ݷ�
	int _defense;	// ����

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

