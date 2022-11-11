#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Math {
public:
	float div(int a, int b) {
		cout << "div(int, int)" << endl;
		return a / b;
	}

	float div(float a, float b) {
		cout << "div(float, float)" << endl;
		return a / b;
	}

	double div(double a, double b) {
		cout << "div(double, double)" << endl;
		return a / b;
	}

	int mul(int a, int b) {
		return a * b;
	}

	float mul(float a, float b) {
		return a * b;
	}
};

class Car {
private:
	string	_name;
	int		_wheelCount;
	float	_speed;
	bool	_isCargo;
public:
	Car() // Car �⺻������
		: _name(""), _wheelCount(1), _speed(1), _isCargo(1) {}

	Car(string name, int wheelCount, float speed, bool isCargo) // Car ���ڻ�����
		: _name(name), _wheelCount(wheelCount), _speed(speed), _isCargo(isCargo) {}
	
	void Init(string name, int wheelCount, float speed, bool isCargo) {
		_name = name;
		_wheelCount = wheelCount;
		_speed = speed;
		_isCargo = isCargo;
	}

	void Accel() {
		_speed += 0.5f;
		cout << _speed << "�� �ӵ� ����" << endl;
	}

	void Break() {
		_speed -= 0.5f;
		cout << _speed << "�� �ӵ� ����" << endl;
	}

	void ShowStatus() {
		cout << _name << "���� ���� �ӵ��� " << _speed << " �̰� ������ ������ " << _wheelCount << " ��ĭ�� ";
		if (_isCargo) {
			cout << "����" << endl;
		}
		else
			cout << "����" << endl;
	}
};

class Student {
private:
	string _name;
	int _age;
	int _grade;
	int _classNum;


public:
	Student()
		: _name(""), _age(1), _grade(1), _classNum(1)
	{
		cout << "Student �⺻ ������" << endl;
	}

	Student(string name, int age, int grade, int classNum)
		: _name(name), _age(age), _grade(grade), _classNum(classNum)
	{
		cout << "Student ���ڸ� �޴� ������" << endl;
	}

	void Init(string name, int age, int grade, int classNum) {
		_name = name;
		_age = age;
		_grade = grade;
		_classNum = classNum;
	}

	~Student() {
		cout << "Student �Ҹ���" << endl;
	}

	void ShowInfo() {
		cout << "�̸�: " << _name << endl;
		cout << "����: " << _age << endl;
		cout << "�г�: " << _grade << endl;
		cout << "��: " << _classNum << endl;
	}
};


class Monster {
private:
	int _health;
	int _attack;
	int _defense;
	int _speed;


public:
	Monster()
		: _health(0), _attack(0), _defense(0), _speed(10)
	{
		//cout << "Monster �⺻������" << endl;
	}

	Monster(int health, int attack, int defense, int speed)
		: _health(health), _attack(attack), _defense(defense), _speed(speed)
	{
		//cout << "Monster ������" << endl;
	}

	~Monster() {
		//cout << "Monster �Ҹ���" << endl;
	}

	void Init(int health, int attack, int defense, int speed) {
		_health = health;
		_attack = attack;
		_defense = defense;
		_speed = speed;
	}

	void Attack() {
		cout << _attack << "�� ���ݷ����� ����" << endl;
	}

	void Run() {
		cout << _speed << "�� �ӵ��� �޸���." << endl;
	}

	void ShowInfo() {
		cout << "�����: " << _health << endl;
		cout << "���ݷ�: " << _attack << endl;
		cout << "����: " << _defense << endl;
		cout << "�ӵ�: " << _speed << endl;
	}
};



// c������ ������ �̸��� �Լ� ������
// c++������ ����
// ���������� ����� �Լ� �̸��� ���̹� �� ��
// �Լ���� �Ű������� ������Ÿ��, ������ ǥ���Ѵ�
// �� ���̹� ����� ���Ӹͱ۸��̶�� �Ѵ�
// ������ �Լ����� ����ϴ� ���� overloading�̶�� �Ѵ�

int add(int a, int b) {
	return a + b;
}

// float add(int a, int b) {
// 	return a + b;
// } ��ó�� �Ű������� ������ ���� ��

float add(float a, float b) {
	return a + b;
}

int main() {
	int a = 20;
	int b = 30;
	float c = 1.2f;
	float d = 3.4f;

	int ret = add(a, b); // call addXX

	cout << a << " + " << b << " = " << ret << endl;

	float fret = add(c, d); // call addYY

	cout << c << " + " << d << " = " << fret << endl;


	Math math;

	double e = 100.234;
	double f = 50.234;

	cout << a << " / " << b << " = " << math.div(a, b) << endl;
	cout << c << " / " << d << " = " << math.div(c, d) << endl;
	cout << e << " / " << f << " = " << math.div(e, f) << endl;
	cout << c << " x " << d << " = " << math.mul(c, d) << endl;

	Monster Marray[10];

	int length = sizeof(Marray) / sizeof(Monster);

	for (int i = 0; i < length; i++) {
		Marray[i].Init(i, i, i, i);
	}

	for (int i = 0; i < length; i++) {
		Marray[i].ShowInfo();
	}

	for (int i = 0; i < length; i++) {
		Marray[i].Attack();
	}

	for (int i = 0; i < length; i++) {
		Marray[i].Run();
	}

	Student st;


	//������ü 
	// ���� ��ü�� ���鶧�� new �����ڸ� ����ؾ��մϴ�.
	// new �����ڴ� �����ڸ� ȣ�� ���� �ݴϴ�.
	Student* pa = new Student; // ���� ��ü �Ҵ�
	// �ּҰ����� ��ü�� ����� �����Ҷ��� ->(ȭ��ǥ������)�� ����մϴ�.
	pa->Init("monster", 11, 1, 10);

	pa->ShowInfo();

	delete pa;   // ������ü �Ҵ�� �޸� �ݳ�.

	pa = new Student("monster2", 18, 2, 5);   // ���ڸ� �޴� �����ڸ� ȣ���Ͽ� ������ü�� ����

	pa->ShowInfo();

	delete pa;   // ������ü �ݳ�.


	int count = 0;
	char buff[100];

	cout << "�ʿ��� ���� ������ �Է��ϼ��� : " << endl;
	cin >> count;

	Car* parray = new Car[count]; // ���� ��ü �迭

	// �⺻ �����ڿ� init�Լ��� ���� ���� ���

	for (int i = 0; i < count; i++) {
		sprintf(buff, "monster_%d", i);
		parray[i].Init(buff, i, i, i);
	}

	// �ڵ����� �۵�
	for (int i = 0; i < count; i++) {
		parray[i].Accel();
	}

	for (int i = 0; i < count; i++) {
		parray[i].ShowStatus();
	}


	for (int i = 0; i < count; i++) {
		parray[i].Break();
	}

	for (int i = 0; i < count; i++) {
		parray[i].ShowStatus();
	}

	delete[] parray;   // �迭�� ��ȯó���Ҷ��� delete[] �����ڸ� ����մϴ�.

	return 0;
}