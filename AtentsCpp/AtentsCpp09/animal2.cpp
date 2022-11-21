#include <iostream>
#include <string>

using namespace std;
// ���� �ù�
// ����, ��, ��

class Animal {
protected:
	string _name;
	float _weight;
	float _height;
	float _age;

public:
	Animal(string name, float weight, float height, float age)
		: _name(name), _weight(weight), _height(height), _age(age) {}

	void Speak() {
		cout << _name << "��(��) ��ϴ�." << endl;
	}

	void Run() {
		cout << _name << "��(��) �ݴϴ�." << endl;
	}

	void Eat() {
		cout << _name << "��(��) �Խ��ϴ�." << endl;
	}

	void Info() {
		cout << "�̸� : " << _name << endl;
		cout << "������ : " << _weight << endl;
		cout << "���� : " << _height << endl;
		cout << "���� : " << _age << endl;
	}
};

class Pig : public Animal {
public:
	Pig(string name, float weight, float height, float age)
		:Animal(name, weight, height, age) {}

	void Speak() {
		cout << _name << "��(��) �ܲ� ��ϴ�." << endl;
	}
};

class Cow : public Animal {
public:
	Cow(string name, float weight, float height, float age)
		:Animal(name, weight, height, age) {}

	void Speak() {
		cout << _name << "��(��) ���� ��ϴ�." << endl;
	}
};

class Chicken : public Animal {
private:
	bool _isFly;

	void Fly() {
		if (_isFly)
			cout << _name << "��(��) ���ϴ�." << endl;
		else
			cout << _name << "��(��) �ݴϴ�." << endl;
	}

public:
	Chicken(string name, float weight, float height, float age, bool isFly)
		:Animal(name, weight, height, age), _isFly(isFly) {}

	void Run() {
		Fly();
	}

	void Speak() {
		cout << _name << "��(��) ���� ��ϴ�." << endl;
	}
};

class Dolphin : public Animal {
private:
	bool _isSwim;

	void Swim() {
		cout << _name << "��(��) ���Ĩ�ϴ�." << endl;
	}
public:
	Dolphin(string name, float weight, float height, float age, bool isSwim)
		:Animal(name, weight, height, age), _isSwim(isSwim) {}

	void Run() {
		Swim();
	}

	void Speak() {
		cout << _name << "��(��) ��� ��ϴ�." << endl;
	}
};

//int main() {
//
//	Pig pig("����", 180.0f, 150.0f, 2.5f);
//	Cow cow("��", 220.0f, 200.0f, 1.8f);
//	Chicken notFlyChicken("������ ��", 4.0f, 40.0f, 1.2f, false);
//	Chicken FlyChicken("���� ��", 3.5f, 40.0f, 1.2f, true);
//	Dolphin SwimDolphin("����", 3.5f, 40.0f, 1.2f, true);
//
//	pig.Speak();
//	cow.Speak();
//	notFlyChicken.Speak();
//	FlyChicken.Speak();
//	SwimDolphin.Speak();
//
//	cout << endl;
//
//	pig.Run();
//	cow.Run();
//	notFlyChicken.Run();
//	FlyChicken.Run();
//	SwimDolphin.Run();
//
//	return 0;
//}