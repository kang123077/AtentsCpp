#include <iostream>
#include <string>

using namespace std;
// ���� �ù�
// ����, ��, ��

typedef enum tagAnimalType {
	PIG = 0,
	COW = 1,
	CHICKEN = 2,
	DOLPHIN = 3
} AnimalType;

class Animal {
private:
	AnimalType _type; // 0: ����, 1: ��, 2: ��
	string _name;
	float _weight;
	float _height;
	float _age;
	bool _isFly;
	bool _isSwim;

	void Fly() {
		cout << _name << "��(��) ���ϴ�." << endl;
	}

	void Swim() {
		cout << _name << "��(��) ���Ĩ�ϴ�." << endl;
	}
	
public:
	Animal(AnimalType type, string name, float weight, float height, float age, bool isFly, bool isSwim)
		: _type(type), _name(name), _weight(weight), _height(height), _age(age), _isFly(isFly), _isSwim(isSwim) {}

	void Speak() {
		switch (_type)
		{
		case PIG:
			cout << _name << "��(��) �ܲ� ��ϴ�." << endl;
			break;
		case COW:
			cout << _name << "��(��) ���� ��ϴ�." << endl;
			break;
		case CHICKEN:
			cout << _name << "��(��) ���� ��ϴ�." << endl;
			break;
		case DOLPHIN:
			cout << _name << "��(��) ��� ��ϴ�." << endl;
		}
	}

	void Run() {
		if (_isFly) {
			Fly();
		}
		else if (_isSwim) {
			Swim();
		}
		else {
			cout << _name << "��(��) �ݴϴ�." << endl;
		}
	}

	void Eat() {
		cout << _name << "��(��) �Խ��ϴ�." << endl;
	}

	void Info() {
		cout << "�̸� : " << _name << endl;
		cout << "������ : " << _weight << endl;
		cout << "���� : " << _height << endl;
		cout << "���� : " << _age << endl;
	}
};

int main() {

	Animal pig(PIG, "����", 180.0f, 150.0f, 2.5f, false, false);
	Animal cow(COW, "��", 220.0f, 200.0f, 1.8f, false, false);
	Animal notFlyChicken(CHICKEN, "������ ��", 4.0f, 40.0f, 1.2f, false, false);
	Animal FlyChicken(CHICKEN, "���� ��", 3.5f, 40.0f, 1.2f, true, false);
	Animal SwimDolphin(CHICKEN, "����", 3.5f, 40.0f, 1.2f, false, true);

	pig.Speak();
	cow.Speak();
	notFlyChicken.Speak();
	FlyChicken.Speak();
	SwimDolphin.Speak();

	cout << endl;

	pig.Run();
	cow.Run();
	notFlyChicken.Run();
	FlyChicken.Run();
	SwimDolphin.Run();

	return 0;
}