#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class DynamicArray {
private:
	int* _parr;
	int _size;

public:
	DynamicArray(int size)
		: _size(size) {
		_parr = new int[_size];
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


class Bus {
private:
	string _Num;
	int _sitCount;
	int _doorCount;
	int _currentSpeed;

public:
	Bus()
		:_Num(""), _sitCount(48), _doorCount(2), _currentSpeed(0) {};

	Bus(string Num, int sitCount, int doorCount, int currentSpeed)
		: _Num(Num), _sitCount(sitCount), _doorCount(doorCount), _currentSpeed(currentSpeed) {};

	void Init(string Num, int sitCount, int doorCount) {
		_Num = Num;
		_sitCount = sitCount;
		_doorCount = doorCount;
		_currentSpeed = 0;
	}

	int GetCurrentSpeed() {
		return _currentSpeed;
	}

	void Drive() {
		cout << _currentSpeed << " DRIVE" << endl;
	}
	void Accel() {
		_currentSpeed++;
		cout << " ACCEL" << endl;
	}
	void Break() {
		_currentSpeed--;

		if (_currentSpeed > 0) {
			cout << _currentSpeed << " �ӵ��� ����" << endl;
		}
		else {
			_currentSpeed = 0;
			cout << "���� ����" << endl;
		}
	}

	void info() {
		cout << "BusNum : " << _Num << endl;
		cout << "SitNum : " << _Num << endl;
		cout << "DoorNum : " << _Num << endl;
		cout << "CurrentSpeed : " << _Num << endl;
	}
};

int main() {
	//int busCount = 0;
	//char buff[100];   // �̸� �����

	//cout << "���� ���� ����� �Է��ϼ���: ";
	//cin >> busCount;

	//Bus* pbus = new Bus[busCount];   // ���� ��ü �迭 ����

	//for (int i = 0; i < busCount; i++) {
	//	sprintf(buff, "%d", i % busCount + 700);
	//	pbus[i].Init(buff, i % 5 + 40, i % 2 + 1);
	//}

	//for (int i = 0; i < busCount; i++) {
	//	for (int j = 0; j < 70; j++) {
	//		pbus[i].Accel();
	//	}
	//}

	//for (int i = 0; i < busCount; i++) {
	//	pbus[i].info();
	//}


	//while (1) {
	//	pbus[0].Break();

	//	if (pbus[0].GetCurrentSpeed() <= 0) {
	//		break;
	//	}
	//}

	//delete[] pbus;   // ������ü �迭 ��ȯ

	int a;
	a = 20;

	cout << "&a = " << &a << endl;

	int* pa;   // �������� ������
	pa = &a;

	int** ppa;
	ppa = &pa;

	**ppa;
	**&pa;
	*pa;
	*&a;
	a;

	cout << "�ּҰ��� Ȯ��" << endl;
	cout << "&**ppa = " << &**ppa << endl;
	cout << "&**&pa = " << &**&pa << endl;
	cout << "&*pa = " << &*pa << endl;
	cout << "&*&a = " << &*&a << endl;
	cout << "&a = " << &a << endl << endl;

	cout << "����� ���� Ȯ��" << endl;
	cout << "**ppa = " << **ppa << endl;
	cout << "**&pa = " << **&pa << endl;
	cout << "*pa = " << *pa << endl;
	cout << "*&a = " << *&a << endl;
	cout << "a = " << a << endl;

	DynamicArray array(10);

	for (int i = 0; i < array.GetSize(); i++) {
		array.SetValue(i, i);
	}

	for (int i = 0; i < array.GetSize(); i++) {
		cout << "array[" << i << "] = " << array.GetIndex(i) << endl;
	}

	return 0;
}