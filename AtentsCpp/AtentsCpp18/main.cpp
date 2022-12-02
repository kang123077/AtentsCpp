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

// �⺻������ �����ڴ� �⺻����Ÿ Ÿ�Կ����� ����ó���� �����մϴ�.
// C++������ Ŭ������ ����Ÿ Ÿ�Կ� �����ȣ�� 
// ����� �� �ִ� ����� �����ϰ� �ֽ��ϴ�.
// �� ����� ������ �����ε��̶�� �մϴ�.

/*
int main() {

    Complex com1(10, 10);

    com1.ShowInfo();

    Complex com2(20, 20);

    Complex com3(0, 0);

    com3 = com1 + com2;

    com3.ShowInfo();
    //com3 = com1.operator+(com2);

    // ���� ������ ��ȣ�� �����ε��غ�����...

    com3 = com1 - com2;

    com3.ShowInfo();


    return 0;
}
*/
