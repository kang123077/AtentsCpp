#pragma once
#include <string>

class Slime;
class Ogre;

// ���������Լ��� �ϳ��� �ִ� Ŭ������ �߻�Ŭ����
// �߻�Ŭ������ �ڽ��� ��ü�� ����� �ִ� �ɷ��� ���
// �ڽ��� �ڽĵ��� ���������Լ��� �����ϵ��� ������ �� �ֽ��ϴ�.
class Monster
{
protected:
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

	virtual void GetDamage(int attack) = 0;	// ������ ó�� �����Լ� (���������Լ�)


	void Attack(Monster& enemy);	

	void Defense();
	void Run();
	void Dead();

	void ShowInfo();
};

