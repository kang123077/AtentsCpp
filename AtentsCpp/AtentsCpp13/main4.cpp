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
		cout << _speed << "�ӵ��� �޸�" << endl;
	}

	void Kick() {
		cout << "�߷� ��" << endl;
	}
};

class Human {
private:
	float _intelligence;

public:
	Human(float intelligence)
		: _intelligence(intelligence) {}

	void HandMaking() {
		cout << "������ ����ϴ�." << endl;
	}

	void Thinking() {
		cout << "������ �մϴ�. " << endl;
	}

	void Punch() {
		cout << "�ָ����� �մϴ�." << endl;
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
		cout << _language << "���� ���Ѵ�." << endl;
	}

};

int main() {

	Centaur centaur(4, 70.0f, 130.0f, "�ѱ���");

	centaur.Attack();
	cout << endl;

	centaur.Run();
	cout << endl;

	centaur.Thinking();

	cout << endl;
	centaur.Speak();



	return 0;
}