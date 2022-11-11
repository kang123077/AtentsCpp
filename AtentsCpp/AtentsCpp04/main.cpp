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
	Car() // Car 기본생성자
		: _name(""), _wheelCount(1), _speed(1), _isCargo(1) {}

	Car(string name, int wheelCount, float speed, bool isCargo) // Car 인자생성자
		: _name(name), _wheelCount(wheelCount), _speed(speed), _isCargo(isCargo) {}
	
	void Init(string name, int wheelCount, float speed, bool isCargo) {
		_name = name;
		_wheelCount = wheelCount;
		_speed = speed;
		_isCargo = isCargo;
	}

	void Accel() {
		_speed += 0.5f;
		cout << _speed << "로 속도 증가" << endl;
	}

	void Break() {
		_speed -= 0.5f;
		cout << _speed << "로 속도 감소" << endl;
	}

	void ShowStatus() {
		cout << _name << "차의 현재 속도는 " << _speed << " 이고 바퀴의 갯수는 " << _wheelCount << " 짐칸은 ";
		if (_isCargo) {
			cout << "있음" << endl;
		}
		else
			cout << "없음" << endl;
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
		cout << "Student 기본 생성자" << endl;
	}

	Student(string name, int age, int grade, int classNum)
		: _name(name), _age(age), _grade(grade), _classNum(classNum)
	{
		cout << "Student 인자를 받는 생성자" << endl;
	}

	void Init(string name, int age, int grade, int classNum) {
		_name = name;
		_age = age;
		_grade = grade;
		_classNum = classNum;
	}

	~Student() {
		cout << "Student 소멸자" << endl;
	}

	void ShowInfo() {
		cout << "이름: " << _name << endl;
		cout << "나이: " << _age << endl;
		cout << "학년: " << _grade << endl;
		cout << "반: " << _classNum << endl;
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
		//cout << "Monster 기본생성자" << endl;
	}

	Monster(int health, int attack, int defense, int speed)
		: _health(health), _attack(attack), _defense(defense), _speed(speed)
	{
		//cout << "Monster 생성자" << endl;
	}

	~Monster() {
		//cout << "Monster 소멸자" << endl;
	}

	void Init(int health, int attack, int defense, int speed) {
		_health = health;
		_attack = attack;
		_defense = defense;
		_speed = speed;
	}

	void Attack() {
		cout << _attack << "의 공격력으로 공격" << endl;
	}

	void Run() {
		cout << _speed << "의 속도로 달린다." << endl;
	}

	void ShowInfo() {
		cout << "생명력: " << _health << endl;
		cout << "공격력: " << _attack << endl;
		cout << "방어력: " << _defense << endl;
		cout << "속도: " << _speed << endl;
	}
};



// c언어에서는 동일한 이름의 함수 못만듬
// c++에서는 가능
// 내부적으로 사용할 함수 이름을 네이밍 할 때
// 함수명과 매개변수의 데이터타입, 갯수를 표현한다
// 이 네이밍 방법을 네임맹글링이라고 한다
// 동일한 함수명을 사용하는 것을 overloading이라고 한다

int add(int a, int b) {
	return a + b;
}

// float add(int a, int b) {
// 	return a + b;
// } 얘처럼 매개변수도 같으면 에러 뜸

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


	//동적객체 
	// 동적 객체를 만들때는 new 연산자를 사용해야합니다.
	// new 연산자는 생성자를 호출 시켜 줍니다.
	Student* pa = new Student; // 동적 객체 할당
	// 주소값으로 객체의 멤버에 접근할때는 ->(화살표연산자)를 사용합니다.
	pa->Init("monster", 11, 1, 10);

	pa->ShowInfo();

	delete pa;   // 동적객체 할당된 메모리 반납.

	pa = new Student("monster2", 18, 2, 5);   // 인자를 받는 생성자를 호출하여 동적객체를 생성

	pa->ShowInfo();

	delete pa;   // 동적객체 반납.


	int count = 0;
	char buff[100];

	cout << "필요한 차의 갯수를 입력하세요 : " << endl;
	cin >> count;

	Car* parray = new Car[count]; // 동적 객체 배열

	// 기본 생성자와 init함수를 직접 만들어서 출력

	for (int i = 0; i < count; i++) {
		sprintf(buff, "monster_%d", i);
		parray[i].Init(buff, i, i, i);
	}

	// 자동차를 작동
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

	delete[] parray;   // 배열을 반환처리할때는 delete[] 연산자를 사용합니다.

	return 0;
}