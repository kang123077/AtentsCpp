#include <iostream>
#include "Monster.h"

using namespace std;

class Human {
private:
	string _name;
	int _age;
	float _runSpeed;

public:
	Human(string name, int age, float runSpeed)
		: _name(name), _age(age), _runSpeed(runSpeed) {}

	float GetRunSpeed() const {
		return _runSpeed;
	}

	string GetName() const {
		return _name;
	}

	void Info() {
		cout << "이름: " << _name << endl;
		cout << "나이: " << _age << endl;
		cout << "달리기 속도: " << _runSpeed << endl;
	}
};
// const 매개변수로 전달된 객체는 const 함수만 호출이 가능하다
void PrintRunSpeed(const Human& ref) {
	//ref.SetAge(20);
	cout << ref.GetName() << "의 달리기 속도는 " << ref.GetRunSpeed() << "입니다." << endl;
}

class A {
private:
	int _value;
	int _value2;

public:
	A(int value, int value2)
		: _value(value), _value2(value2) {}
};

class DynamicArray {
private:
	int* _parr;
	int _size;

public:
	DynamicArray(int size)
		: _size(size) {
		_parr = new int[_size];
	}


	DynamicArray(DynamicArray& ref) {
		// 복사생성자 (자기타입을 인자로받는 생성자)
		cout << "DynamicArray Copy Constructor" << endl;

		_size = ref._size;

		_parr = new int[_size];

		for (int i = 0; i < _size; i++) {
			_parr[i] = ref._parr[i];
		}
	}


	~DynamicArray() {
		delete[] _parr;
	}

	int GetSize() {
		return _size;
	}

	void SetValue(int index, int value) {
		_parr[index] = value;
	}

	int GetIndex(int index) {
		return _parr[index];
	}

};
int main() {
	DynamicArray array(10);

	for (int i = 0; i < array.GetSize(); i++) {
		array.SetValue(i, i * 3);
	}

	DynamicArray array2(array);   // 복사생성자
	//DynamicArray array2 = array;

	array2.SetValue(5, 10000);

	cout << "array" << endl;
	for (int i = 0; i < array.GetSize(); i++) {
		cout << "array[" << i << "] = " << array.GetIndex(i) << endl;
	}
	cout << endl;

	cout << "array2" << endl;
	for (int i = 0; i < array2.GetSize(); i++) {
		cout << "array2[" << i << "] = " << array2.GetIndex(i) << endl;
	}   
	
	Monster mons(100, 30, 40);

	mons.SetHealth(200);

	//mons._health = 200;

	mons.Attack();
	mons.info();

	Human human("손흥민", 32, 9.8f);

	const Human human2("손", 32, 9.8f);

	PrintRunSpeed(human);

	return 0;


}