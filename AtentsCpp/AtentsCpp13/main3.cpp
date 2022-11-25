#include <iostream>

using namespace std;

class Parent2 {
public:
    int _value;

public:
    Parent2(int value)
        : _value(value) {}

};

//상속관계에서 접근 제어자

class Child2 : public Parent2 {
private:
    int _value;

public:
    Child2(int value, int value2)
        : Parent2(value), _value(value2) {}

    int GetValue() {
        return Parent2::_value;
    }

    int GetValue2() {
        return _value;
    }
};

//int main() {
//
//    Child2 child(10, 20);
//
//    cout << child.GetValue() << endl;
//    cout << child.Parent2::_value << endl;
//
//    cout << child.GetValue2() << endl;
//
//
//    return 0;
//}