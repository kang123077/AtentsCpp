#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string _name;
	int _age;
	int _grade;
	int _classNum;

	static int Count;      // 정적멤버변수
public:

	static int GetCount() {   // 정적멤버함수, 클래스 함수
		// 정적멤버함수 안에서 멤버변수에 접근하면 안 됨
		// (어떤 멤버의 변수인지 특정지을 수 없음)
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
		cout << "이름: " << _name << endl;
		cout << "나이: " << _age << endl;
		cout << "학년: " << _grade << endl;
		cout << "반: " << _classNum << endl;
		cout << "학생수: " << Count << endl << endl;
	}
};

int Student::Count = 0;

class Dragon {
private:
	// 멤버변수와 일반 변수를 구분하기 위해서
	// 멤버변수앞에 이니셜을 붙이는 것이 좋습니다.
	int _health;   // 생명력
	int _attack;   // 공격력
	int _defense;   // 방어력

	const int _MAX;   // 상수형 변수
	int& _refa;   // 참조형 변수

public:
	Dragon(int health, int attack, int defense, int& refa, int MAX)
		: _health(health), _attack(attack), _defense(defense), _refa(refa), _MAX(MAX)
	{
		// 생성자의 블럭안에서 대입연산자를 통해서 초기화 할수가 없습니다.
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

	void ShowInfo() { // 멤버 함수
		cout << "이름 : " << this->_name << endl;
		cout << "나이 : " << this->_age << endl;
		cout << "무게 : " << this->_weight << endl;
		cout << "건강 : " << this->_healthRate << endl;
		cout << "thisPointer : " << this << endl << endl;
	}
};

int main() {
	// 상수형변수는 
	// 변수가 만들어짐과 동시에 초기화가 되어야 한다.
	const int MAX = 100; //상수형변수

	cout << "MAX = " << MAX << endl;

	int a = 20;
	int b = 30;

	// 참조형변수는
	// 변수가 만들어짐과 동시에 초기화 되어야한다.
	// 초기화 되어서 전달된 변수를 다른 변수를 가르키도록 변경할 수 없다.
	int& refa = a;   // 참조형 변수

	cout << "refa = " << refa << endl;

	int* pa;

	pa = &a;   // 포인터형 변수

	cout << "*pa = " << *pa << endl;

	pa = &b;

	cout << "*pa = " << *pa << endl;


	Student st1("몬스터", 18, 3, 3);

	// st1.ShowInfo();
	// cout << "student::count = " << Student::Count << endl;
	cout << "Student::Getcount() = " << Student::GetCount() << endl;

	// Count = 정적멤버 변수는 다른 멤버들과 공유한다. 초기화도 밖에서

	{
		Student st2("몬스터2", 17, 2, 10);

		// st2.ShowInfo();
		// cout << "student::count = " << Student::Count << endl;
		cout << "Student::Getcount() = " << Student::GetCount() << endl;
	}

	Student st3("몬스터3", 16, 1, 11);


	// st3.ShowInfo();
	// cout << "student::count = " << Student::Count << endl;
	cout << "Student::Getcount() = " << Student::GetCount() << endl;


	Utillity util;

	//위에 클래스 선언 없이는 사용 불가능
	cout << a << " + " << b << " = " << util.add(a, b) << endl;

	//위에 클래스 선언 없어도 사용 가능
	cout << a << " + " << b << " = " << Utillity::sub(a, b) << endl;


	// this 자기 참조형 포인터

	Pig pig("돼지", 1.8f, 150.0f, 80.0f);

	Pig pig2("돼지2", 2.8f, 190.0f, 90.0f);

	pig.ShowInfo();

	pig2.ShowInfo();

	return 0;
}