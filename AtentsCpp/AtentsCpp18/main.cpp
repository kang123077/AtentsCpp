#include <iostream>

using namespace std;

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

    Complex& operator+(Complex& ref) {
        Complex temp(_real + ref._real, _imaginary + ref._imaginary);

        return temp;
    }

    Complex& operator-(Complex& ref) {
        Complex temp(_real - ref._real, _imaginary - ref._imaginary);

        return temp;
    }

    void ShowInfo() {
        cout << _real << showpos << _imaginary << "i" << endl;
        cout << noshowpos;
    }

};

// 기본적으로 연산자는 기본데이타 타입에대한 연산처리만 가능합니다.
// C++에서는 클래스형 데이타 타입에 연산기호를 
// 사용할 수 있는 방법을 제공하고 있습니다.
// 이 기능을 연산자 오버로딩이라고 합니다.

/*
int main() {

    Complex com1(10, 10);

    com1.ShowInfo();

    Complex com2(20, 20);

    Complex com3(0, 0);

    com3 = com1 + com2;

    com3.ShowInfo();
    //com3 = com1.operator+(com2);

    // 뺄셈 연산자 기호를 오버로딩해보세요...

    com3 = com1 - com2;

    com3.ShowInfo();


    return 0;
}
*/
