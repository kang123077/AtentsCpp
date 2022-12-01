#include <iostream>

using namespace std;

// �����Լ� 

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
    void PrintInfo() { // �Ϲ� ��� �Լ�
        cout << "Child2::PrintInfo" << endl;
    }

    void TestInfo2() override { // ���� �Լ�
        cout << "Child2::TestInfo2" << endl;
    }
};

// �Ϲݸ���Լ� ȣ��
void PrintInfoFunc(Parent& ref) {
    ref.PrintInfo();
}

// �����Լ� ȣ��
void TestInfo1Func(Parent& ref) {
    ref.TestInfo1();
}

// �����Լ� ȣ��
void TestInfo2Func(Parent& ref) {
    ref.TestInfo2();
}


//int main() {
//    Parent parent;
//    Child1 child1;
//    Child2 child2;
//
//
//    // �Ϲݸ���Լ� ȣ��
//    cout << "�Ϲݸ���Լ� ȣ��" << endl;
//    PrintInfoFunc(parent);
//    PrintInfoFunc(child1);
//    PrintInfoFunc(child2);
//
//    cout << endl;
//
//    cout << "�����Լ� ȣ��" << endl;
//    TestInfo1Func(parent);
//    TestInfo1Func(child1);
//    TestInfo1Func(child2);
//
//    cout << endl;
//
//    cout << "�����Լ� ȣ��" << endl;
//    TestInfo2Func(parent);
//    TestInfo2Func(child1);
//    TestInfo2Func(child2);
//
//
//    return 0;
//}