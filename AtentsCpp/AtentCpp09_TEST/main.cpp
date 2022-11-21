#include <iostream>
#include <string>

using namespace std;
// 동물 시뮬레이션 게임
// 기획 돼지, 닭, 소, 돌고래,
class Animal {
protected:
	int _type;
	string _name;
	float _weight;
	float _height;
	float _age;

public:
	Animal(int type, string name, float weight, float height, float age)
		: _type(type), _name(name), _weight(weight), _height(height), _age(age) {}

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
		cout << _name << "가 꿀꿀합니다." << endl;
	}
};

class Cow : public Animal {
public:
	Cow(string name, float weight, float height, float age)
		:Animal(1, name, weight, height, age) {}

	void Speak() {
		cout << _name << "가 음매합니다." << endl;
	}


};

class Chicken : public Animal {
private:
	bool _isFly;

	void Fly() {
		cout << _name << "이 납니다." << endl;
	}

public:
	Chicken(string name, float weight, float height, float age, bool isFly)
		:Animal(2, name, weight, height, age), _isFly(isFly) {}

	void Speak() {
		cout << _name << "이 꼬끼오합니다." << endl;
	}

	void Run() {
		if (_isFly) {
			Fly();
		}
		else {
			cout << _name << "이 뜁니다." << endl;
		}
	}

};

class Dolphin : public Animal {
private:
	void Swim() {
		cout << _name << "가 헤엄을 칩니다." << endl;
	}

public:
	Dolphin(string name, float weight, float height, float age)
		:Animal(3, name, weight, height, age) {}

	void Speak() {
		cout << _name << "가 끽끽합니다." << endl;
	}

	void Run() {
		Swim();
	}
};

void Speak(Animal* pObj) {
	switch (pObj->GetType()) {
	case 0:   // 돼지
		((Pig*)pObj)->Speak();
		break;

	case 1:   // 소
		((Cow*)pObj)->Speak();
		break;

	case 2:   // 닭
		((Chicken*)pObj)->Speak();
		break;

	case 3:   // 돌고래
		((Dolphin*)pObj)->Speak();
		break;
	}
}

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
}

int main() {

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

	return 0;
}