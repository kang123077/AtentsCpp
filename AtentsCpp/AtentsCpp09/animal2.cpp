#include <iostream>
#include <string>

using namespace std;
// µ¿¹° ½Ã¹Ä
// µÅÁö, ´ß, ¼Ò

class Animal {
protected:
	string _name;
	float _weight;
	float _height;
	float _age;

public:
	Animal(string name, float weight, float height, float age)
		: _name(name), _weight(weight), _height(height), _age(age) {}

	void Speak() {
		cout << _name << "ÀÌ(°¡) ¿ó´Ï´Ù." << endl;
	}

	void Run() {
		cout << _name << "ÀÌ(°¡) ¶Ý´Ï´Ù." << endl;
	}

	void Eat() {
		cout << _name << "ÀÌ(°¡) ¸Ô½À´Ï´Ù." << endl;
	}

	void Info() {
		cout << "ÀÌ¸§ : " << _name << endl;
		cout << "¸ö¹«°Ô : " << _weight << endl;
		cout << "½ÅÀå : " << _height << endl;
		cout << "³ªÀÌ : " << _age << endl;
	}
};

class Pig : public Animal {
public:
	Pig(string name, float weight, float height, float age)
		:Animal(name, weight, height, age) {}

	void Speak() {
		cout << _name << "ÀÌ(°¡) ²Ü²Ü ¿ó´Ï´Ù." << endl;
	}
};

class Cow : public Animal {
public:
	Cow(string name, float weight, float height, float age)
		:Animal(name, weight, height, age) {}

	void Speak() {
		cout << _name << "ÀÌ(°¡) À½¸Ó ¿ó´Ï´Ù." << endl;
	}
};

class Chicken : public Animal {
private:
	bool _isFly;

	void Fly() {
		if (_isFly)
			cout << _name << "ÀÌ(°¡) ³³´Ï´Ù." << endl;
		else
			cout << _name << "ÀÌ(°¡) ¶Ý´Ï´Ù." << endl;
	}

public:
	Chicken(string name, float weight, float height, float age, bool isFly)
		:Animal(name, weight, height, age), _isFly(isFly) {}

	void Run() {
		Fly();
	}

	void Speak() {
		cout << _name << "ÀÌ(°¡) ²¿²¿ ¿ó´Ï´Ù." << endl;
	}
};

class Dolphin : public Animal {
private:
	bool _isSwim;

	void Swim() {
		cout << _name << "ÀÌ(°¡) Çì¾öÄ¨´Ï´Ù." << endl;
	}
public:
	Dolphin(string name, float weight, float height, float age, bool isSwim)
		:Animal(name, weight, height, age), _isSwim(isSwim) {}

	void Run() {
		Swim();
	}

	void Speak() {
		cout << _name << "ÀÌ(°¡) ²ó¿ì ¿ó´Ï´Ù." << endl;
	}
};

//int main() {
//
//	Pig pig("µÅÁö", 180.0f, 150.0f, 2.5f);
//	Cow cow("¼Ò", 220.0f, 200.0f, 1.8f);
//	Chicken notFlyChicken("¸ø³ª´Â ´ß", 4.0f, 40.0f, 1.2f, false);
//	Chicken FlyChicken("³ª´Â ´ß", 3.5f, 40.0f, 1.2f, true);
//	Dolphin SwimDolphin("µ¹°í·¡", 3.5f, 40.0f, 1.2f, true);
//
//	pig.Speak();
//	cow.Speak();
//	notFlyChicken.Speak();
//	FlyChicken.Speak();
//	SwimDolphin.Speak();
//
//	cout << endl;
//
//	pig.Run();
//	cow.Run();
//	notFlyChicken.Run();
//	FlyChicken.Run();
//	SwimDolphin.Run();
//
//	return 0;
//}