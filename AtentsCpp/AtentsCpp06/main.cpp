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
		cout << "�̸�: " << _name << endl;
		cout << "����: " << _age << endl;
		cout << "�޸��� �ӵ�: " << _runSpeed << endl;
	}
};
// const �Ű������� ���޵� ��ü�� const �Լ��� ȣ���� �����ϴ�
void PrintRunSpeed(const Human& ref) {
	//ref.SetAge(20);
	cout << ref.GetName() << "�� �޸��� �ӵ��� " << ref.GetRunSpeed() << "�Դϴ�." << endl;
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
		// ��������� (�ڱ�Ÿ���� ���ڷι޴� ������)
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

	DynamicArray array2(array);   // ���������
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

	Human human("�����", 32, 9.8f);

	const Human human2("��", 32, 9.8f);

	PrintRunSpeed(human);

	return 0;


}