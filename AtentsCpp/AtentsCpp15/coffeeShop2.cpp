#include <iostream>
#include <string>

using namespace std;

// Ŀ�Ǚ�
// Ŀ�Ǚ����� ���α׷�
// Ŀ�Ǚ��� �����帧�� �ľ�
// ��Ȱ, å��

//  Barista, Cashier
// Guest

// ���������Լ��� �ϳ��� ������ �ִ� Ŭ������
// �߻�Ŭ������� �Ѵ�.
// �߻� Ŭ������ �ڱ� �ڽ��� ��ü�� ���� �� �ִ� �ɷ��� ���
// �ڽ�Ŭ������ ������ �θ��� ���������Լ��� �����ϵ��� ������ �� �ִ�
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
	void MakeADrink() {   // �Ϲݸ���Լ�
		cout << "���Ḧ ����ϴ�." << endl;
	}
	*/

	virtual void MakeADrink() = 0;	// ���������Լ�

	/*
	virtual void MakeADrink() { // �����Լ� 
		cout << "���Ḧ ����ϴ�." << endl;
	}
	*/

};


class Coffee : public Drink {
public:
	Coffee()
		: Drink("Coffee") {}

	void MakeADrink() override { // �������̵� : �θ��� �����Լ��� �ڽ��� ������, override Ű���带 ������ ���� ����
		cout << "Ŀ�Ǹ� ����ϴ�." << endl;
	}
};

class Latte : public Drink {
public:
	Latte()
		: Drink("Latte") {}

	void MakeADrink() override {
		cout << "�󶼸� ����ϴ�." << endl;
	}
};

class Cola : public Drink {
public:
	Cola()
		: Drink("Cola") {}

	void MakeADrink() override {
		cout << "�ݶ� ����ϴ�." << endl;
	}
};

class Cidar : public Drink {
public:
	Cidar()
		: Drink("Cidar") {}

	void MakeADrink() override {
		cout << "���̴ٸ� ����ϴ�." << endl;
	}
};

class BanillaLatte : public Drink {
public:
	BanillaLatte()
		: Drink("BanillaLatte") {}

	void MakeADrink() override {
		cout << "�ٴҶ�󶼸� ����ϴ�." << endl;
	}
};

class CaramelMachiatto : public Drink {
public:
	CaramelMachiatto()
		: Drink("CaramelMachiatto") {}

	void MakeADrink() override {
		cout << "ī��� �����ƶǸ� ����ϴ�." << endl;
	}
};

class IceTea : public Drink {
public:
	IceTea()
		: Drink("IceTea") {}

	void MakeADrink() override {
		cout << "���̽�Ƽ�� ����ϴ�." << endl;
	}
};

class Tea : public Drink {
public:
	Tea()
		:Drink("Tea") {}

	void MakeADrink() override {
		cout << "���� ����ϴ�." << endl;
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

		//cout << drink.GetName() << "�� ����ϴ�." << endl;
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
		cout << drink.GetName() << "�� �ֹ��� �޽��ϴ�." << endl;
		_refBari.MakeDrink(drink);
	}

	int GetOrderCount() {
		return _count;
	}
};

class Guest {
public:
	void OrderedDrink(Cashier& ref, Drink& drink) {   // ������ ����
		cout << drink.GetName() << "�� �ֹ��� �մϴ�." << endl;
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