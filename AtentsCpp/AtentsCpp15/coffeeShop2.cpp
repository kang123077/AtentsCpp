#include <iostream>
#include <string>

using namespace std;

// 커피숖
// 커피숖관리 프로그램
// 커피숖의 업무흐름을 파악
// 역활, 책임

//  Barista, Cashier
// Guest

// 순수가상함수를 하나라도 가지고 있는 클래스를
// 추상클래스라고 한다.
// 추상 클래스는 자기 자신의 객체를 만들 수 있는 능력은 상실
// 자식클래스가 무조건 부모의 순수가상함수를 구현하도록 강제할 수 있다
class Drink {
private:
	string _name;

public:
	Drink(string name)
		: _name(name) {}

	string GetName() {

		return _name;
	}

	/*
	void MakeADrink() {   // 일반멤버함수
		cout << "음료를 만듭니다." << endl;
	}
	*/

	virtual void MakeADrink() = 0;	// 순수가상함수

	/*
	virtual void MakeADrink() { // 가상함수 
		cout << "음료를 만듭니다." << endl;
	}
	*/

};


class Coffee : public Drink {
public:
	Coffee()
		: Drink("Coffee") {}

	void MakeADrink() override { // 오버라이드 : 부모의 가상함수를 자식이 재정의, override 키워드를 검증을 위해 삽입
		cout << "커피를 만듭니다." << endl;
	}
};

class Latte : public Drink {
public:
	Latte()
		: Drink("Latte") {}

	void MakeADrink() override {
		cout << "라떼를 만듭니다." << endl;
	}
};

class Cola : public Drink {
public:
	Cola()
		: Drink("Cola") {}

	void MakeADrink() override {
		cout << "콜라를 만듭니다." << endl;
	}
};

class Cidar : public Drink {
public:
	Cidar()
		: Drink("Cidar") {}

	void MakeADrink() override {
		cout << "사이다를 만듭니다." << endl;
	}
};

class BanillaLatte : public Drink {
public:
	BanillaLatte()
		: Drink("BanillaLatte") {}

	void MakeADrink() override {
		cout << "바닐라라떼를 만듭니다." << endl;
	}
};

class CaramelMachiatto : public Drink {
public:
	CaramelMachiatto()
		: Drink("CaramelMachiatto") {}

	void MakeADrink() override {
		cout << "카라멜 마끼아또를 만듭니다." << endl;
	}
};

class IceTea : public Drink {
public:
	IceTea()
		: Drink("IceTea") {}

	void MakeADrink() override {
		cout << "아이스티를 만듭니다." << endl;
	}
};

class Tea : public Drink {
public:
	Tea()
		:Drink("Tea") {}

	void MakeADrink() override {
		cout << "차를 만듭니다." << endl;
	}
};

class Barista {
public:
	void MakeDrink(Drink& drink) {
		if (drink.GetName() == "Coffee") {
			((Coffee&)drink).MakeADrink();
		}
		else if (drink.GetName() == "Cola") {
			((Cola&)drink).MakeADrink();
		}
		else if (drink.GetName() == "Latte") {
			((Latte&)drink).MakeADrink();
		}
		else if (drink.GetName() == "Cidar") {
			((Cidar&)drink).MakeADrink();
		}
		else if (drink.GetName() == "BanillaLatte") {
			((BanillaLatte&)drink).MakeADrink();
		}
		else if (drink.GetName() == "CaramelMachiatto") {
			((BanillaLatte&)drink).MakeADrink();
		}
		else if (drink.GetName() == "IceTea") {
			((BanillaLatte&)drink).MakeADrink();
		}
		else if (drink.GetName() == "Tea") {
			((BanillaLatte&)drink).MakeADrink();
		}

		//cout << drink.GetName() << "를 만듭니다." << endl;
	}

};

class Cashier {
private:
	Barista& _refBari;

	int _count;

public:
	Cashier(Barista& refBari)
		: _refBari(refBari), _count(0) {}

	void OrderingDrink(Drink& drink) {
		_count++;
		cout << drink.GetName() << "을 주문을 받습니다." << endl;
		_refBari.MakeDrink(drink);
	}

	int GetOrderCount() {
		return _count;
	}
};

class Guest {
public:
	void OrderedDrink(Cashier& ref, Drink& drink) {   // 의존적 관계
		cout << drink.GetName() << "를 주문을 합니다." << endl;
		ref.OrderingDrink(drink);
	}
};

int main() {
	Barista bari;
	Cashier cashier(bari);
	Guest guest;

	Coffee coffee;
	Latte latte;
	Cola cola;
	Cidar cidar;
	BanillaLatte banillaLatte;
	CaramelMachiatto caramelmachiatto;
	IceTea icetea;
	Tea tea;

	guest.OrderedDrink(cashier, coffee);
	cout << endl;

	guest.OrderedDrink(cashier, latte);
	cout << endl;

	guest.OrderedDrink(cashier, cola);

	cout << endl;
	guest.OrderedDrink(cashier, cidar);

	cout << endl;
	guest.OrderedDrink(cashier, banillaLatte);

	cout << endl;
	guest.OrderedDrink(cashier, caramelmachiatto);

	cout << endl;
	guest.OrderedDrink(cashier, icetea);

	cout << endl;
	guest.OrderedDrink(cashier, tea);


	return 0;
}