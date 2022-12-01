#include "Monster.h"
#include "Slime.h"
#include "Ogre.h"
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

/*
void Monster::GetDamage(int attack) {

	cout << "Monster::GetDamage" << endl;
	_health -= (attack - _defense);

	if (_health <= 0) {
		Dead();
	}
}
*/

void Monster::Attack(Monster& enemy) {
	cout << "Monster Attack " << endl;
	//enemy._health -= (_attack - enemy._defense);

	enemy.GetDamage(_attack);

	cout << _name << "�� " << enemy._name << "�� �����ؼ� ������� " << enemy._health << "�� �پ���" << endl;
}

void Monster::Defense() {
	cout << "�� �մϴ�." << endl;
}

void Monster::Run() {
	cout << "�ݴϴ�." << endl;
}

void Monster::Dead() {
	cout << _name << "�� �������." << endl;
}

void Monster::ShowInfo() {
	cout << "�̸�: " << _name << endl;
	cout << "�����: " << _health << endl;
	cout << "����: " << _defense << endl;
	cout << "���ݷ�: " << _attack << endl;
}