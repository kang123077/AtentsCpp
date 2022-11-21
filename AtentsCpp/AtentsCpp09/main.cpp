#include <iostream>
#include <string>

using namespace std;

class Parent {
protected:

	int _value;
	int _value2;

public:
	Parent(int value, int value2)   // 생성자
		: _value(value), _value2(value2) {}

	void Init(int value, int value2) {
		_value = value;
		_value2 = value2;
	}

	void ShowInfo() {   // 일반멤버함수
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
	Child1(int value, int value2, int value3, int value4)   // 생성자
		: Parent(value, value2), _value3(value3), _value4(value4) {}


	void Init(int value, int value2, int value3, int value4) {
		_value = value;
		_value2 = value2;
		_value3 = value3;
		_value4 = value4;
	}

	void ShowInfo() {   // 일반 멤버함수
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
		cout << _name << "가 말합니다." << endl;
	}
	void Run() {
		cout << _name << "이 뜁니다." << endl;
	}

	void Eat() {
		cout << _name << "이 먹는다." << endl;
	}

	void Info() {
		cout << "이름: " << _name << endl;
		cout << "몸무게: " << _weight << endl;
		cout << "신장: " << _height << endl;
		cout << "나이: " << _age << endl;
	}
};

class Pig : public Animal {
public:
	Pig(string name, float weight, float height, float age)
		:Animal(0, name, weight, height, age) {}

	void Speak() {
		cout << _name << "가 꿀꿀 웁니다." << endl;
	}
};

class Cow : public Animal {
public:
	Cow(string name, float weight, float height, float age)
		:Animal(1, name, weight, height, age) {}

	void Speak() {
		cout << _name << "가 음머 웁니다." << endl;
	}
};

class Chicken : public Animal {
private:
	bool _isFly;
public:
	Chicken(string name, float weight, float height, float age, bool isFly)
		:Animal(2, name, weight, height, age), _isFly(isFly) {}

	void Speak() {
		cout << _name << "가 꼬꼬 웁니다." << endl;
	}

	void Run() {
		if (_isFly)
			cout << _name << "가 납니다." << endl;
		else
			cout << _name << "가 뜁니다." << endl;
	}
};

class Dolphin : public Animal {
private:
	void Swim() {
		cout << _name << "가 헤엄칩니다." << endl;
	}
public:
	Dolphin(string name, float weight, float height, float age)
		:Animal(3, name, weight, height, age) {}

	void Speak() {
		cout << _name << "가 뀨웅 웁니다." << endl;
	}

	void Run() {
		Swim();
	}
};

void Speak(Animal* pObj)
{
	switch (pObj->GetType())
	{
	case 0: // 돼지
		((Pig*)pObj)->Speak();
		break;
	case 1: // 소
		((Cow*)pObj)->Speak();
		break;
	case 2: // 닭
		((Chicken*)pObj)->Speak();
		break;
	case 3: // 돌고래
		((Dolphin*)pObj)->Speak();
		break;
	}
};

void Run(Animal* pObj) {
	switch (pObj->GetType()) {
	case 0:   // 돼지
		((Pig*)pObj)->Run();
		break;

	case 1:   // 소
		((Cow*)pObj)->Run();
		break;

	case 2:   // 닭
		((Chicken*)pObj)->Run();
		break;

	case 3:   // 돌고래
		((Dolphin*)pObj)->Run();
		break;
	}
};

int main() {

	Parent a(10, 20);
	Child1 b(100, 200, 300, 400);


	//Child1 & ref = a;

	a.ShowInfo();

	// 업캐스팅
	// 부모의 타입으로 자식의 타입을 대입받는 것을 업캐스팅
	a = b;   // 업캐스팅

	a.ShowInfo();

	// 다운캐스팅
	// 자식의 타입으로 부모을 타입에 대입을 하는 경우   
	//b = a;   // 다운캐스팅은 허용이 안됩니다.


	cout << "참조타입인 경우" << endl;

	Parent& refb = b;   // 업캐스팅 : Child1타입의 객체를 Parent 참조형 변수에 대입

	refb.ShowInfo();

	Child1& rrefb = (Child1&)refb;   // 다운 캐스팅: Parent타입 refb 참조형변수를 Child1형 변환해서
							// rrefb 참조형변수에 대입.

	rrefb.ShowInfo();


	cout << "포인터 타입인 경우" << endl;

	b.Init(1000, 2000, 3000, 4000);

	Parent* pb = &b;   // 업캐스팅

	pb->ShowInfo();

	Child1* pbb = (Child1*)pb;   // 다운캐스팅

	pbb->ShowInfo();

	Animal* pArray[5];   // 포인터 배열

	pArray[0] = new Pig("돼지", 180.0f, 150.0f, 2.5f);
	pArray[1] = new Cow("소", 220.0f, 200.0f, 1.8f);
	pArray[2] = new Chicken("못나는 닭", 4.0f, 40.0f, 1.2f, false);
	pArray[3] = new Chicken("나는 닭", 3.5f, 40.0f, 1.2f, true);
	pArray[4] = new Dolphin("돌고래", 200.0f, 200.0f, 3.5f);

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