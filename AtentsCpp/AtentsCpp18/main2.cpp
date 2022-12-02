#include <iostream>

using namespace std;

class A {
private:
    int _value;

public:
    A(int value)
        : _value(value) {}

};

class Complex {
private:
    int _real;
    int _imaginary;

public:
    Complex(int real, int imaginary)
        : _real(real), _imaginary(imaginary) {}

    int GetReal() {
        return _real;
    }

    int GetImaginary() {
        return _imaginary;
    }

    /*
    Complex& operator+(Complex& ref) {
       Complex temp(_real + ref._real, _imaginary + ref._imaginary);

       return temp;
    }
    */

    Complex& operator+(int value) {
        cout << "정수 덧셈 멤버함수" << endl;
        Complex temp(_real + value, _imaginary);

        return temp;
    }

    Complex& operator-(Complex& ref) {
        Complex temp(_real - ref._real, _imaginary - ref._imaginary);

        return temp;
    }

    Complex& operator++(int) {   // 후치형
        Complex temp(_real, _imaginary);

        _real++;
        _imaginary++;


        return temp;
    }

    Complex& operator++() {   // 전치형
        _real++;
        _imaginary++;

        return *this;
    }

    operator int() {
        return _real;
    }

    operator float() {
        return _real;
    }

    operator A() {
        return _real;
    }

    void ShowInfo() {
        cout << _real << showpos << _imaginary << "i" << endl;
        cout << noshowpos;
    }
};

// 연산자오버로딩을 하는 방법
// 클래스의 멤버함수
// 일반함수

Complex& operator+(Complex& left, Complex& right) {
    cout << "일반함수" << endl;
    Complex temp(left.GetReal() + right.GetReal(), left.GetImaginary() + right.GetImaginary());


    return temp;
}

ostream& operator<<(ostream& o, Complex& right) {
    cout << "Complex 객체 출력" << endl;
    o << right.GetReal() << showpos << right.GetImaginary() << "i" << endl;
    o << noshowpos;

    return o;
}


int main() {

    Complex com1(10, 10);
    Complex com2(20, 20);
    Complex com3(0, 0);

    com3 = com1 + com2;

    //com3.ShowInfo();
    cout << com3;

    com3 = com1 + 2;

    cout << com3;
    //cout.operator<<(com3);





    return 0;
}