#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string _name;
	int _age;
	int _grade;
	int _classNum;

	static int Count;      // �����������
public:

	static int GetCount() {   // ��������Լ�, Ŭ���� �Լ�
		// ��������Լ� �ȿ��� ��������� �����ϸ� �� ��
		// (� ����� �������� Ư������ �� ����)
		return Count;
	}

	Student(string name, int age, int grade, int classNum)
		: _name(name), _age(age), _grade(grade), _classNum(classNum)
	{
		Count++;
	}

	~Student() {
		Count--;
	}

	void ShowInfo() {
		cout << "�̸�: " << _name << endl;
		cout << "����: " << _age << endl;
		cout << "�г�: " << _grade << endl;
		cout << "��: " << _classNum << endl;
		cout << "�л���: " << Count << endl << endl;
	}
};

int Student::Count = 0;

class Dragon {
private:
	// ��������� �Ϲ� ������ �����ϱ� ���ؼ�
	// ��������տ� �̴ϼ��� ���̴� ���� �����ϴ�.
	int _health;   // �����
	int _attack;   // ���ݷ�
	int _defense;   // ����

	const int _MAX;   // ����� ����
	int& _refa;   // ������ ����

public:
	Dragon(int health, int attack, int defense, int& refa, int MAX)
		: _health(health), _attack(attack), _defense(defense), _refa(refa), _MAX(MAX)
	{
		// �������� ���ȿ��� ���Կ����ڸ� ���ؼ� �ʱ�ȭ �Ҽ��� �����ϴ�.
		//refa = _health;
		//MAX = 200;
	}
};

class Utillity {
public:
	static int add(int a, int b) {
		return a + b;
	}

	static int sub(int a, int b) {
		return a - b;
	}
};

class Pig {
private:
	string _name;
	float _age;
	float _weight;
	float _healthRate;

public:
	Pig(string name, float age, float weight, float healthRate)
		: _name(name), _age(age), _weight(weight), _healthRate(healthRate) {}

	void ShowInfo() { // ��� �Լ�
		cout << "�̸� : " << this->_name << endl;
		cout << "���� : " << this->_age << endl;
		cout << "���� : " << this->_weight << endl;
		cout << "�ǰ� : " << this->_healthRate << endl;
		cout << "thisPointer : " << this << endl << endl;
	}
};

int main() {
	// ����������� 
	// ������ ��������� ���ÿ� �ʱ�ȭ�� �Ǿ�� �Ѵ�.
	const int MAX = 100; //���������

	cout << "MAX = " << MAX << endl;

	int a = 20;
	int b = 30;

	// ������������
	// ������ ��������� ���ÿ� �ʱ�ȭ �Ǿ���Ѵ�.
	// �ʱ�ȭ �Ǿ ���޵� ������ �ٸ� ������ ����Ű���� ������ �� ����.
	int& refa = a;   // ������ ����

	cout << "refa = " << refa << endl;

	int* pa;

	pa = &a;   // �������� ����

	cout << "*pa = " << *pa << endl;

	pa = &b;

	cout << "*pa = " << *pa << endl;


	Student st1("����", 18, 3, 3);

	// st1.ShowInfo();
	// cout << "student::count = " << Student::Count << endl;
	cout << "Student::Getcount() = " << Student::GetCount() << endl;

	// Count = ������� ������ �ٸ� ������ �����Ѵ�. �ʱ�ȭ�� �ۿ���

	{
		Student st2("����2", 17, 2, 10);

		// st2.ShowInfo();
		// cout << "student::count = " << Student::Count << endl;
		cout << "Student::Getcount() = " << Student::GetCount() << endl;
	}

	Student st3("����3", 16, 1, 11);


	// st3.ShowInfo();
	// cout << "student::count = " << Student::Count << endl;
	cout << "Student::Getcount() = " << Student::GetCount() << endl;


	Utillity util;

	//���� Ŭ���� ���� ���̴� ��� �Ұ���
	cout << a << " + " << b << " = " << util.add(a, b) << endl;

	//���� Ŭ���� ���� ��� ��� ����
	cout << a << " + " << b << " = " << Utillity::sub(a, b) << endl;


	// this �ڱ� ������ ������

	Pig pig("����", 1.8f, 150.0f, 80.0f);

	Pig pig2("����2", 2.8f, 190.0f, 90.0f);

	pig.ShowInfo();

	pig2.ShowInfo();

	return 0;
}