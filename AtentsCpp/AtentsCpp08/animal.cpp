#include <iostream>
#include <string>

using namespace std;
// µ¿¹° ½Ã¹Ä
// µÅÁö, ´ß, ¼Ò

typedef enum tagAnimalType {
	PIG = 0,
	COW = 1,
	CHICKEN = 2,
	DOLPHIN = 3
} AnimalType;

class Animal {
private:
	AnimalType _type; // 0: µÅÁö, 1: ¼Ò, 2: ´ß
	string _name;
	float _weight;
	float _height;
	float _age;
	bool _isFly;
	bool _isSwim;

	void Fly() {
		cout << _name << "ÀÌ(°¡) ³³´Ï´Ù." << endl;
	}

	void Swim() {
		cout << _name << "ÀÌ(°¡) Çì¾öÄ¨´Ï´Ù." << endl;
	}
	
public:
	Animal(AnimalType type, string name, float weight, float height, float age, bool isFly, bool isSwim)
		: _type(type), _name(name), _weight(weight), _height(height), _age(age), _isFly(isFly), _isSwim(isSwim) {}

	void Speak() {
		switch (_type)
		{
		case PIG:
			cout << _name << "ÀÌ(°¡) ²Ü²Ü ¿ó´Ï´Ù." << endl;
			break;
		case COW:
			cout << _name << "ÀÌ(°¡) À½¸Ó ¿ó´Ï´Ù." << endl;
			break;
		case CHICKEN:
			cout << _name << "ÀÌ(°¡) ²¿²¿ ¿ó´Ï´Ù." << endl;
			break;
		case DOLPHIN:
			cout << _name << "ÀÌ(°¡) ²ó¿õ ¿ó´Ï´Ù." << endl;
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
			cout << _name << "ÀÌ(°¡) ¶Ý´Ï´Ù." << endl;
		}
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

int main() {

	Animal pig(PIG, "µÅÁö", 180.0f, 150.0f, 2.5f, false, false);
	Animal cow(COW, "¼Ò", 220.0f, 200.0f, 1.8f, false, false);
	Animal notFlyChicken(CHICKEN, "¸ø³ª´Â ´ß", 4.0f, 40.0f, 1.2f, false, false);
	Animal FlyChicken(CHICKEN, "³ª´Â ´ß", 3.5f, 40.0f, 1.2f, true, false);
	Animal SwimDolphin(CHICKEN, "µ¹°í·¡", 3.5f, 40.0f, 1.2f, false, true);

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