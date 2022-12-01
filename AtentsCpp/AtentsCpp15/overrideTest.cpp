#include <iostream>

using namespace std;

// 가상함수 

class Parent {
public:
    void PrintInfo() {
        cout << "Parent::PrintInfo" << endl;
    }

    virtual void TestInfo1() {
        cout << "Parent::TestInfo1" << endl;
    }

    virtual void TestInfo2() {
        cout << "Parent::TestInfo2" << endl;
    }
};


class Child1 : public Parent {
public:
    void PrintInfo() {
        cout << "Child1::PrintInfo" << endl;
    }

    void TestInfo1() override {
        cout << "Child1::TestInfo1" << endl;
    }
};

class Child2 : public Parent {
public:
    void PrintInfo() { // 일반 멤버 함수
        cout << "Child2::PrintInfo" << endl;
    }

    void TestInfo2() override { // 가상 함수
        cout << "Child2::TestInfo2" << endl;
    }
};

// 일반멤버함수 호출
void PrintInfoFunc(Parent& ref) {
    ref.PrintInfo();
}

// 가상함수 호출
void TestInfo1Func(Parent& ref) {
    ref.TestInfo1();
}

// 가상함수 호출
void TestInfo2Func(Parent& ref) {
    ref.TestInfo2();
}


//int main() {
//    Parent parent;
//    Child1 child1;
//    Child2 child2;
//
//
//    // 일반멤버함수 호출
//    cout << "일반멤버함수 호출" << endl;
//    PrintInfoFunc(parent);
//    PrintInfoFunc(child1);
//    PrintInfoFunc(child2);
//
//    cout << endl;
//
//    cout << "가상함수 호출" << endl;
//    TestInfo1Func(parent);
//    TestInfo1Func(child1);
//    TestInfo1Func(child2);
//
//    cout << endl;
//
//    cout << "가상함수 호출" << endl;
//    TestInfo2Func(parent);
//    TestInfo2Func(child1);
//    TestInfo2Func(child2);
//
//
//    return 0;
//}