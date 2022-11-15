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
	cout << "공격" << endl;
}

void Monster::info() {
	cout << "생명력: " << _health << endl;
	cout << "공격력: " << _attack << endl;
	cout << "방어력: " << _defense << endl;
}