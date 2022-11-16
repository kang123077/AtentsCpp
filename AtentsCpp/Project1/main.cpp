#include <iostream>
#include <string>

using namespace std;
// 1. 기존 클래스의 재사용
// 2. 공통되는 부분을 상위클래스 통합하여 반복을 제거하여 유지보수성 좋게함.
// 3. 공통의 조상을 가지는 계층을 만듦으로써 다형성을 부여할 수 있다.
//    다형성의 기반구조를 제공한다.

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


// 동물농장 시뮬레이션 게임
// 기획 돼지, 소, 닭

class Pig {
private:
    string _name;
    float _healthRate; // 건강지수
    float _weight;
    float _age;

public:
    Pig(string name, float healthrate, float weight, float age)
        : _name(name), _healthRate(healthrate), _weight(weight), _age(age) {}

    void Speak() {
        cout << _name << "가 꿀꿀합니다." << endl;
    }

    void Eat() {
        cout << _name << "가 먹습니다." << endl;
    }

    void Run() {
        cout << _name << "이 뜁니다. " << endl;
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
        cout << "이름: " << _name << endl;
        cout << "건강상태: " << _healthRate << endl;
        cout << "몸무게: " << _weight << endl;
        cout << "나이: " << _age << endl;
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
        cout << _name << "가 음매합니다." << endl;
    }

    void Eat() {
        cout << _name << "가 먹습니다." << endl;
    }

    void Run() {
        cout << _name << "이 뜁니다. " << endl;
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
        cout << "이름: " << _name << endl;
        cout << "건강상태: " << _healthRate << endl;
        cout << "몸무게: " << _weight << endl;
        cout << "나이: " << _age << endl;
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
        cout << _name << "이 납니다." << endl;
    }

public:
    Chicken(string name, float healthRate, float weight, float age, bool isFly)
        : _name(name), _weight(weight), _healthRate(healthRate), _age(age), _isFly(isFly) {}

    void Speak() {
        cout << _name << "이 꼬끼오 합니다." << endl;
    }

    void Eat() {
        cout << _name << "이 먹습니다. " << endl;
    }

    void Run() {
        if (_isFly) {
            Fly();
        }
        else {
            cout << _name << "이 뜁니다." << endl;
        }
    }

    void Info() {
        cout << "이름: " << _name << endl;
        cout << "건강상태: " << _healthRate << endl;
        cout << "몸무게: " << _weight << endl;
        cout << "나이: " << _age << endl;
        if (_isFly) {
            cout << "나는 닭" << endl;
        }
        else {
            cout << "못나는 닭" << endl;
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

	cout << str << "의 문자의 갯수는 " << str.GetLength() << " 입니다." << endl;

	ExtString str2 = "i am a monster!!";

	cout << str2 << "의 문자의 갯수는 " << str2.GetLength() << " 입니다." << endl;

	cout << str + str2 << endl;


    Pig pig("돼지", 80.0f, 200.0f, 2.5f);
    Cow cow("소", 90.0f, 250.0f, 3.5f);
    Chicken flyChicken("나는 닭", 70.0f, 4.0f, 1.2f, true);
    Chicken notFlyChicken("못나는 닭", 50.0f, 3.5f, 2.2f, false);


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