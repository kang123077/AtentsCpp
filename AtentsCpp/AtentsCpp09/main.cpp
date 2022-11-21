#include <iostream>
#include <string>

using namespace std;

class Parent {
protected:

	int _value;
	int _value2;

public:
	Parent(int value, int value2)   // ������
		: _value(value), _value2(value2) {}

	void Init(int value, int value2) {
		_value = value;
		_value2 = value2;
	}

	void ShowInfo() {   // �Ϲݸ���Լ�
		cout << "Parent::ShowInfo" << endl;
		cout << "_value = " << _value << endl;
		cout << "_value2 = " << _value2 << endl << endl;
	}
};

class Child1 : public Parent {
private:
	int _value3;
	int _value4;

public:
	Child1(int value, int value2, int value3, int value4)   // ������
		: Parent(value, value2), _value3(value3), _value4(value4) {}


	void Init(int value, int value2, int value3, int value4) {
		_value = value;
		_value2 = value2;
		_value3 = value3;
		_value4 = value4;
	}

	void ShowInfo() {   // �Ϲ� ����Լ�
		cout << "Child1::ShowInfo" << endl;
		cout << "_value = " << _value << endl;
		cout << "_value2 = " << _value2 << endl;
		cout << "_value3 = " << _value3 << endl;
		cout << "_value4 = " << _value4 << endl << endl;
	}
};

class Animal {
protected:
	int _type;
	string _name;
	float _weight;
	float _height;
	float _age;

public:
	Animal(int type, string name, float weight, float height, float age)
		:_type(type), _name(name), _weight(weight), _height(height), _age(age) {}

	int GetType() {
		return _type;
	}

	void Speak() {
		cout << _name << "�� ���մϴ�." << endl;
	}
	void Run() {
		cout << _name << "�� �ݴϴ�." << endl;
	}

	void Eat() {
		cout << _name << "�� �Դ´�." << endl;
	}

	void Info() {
		cout << "�̸�: " << _name << endl;
		cout << "������: " << _weight << endl;
		cout << "����: " << _height << endl;
		cout << "����: " << _age << endl;
	}
};

class Pig : public Animal {
public:
	Pig(string name, float weight, float height, float age)
		:Animal(0, name, weight, height, age) {}

	void Speak() {
		cout << _name << "�� �ܲ� ��ϴ�." << endl;
	}
};

class Cow : public Animal {
public:
	Cow(string name, float weight, float height, float age)
		:Animal(1, name, weight, height, age) {}

	void Speak() {
		cout << _name << "�� ���� ��ϴ�." << endl;
	}
};

class Chicken : public Animal {
private:
	bool _isFly;
public:
	Chicken(string name, float weight, float height, float age, bool isFly)
		:Animal(2, name, weight, height, age), _isFly(isFly) {}

	void Speak() {
		cout << _name << "�� ���� ��ϴ�." << endl;
	}

	void Run() {
		if (_isFly)
			cout << _name << "�� ���ϴ�." << endl;
		else
			cout << _name << "�� �ݴϴ�." << endl;
	}
};

class Dolphin : public Animal {
private:
	void Swim() {
		cout << _name << "�� ���Ĩ�ϴ�." << endl;
	}
public:
	Dolphin(string name, float weight, float height, float age)
		:Animal(3, name, weight, height, age) {}

	void Speak() {
		cout << _name << "�� ��� ��ϴ�." << endl;
	}

	void Run() {
		Swim();
	}
};

void Speak(Animal* pObj)
{
	switch (pObj->GetType())
	{
	case 0: // ����
		((Pig*)pObj)->Speak();
		break;
	case 1: // ��
		((Cow*)pObj)->Speak();
		break;
	case 2: // ��
		((Chicken*)pObj)->Speak();
		break;
	case 3: // ����
		((Dolphin*)pObj)->Speak();
		break;
	}
};

void Run(Animal* pObj) {
	switch (pObj->GetType()) {
	case 0:   // ����
		((Pig*)pObj)->Run();
		break;

	case 1:   // ��
		((Cow*)pObj)->Run();
		break;

	case 2:   // ��
		((Chicken*)pObj)->Run();
		break;

	case 3:   // ����
		((Dolphin*)pObj)->Run();
		break;
	}
};

int main() {

	Parent a(10, 20);
	Child1 b(100, 200, 300, 400);


	//Child1 & ref = a;

	a.ShowInfo();

	// ��ĳ����
	// �θ��� Ÿ������ �ڽ��� Ÿ���� ���Թ޴� ���� ��ĳ����
	a = b;   // ��ĳ����

	a.ShowInfo();

	// �ٿ�ĳ����
	// �ڽ��� Ÿ������ �θ��� Ÿ�Կ� ������ �ϴ� ���   
	//b = a;   // �ٿ�ĳ������ ����� �ȵ˴ϴ�.


	cout << "����Ÿ���� ���" << endl;

	Parent& refb = b;   // ��ĳ���� : Child1Ÿ���� ��ü�� Parent ������ ������ ����

	refb.ShowInfo();

	Child1& rrefb = (Child1&)refb;   // �ٿ� ĳ����: ParentŸ�� refb ������������ Child1�� ��ȯ�ؼ�
							// rrefb ������������ ����.

	rrefb.ShowInfo();


	cout << "������ Ÿ���� ���" << endl;

	b.Init(1000, 2000, 3000, 4000);

	Parent* pb = &b;   // ��ĳ����

	pb->ShowInfo();

	Child1* pbb = (Child1*)pb;   // �ٿ�ĳ����

	pbb->ShowInfo();

	Animal* pArray[5];   // ������ �迭

	pArray[0] = new Pig("����", 180.0f, 150.0f, 2.5f);
	pArray[1] = new Cow("��", 220.0f, 200.0f, 1.8f);
	pArray[2] = new Chicken("������ ��", 4.0f, 40.0f, 1.2f, false);
	pArray[3] = new Chicken("���� ��", 3.5f, 40.0f, 1.2f, true);
	pArray[4] = new Dolphin("����", 200.0f, 200.0f, 3.5f);

	/*
	pig.Speak();
	cow.Speak();
	notFlyChicken.Speak();
	FlyChicken.Speak();
	dolphin.Speak();
	*/

	for (int i = 0; i < 5; i++) {
		Speak(pArray[i]);
	}

	cout << endl;

	/*
	pig.Run();
	cow.Run();
	notFlyChicken.Run();
	FlyChicken.Run();
	dolphin.Run();
	*/

	for (int i = 0; i < 5; i++) {
		Run(pArray[i]);
	}

	for (int i = 0; i < 5; i++) {
		delete pArray[i];
	}

	delete pArray;

	return 0;
}