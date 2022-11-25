#include <iostream>

using namespace std;

// Ŀ�Ǚ�
// Ŀ�Ǚ����� ���α׷�
// Ŀ�Ǚ��� �����帧�� �ľ�
// ��Ȱ, å��

//  Barista, Cashier
// Guest

class Drink {
private:
    string _name;

public:
    Drink(string name)
        : _name(name) {}

    string GetName() {
        return _name;
    }
};

class Coffee : public Drink {
public:
    Coffee()
        :Drink("Coffee") {}
};

class Latte : public Drink {
public:
    Latte()
        : Drink("Latte") {}
};

class Cola : public Drink {
public:
    Cola()
        : Drink("Cola") {}
};

class Cider : public Drink {
public:
    Cider()
        : Drink("Cider") {}
};


class Barista {
public:
    void MakeDrink(Drink& drink) {
        cout << drink.GetName() << "�� ����ϴ�." << endl;
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
    Cider cider;

    guest.OrderedDrink(cashier, coffee);
    cout << endl;

    guest.OrderedDrink(cashier, latte);
    cout << endl;

    guest.OrderedDrink(cashier, cola);
    cout << endl;

    guest.OrderedDrink(cashier, cider);


    return 0;
}