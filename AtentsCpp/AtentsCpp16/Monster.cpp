#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(std::string name, int health, int attack, int defense)
	: _name(name), _health(health), _attack(attack), _defense(defense) {}


int Monster::GetHealth() {
	return _health;
}

void Monster::SetHealth(int value) {
	_health = value;
}
int Monster::GetDefense() {
	return _defense;
}

std::string Monster::GetName() {
	return _name;
}

void Monster::Attack(Monster& enemy) {
	enemy._health -= (_attack - enemy._defense);

	cout << _name << "이 " << enemy._name << "을 공격해서 생명력이 " << enemy._health << "로 줄었다" << endl;
}

void Monster::Defense() {
	cout << "방어를 합니다." << endl;
}

void Monster::Run() {
	cout << "뜁니다." << endl;
}

void Monster::ShowInfo() {
	cout << "이름: " << _name << endl;
	cout << "생명력: " << _health << endl;
	cout << "방어력: " << _defense << endl;
	cout << "공격력: " << _attack << endl;
}