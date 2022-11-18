#include <iostream>
#include <string>

using namespace std;

// ���� ���� �ùķ��̼� ���� ����
// ��ȹ�� ����, ��, �� �ʿ�

// �θ� Ŭ������ Stock�� �� Ŭ������ ���
class Stock {
private:
	string _name;
	float _healthRate; // �ǰ�����
	float _weight;
	float _age;

public:

	Stock(string name, float healthRate, float weight, float age)
		: _name(name), _healthRate(healthRate), _weight(weight), _age(age) {}

	string GetName() {
		return _name;
	}

	void Speak() {
		cout << _name << "��(��) ���մϴ�." << endl;
	}

	void Eat() {
		cout << _name << "��(��) �Խ��ϴ�." << endl;
	}

	void Run() {
		cout << _name << "��(��) �ݴϴ�. " << endl;
	}

	void CheckHealth() {
		if (_healthRate <= 100.0f && _healthRate > 80.0f) {
			cout << _name << "�� �ǰ����°� ����" << endl;
		}
		else if (_healthRate <= 80.0f && _healthRate > 50) {
			cout << _name << "�� �ǰ����°� ����" << endl;
		}
	}

	void Info() {
		cout << "\n�̸�: " << _name << endl;
		cout << "�ǰ�����: " << _healthRate << endl;
		cout << "������: " << _weight << endl;
		cout << "����: " << _age << endl;
	}
};

class Pig : public Stock {

public:
	Pig(string name, float healthRate, float weight, float age)
		: Stock(name, weight, healthRate, age) {}

	void Speak() {
		cout << GetName() << "�� �ܲ� ��ϴ�." << endl;
	}
};

class Cow : public Stock {

public:
	Cow(string name, float healthRate, float weight, float age)
		: Stock(name, weight, healthRate, age) {}

	void Speak() {
		cout << GetName() << "�� ���� ��ϴ�." << endl;
	}
};

class Chicken : public Stock {
private:
	bool _isFly;

	void Fly() {
		cout << GetName() << "�� ���ϴ�." << endl;
	}

public:
	Chicken(string name, float healthRate, float weight, float age, bool isFly)
		: Stock(name, healthRate, weight, age), _isFly(isFly) {}

	void Speak() {
		cout << GetName() << "�� ������ �մϴ�." << endl;
	}

	void Run() {
		if (_isFly) {
			Fly();
		}
		else {
			cout << GetName() << "�� �ݴϴ�." << endl;
		}
	}

	void Info() {
		Stock::Info();

		if (_isFly) {
			cout << "���� ��" << endl;
		}
		else {
			cout << "������ ��" << endl;
		}
	}
};

// �θ�Ŭ���� ���� �߰��� ����
class Dolphin : public Stock {
private:

	void Swimming() {
		cout << GetName() << "�� �����մϴ�." << endl;
	}

public:
	Dolphin(string name, float healthRate, float weight, float age)
		: Stock(name, healthRate, age, weight) {}

	void Speak() {
		cout << GetName() << "�� ��ϴ�" << endl;
	}

	void Run() {
		Swimming();
	}
};

class Sheep : public Stock {
private:
	bool _woolReady;

	void WoolReady() {
		cout << GetName() << "�� ���� �� �ڶ����ϴ�" << endl;
	}

public:
	Sheep(string name, float healthRate, float weight, float age, bool woolReady)
		: Stock(name, healthRate, age, weight), _woolReady(woolReady) {}

	void Speak() {
		cout << GetName() << "�� �޿� ��ϴ�" << endl;
	}

	void Info() {
		Stock::Info();

		if (_woolReady) {
			cout << "���� �� �ڶ�" << endl;
		}
		else {
			cout << "���� �ڶ�� ��" << endl;
		}
	}
};

class Parent {
private:
	int _value1;
	int _value2;

public:
	Parent()
	{
		cout << "Parent �⺻ ������" << endl;
	}

	Parent(int value1)
		: _value1(value1), _value2(0)
	{
		cout << "���ڸ� 1�� �޴� Parent ������" << endl;
	}

	Parent(int value1, int value2)
		: _value1(value1), _value2(value2)
	{
		cout << "���ڸ� 2�� �޴� Parent ������" << endl;
	}

	~Parent() {
		cout << "Parent �Ҹ���" << endl;
	}
};

class Child : public Parent {
private:
	int _value3;

public:
	Child()
		:Parent(0, 0), _value3(0)
	{
		cout << "Child �⺻ ������" << endl;
	}

	Child(int value1, int value2, int value3)
		:Parent(value1, value2), _value3(value3)
	{
		cout << "���ڸ� 3�� �޴� Child ������" << endl;
	}

	Child(int value1)
		:Parent(value1), _value3(0)
	{
		cout << "���ڸ� 1�� �޴� Child ������" << endl;
	}

	~Child()
	{
		cout << "Child �Ҹ���" << endl;
	}
};

//int main() {
//	Pig pig("����", 80.0f, 200.0f, 2.5f);
//	Cow cow("��", 90.0f, 250.0f, 3.5f);
//	Chicken flyChicken("��1", 70.0f, 4.0f, 1.2f, true);
//	Chicken notFlyChicken("��2", 50.0f, 3.5f, 2.2f, false);
//	Dolphin dolphin("����", 80.0f, 30.0f, 3.0f);
//	Sheep sheep1("��1", 40.0f, 20.0f, 2.5f, true);
//	Sheep sheep2("��2", 40.0f, 20.0f, 2.5f, false);
//
//
//	pig.Speak();
//	cow.Speak();
//	flyChicken.Speak();
//	notFlyChicken.Speak();
//	dolphin.Speak();
//	sheep1.Speak();
//	sheep2.Speak();
//
//
//	pig.Run();
//	cow.Run();
//	flyChicken.Run();
//	notFlyChicken.Run();
//	dolphin.Run();
//	sheep1.Run();
//	sheep2.Run();
//
//	pig.Info();
//	cow.Info();
//	flyChicken.Info();
//	notFlyChicken.Info();
//	dolphin.Info();
//	sheep1.Info();
//	sheep2.Info();
//
//	Child a;
//
//	Child b(10);
//
//	Child c(20, 30, 40);
//
//	return 0;
//}