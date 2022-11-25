#include <iostream>
#include <string>

using namespace std;

class Horse {
private:
	int _legCount;
	float _speed;

public:
	Horse(int legCount, float speed)
		: _legCount(legCount), _speed(speed) {}

	void Run() {
		cout << _speed << "속도로 달림" << endl;
	}

	void Kick() {
		cout << "발로 참" << endl;
	}
};

class Human {
private:
	float _intelligence;

public:
	Human(float intelligence)
		: _intelligence(intelligence) {}

	void HandMaking() {
		cout << "물건을 만듭니다." << endl;
	}

	void Thinking() {
		cout << "생각을 합니다. " << endl;
	}

	void Punch() {
		cout << "주먹질을 합니다." << endl;
	}
};

class Centaur : private Horse, private Human {
private:
	string _language;

public:
	Centaur(int legCount, float speed, float intelligence, string language)
		: Horse(legCount, speed), Human(intelligence), _language(language) {}

	void Attack() {
		Punch();
		Kick();
	}

	void Run() {
		Horse::Run();
	}

	void Thinking() {
		Human::Thinking();
	}

	void Speak() {
		cout << _language << "언어로 말한다." << endl;
	}

};

int main() {

	Centaur centaur(4, 70.0f, 130.0f, "한국어");

	centaur.Attack();
	cout << endl;

	centaur.Run();
	cout << endl;

	centaur.Thinking();

	cout << endl;
	centaur.Speak();



	return 0;
}