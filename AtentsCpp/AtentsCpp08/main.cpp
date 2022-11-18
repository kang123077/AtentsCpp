#include <iostream>
#include <string>

using namespace std;

// 동물 농장 시뮬레이션 게임 가정
// 기획상 돼지, 소, 닭 필요

// 부모 클래스인 Stock을 각 클래스에 상속
class Stock {
private:
	string _name;
	float _healthRate; // 건강지수
	float _weight;
	float _age;

public:

	Stock(string name, float healthRate, float weight, float age)
		: _name(name), _healthRate(healthRate), _weight(weight), _age(age) {}

	string GetName() {
		return _name;
	}

	void Speak() {
		cout << _name << "이(가) 말합니다." << endl;
	}

	void Eat() {
		cout << _name << "이(가) 먹습니다." << endl;
	}

	void Run() {
		cout << _name << "이(가) 뜁니다. " << endl;
	}

	void CheckHealth() {
		if (_healthRate <= 100.0f && _healthRate > 80.0f) {
			cout << _name << "의 건강상태가 좋음" << endl;
		}
		else if (_healthRate <= 80.0f && _healthRate > 50) {
			cout << _name << "의 건강상태가 보통" << endl;
		}
	}

	void Info() {
		cout << "\n이름: " << _name << endl;
		cout << "건강상태: " << _healthRate << endl;
		cout << "몸무게: " << _weight << endl;
		cout << "나이: " << _age << endl;
	}
};

class Pig : public Stock {

public:
	Pig(string name, float healthRate, float weight, float age)
		: Stock(name, weight, healthRate, age) {}

	void Speak() {
		cout << GetName() << "가 꿀꿀 웁니다." << endl;
	}
};

class Cow : public Stock {

public:
	Cow(string name, float healthRate, float weight, float age)
		: Stock(name, weight, healthRate, age) {}

	void Speak() {
		cout << GetName() << "가 음머 웁니다." << endl;
	}
};

class Chicken : public Stock {
private:
	bool _isFly;

	void Fly() {
		cout << GetName() << "이 납니다." << endl;
	}

public:
	Chicken(string name, float healthRate, float weight, float age, bool isFly)
		: Stock(name, healthRate, weight, age), _isFly(isFly) {}

	void Speak() {
		cout << GetName() << "이 꼬끼오 합니다." << endl;
	}

	void Run() {
		if (_isFly) {
			Fly();
		}
		else {
			cout << GetName() << "이 뜁니다." << endl;
		}
	}

	void Info() {
		Stock::Info();

		if (_isFly) {
			cout << "나는 닭" << endl;
		}
		else {
			cout << "못나는 닭" << endl;
		}
	}
};

// 부모클래스 덕에 추가가 쉬움
class Dolphin : public Stock {
private:

	void Swimming() {
		cout << GetName() << "이 수영합니다." << endl;
	}

public:
	Dolphin(string name, float healthRate, float weight, float age)
		: Stock(name, healthRate, age, weight) {}

	void Speak() {
		cout << GetName() << "가 웁니다" << endl;
	}

	void Run() {
		Swimming();
	}
};

class Sheep : public Stock {
private:
	bool _woolReady;

	void WoolReady() {
		cout << GetName() << "의 털이 다 자랐습니다" << endl;
	}

public:
	Sheep(string name, float healthRate, float weight, float age, bool woolReady)
		: Stock(name, healthRate, age, weight), _woolReady(woolReady) {}

	void Speak() {
		cout << GetName() << "이 메에 웁니다" << endl;
	}

	void Info() {
		Stock::Info();

		if (_woolReady) {
			cout << "털이 다 자람" << endl;
		}
		else {
			cout << "털이 자라는 중" << endl;
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
		cout << "Parent 기본 생성자" << endl;
	}

	Parent(int value1)
		: _value1(value1), _value2(0)
	{
		cout << "인자를 1개 받는 Parent 생성자" << endl;
	}

	Parent(int value1, int value2)
		: _value1(value1), _value2(value2)
	{
		cout << "인자를 2개 받는 Parent 생성자" << endl;
	}

	~Parent() {
		cout << "Parent 소멸자" << endl;
	}
};

class Child : public Parent {
private:
	int _value3;

public:
	Child()
		:Parent(0, 0), _value3(0)
	{
		cout << "Child 기본 생성자" << endl;
	}

	Child(int value1, int value2, int value3)
		:Parent(value1, value2), _value3(value3)
	{
		cout << "인자를 3개 받는 Child 생성자" << endl;
	}

	Child(int value1)
		:Parent(value1), _value3(0)
	{
		cout << "인자를 1개 받는 Child 생성자" << endl;
	}

	~Child()
	{
		cout << "Child 소멸자" << endl;
	}
};

//int main() {
//	Pig pig("돼지", 80.0f, 200.0f, 2.5f);
//	Cow cow("소", 90.0f, 250.0f, 3.5f);
//	Chicken flyChicken("닭1", 70.0f, 4.0f, 1.2f, true);
//	Chicken notFlyChicken("닭2", 50.0f, 3.5f, 2.2f, false);
//	Dolphin dolphin("돌고", 80.0f, 30.0f, 3.0f);
//	Sheep sheep1("양1", 40.0f, 20.0f, 2.5f, true);
//	Sheep sheep2("양2", 40.0f, 20.0f, 2.5f, false);
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