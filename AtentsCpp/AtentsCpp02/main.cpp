#include <iostream>

using namespace std;

class Dragon {
private:
	// 멤버변수와 일반 변수를 구분하기 위해
	// 뭔가 표시를 해 두는 것이 좋다
	int _health;
	int _attack;
	int _defense;

public:
	// 기본 생성자 (인자를 받지 않는 생성자)
	Dragon() {
		cout << "Dragon 기본 생성자" << endl;
		_health = 0;
		_attack = 0;
		_defense = 0;
	}

	// 인자를 받는 생성자
	Dragon(int health, int attack, int defense) {
		cout << "Dragon 인자를 받는 생성자" << endl;
		_health = health;
		_attack = attack;
		_defense = defense;
	}

	// 멤버 함수
	void attack() {
		cout << "attack" << endl;
	}

	// 멤버 함수
	void showinfo() {
		cout << "health : " << _health << endl;
		cout << "attack : " << _attack << endl;
		cout << "defense : " << _defense << endl;
	}
};

int main() {
	// 객체를 만들때 자동으로 호출되어지는 멤버함수가 있습니다.
	// 생성자라고 합니다.
	// 객체는 생성자가 호출되어야지만 온전한 객체로 생성이 됩니다.
	// 생성자를 만들지 않으면 컴파일러가 자동으로 기본 생성자를 
	// 만들어서 포함을 시킵니다.

	Dragon dragonA;   // 기본생성자가 호출되어 객체 생성

	dragonA.attack();

	dragonA.showinfo();

	Dragon dragonB(100, 100, 100);

	dragonB.showinfo();


	return 0;
}