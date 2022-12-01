#pragma once
#include <string>

class Slime;
class Ogre;

// 순수가상함수가 하나라도 있는 클래스를 추상클래스
// 추상클래스는 자신의 객체를 만들수 있는 능력이 상실
// 자신의 자식들이 순수가상함수를 구현하도록 강제할 수 있습니다.
class Monster
{
protected:
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

	virtual void GetDamage(int attack) = 0;	// 데미지 처리 가상함수 (순수가상함수)


	void Attack(Monster& enemy);	

	void Defense();
	void Run();
	void Dead();

	void ShowInfo();
};

