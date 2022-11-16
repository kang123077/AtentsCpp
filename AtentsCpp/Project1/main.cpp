#include <iostream>
#include <string>

using namespace std;
// 1. ���� Ŭ������ ����
// 2. ����Ǵ� �κ��� ����Ŭ���� �����Ͽ� �ݺ��� �����Ͽ� ���������� ������.
// 3. ������ ������ ������ ������ �������ν� �������� �ο��� �� �ִ�.
//    �������� ��ݱ����� �����Ѵ�.

class Math2 {
public:
	int add(int a, int b) {
		return a + b;
	}

	int sub(int a, int b) {
		return a - b;
	}

	int mul(int a, int b) {
		return a * b;
	}
};

class ExtMath2 : public Math2 {
public:
	float div(int a, int b) {
		return a / (float)b;
	}
};

class ExtString : public std::string {
public:
	ExtString(char* str)
		: std::string(str) {}

	ExtString(const char* str)
		: std::string(str) {}

	int GetLength() {
		const char* ptr = c_str();

		int count = 0;


		for (count = 0; ptr[count] != 0; count++);

		return count;
	}
};


// �������� �ùķ��̼� ����
// ��ȹ ����, ��, ��

class Pig {
private:
    string _name;
    float _healthRate; // �ǰ�����
    float _weight;
    float _age;

public:
    Pig(string name, float healthrate, float weight, float age)
        : _name(name), _healthRate(healthrate), _weight(weight), _age(age) {}

    void Speak() {
        cout << _name << "�� �ܲ��մϴ�." << endl;
    }

    void Eat() {
        cout << _name << "�� �Խ��ϴ�." << endl;
    }

    void Run() {
        cout << _name << "�� �ݴϴ�. " << endl;
    }

    void CheckHealth() {
        if (_healthRate <= 100.0f && _healthRate > 80.0f) {
            cout << _name << "�� �ǰ����°� ����" << endl;
        }
        else if (_healthRate <= 80.0f && _healthRate > 50) {
            cout << _name << "�� �ǰ����°� ����" << endl;
        }
    }

    void Info() {
        cout << "�̸�: " << _name << endl;
        cout << "�ǰ�����: " << _healthRate << endl;
        cout << "������: " << _weight << endl;
        cout << "����: " << _age << endl;
    }
};

class Cow {
private:
    string _name;
    float _weight;
    float _healthRate;
    float _age;

public:
    Cow(string name, float healthrate, float weight, float age)
        : _name(name), _healthRate(healthrate), _weight(weight), _age(age) {}

    void Speak() {
        cout << _name << "�� �����մϴ�." << endl;
    }

    void Eat() {
        cout << _name << "�� �Խ��ϴ�." << endl;
    }

    void Run() {
        cout << _name << "�� �ݴϴ�. " << endl;
    }

    void CheckHealth() {
        if (_healthRate <= 100.0f && _healthRate > 80.0f) {
            cout << _name << "�� �ǰ����°� ����" << endl;
        }
        else if (_healthRate <= 80.0f && _healthRate > 50) {
            cout << _name << "�� �ǰ����°� ����" << endl;
        }
    }

    void Info() {
        cout << "�̸�: " << _name << endl;
        cout << "�ǰ�����: " << _healthRate << endl;
        cout << "������: " << _weight << endl;
        cout << "����: " << _age << endl;
    }
};

class Chicken {
private:
    string _name;
    float _weight;
    float _healthRate;
    float _age;
    bool _isFly;

    void Fly() {
        cout << _name << "�� ���ϴ�." << endl;
    }

public:
    Chicken(string name, float healthRate, float weight, float age, bool isFly)
        : _name(name), _weight(weight), _healthRate(healthRate), _age(age), _isFly(isFly) {}

    void Speak() {
        cout << _name << "�� ������ �մϴ�." << endl;
    }

    void Eat() {
        cout << _name << "�� �Խ��ϴ�. " << endl;
    }

    void Run() {
        if (_isFly) {
            Fly();
        }
        else {
            cout << _name << "�� �ݴϴ�." << endl;
        }
    }

    void Info() {
        cout << "�̸�: " << _name << endl;
        cout << "�ǰ�����: " << _healthRate << endl;
        cout << "������: " << _weight << endl;
        cout << "����: " << _age << endl;
        if (_isFly) {
            cout << "���� ��" << endl;
        }
        else {
            cout << "������ ��" << endl;
        }
    }
};


int main() {
	int a = 20;
	int b = 30;

	Math2 math2;

	cout << a << " + " << b << " = " << math2.add(a, b) << endl;


	ExtMath2 extMath;

	cout << a << " - " << b << " = " << extMath.sub(a, b) << endl;

	cout << a << " / " << b << " = " << extMath.div(a, b) << endl;


	ExtString str((char*)"monster");

	cout << str << "�� ������ ������ " << str.GetLength() << " �Դϴ�." << endl;

	ExtString str2 = "i am a monster!!";

	cout << str2 << "�� ������ ������ " << str2.GetLength() << " �Դϴ�." << endl;

	cout << str + str2 << endl;


    Pig pig("����", 80.0f, 200.0f, 2.5f);
    Cow cow("��", 90.0f, 250.0f, 3.5f);
    Chicken flyChicken("���� ��", 70.0f, 4.0f, 1.2f, true);
    Chicken notFlyChicken("������ ��", 50.0f, 3.5f, 2.2f, false);


    pig.Speak();
    cow.Speak();
    flyChicken.Speak();
    notFlyChicken.Speak();


    pig.Run();
    cow.Run();
    flyChicken.Run();
    notFlyChicken.Run();


	return 0;
}