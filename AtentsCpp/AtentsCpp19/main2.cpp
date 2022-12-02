#include <iostream>

using namespace std;


// Functor // 객체를 함수형식으로 사용하는 것
class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }

    float operator()(float a, float b) {
        return a + b;
    }

    double operator()(double a, double b) {
        return a + b;
    }

    int operator()(int a, int b, int c) {
        return a + b + c;
    }

};

/*
int main() {
    int a = 20;
    int b = 30;
    int g = 40;

    float c = 1.2f;
    float d = 3.4f;

    double e = 10.2;
    double f = 20.34;

    Add add;

    cout << a << " + " << b << " = " << add(a, b) << endl; //add.operator()(a, b);
    cout << c << " + " << d << " = " << add(c, d) << endl;
    cout << e << " + " << f << " = " << add(e, f) << endl;

    cout << a << " + " << b << " + " << g << " = " << add(a, b, g) << endl; // add.operator(a, b, g)

    return 0;
}
*/