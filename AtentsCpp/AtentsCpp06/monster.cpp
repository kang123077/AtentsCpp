#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(int health, int attack, int defense)
	: _health(health), _attack(attack), _defense(defense) {
}

int Monster::GetHealth() {
	return _health;
}

void Monster::Attack() {
	cout << "����" << endl;
}

void Monster::info() {
	cout << "�����: " << _health << endl;
	cout << "���ݷ�: " << _attack << endl;
	cout << "����: " << _defense << endl;
}