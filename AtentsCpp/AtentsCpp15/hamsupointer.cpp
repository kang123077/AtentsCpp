/*
#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int main() {
    int a = 20;
    int b = 30;

    int(*pfunc)(int, int);   // 함수 포인터

    pfunc = add;

    cout << "pfunc = " << pfunc << endl;

    int ret = pfunc(a, b);

    cout << a << " + " << b << " = " << ret << endl;

    pfunc = sub;

    ret = pfunc(a, b);
    cout << a << " - " << b << " = " << ret << endl;


    int(*pfuncArray[2])(int, int);   // 함수포인터 배열

    pfuncArray[0] = add;
    pfuncArray[1] = sub;

    for (int i = 0; i < 2; i++) {
        cout << "pfuncArray[" << i << " ] = " << pfuncArray[i](a, b) << endl;
    }


    return 0;
}
*/