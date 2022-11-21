#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Wheel {
private:
    string _modelName;
public:
    Wheel(string name)
        : _modelName(name) {}
    void info() {
        cout << _modelName << " Wheel" << endl;
    }

};

class Car {
private:
    Wheel _wheel;

public:
    Car(string name)
        : _wheel(name) {}

    void Info() {
        _wheel.info();
    }
};

class Heart {
private:
    float _heartRate;

public:
    Heart(float rate)
        : _heartRate(rate)
    {
        cout << "Heart ������" << endl;
    }

    ~Heart() {
        cout << "Heart �Ҹ���" << endl;
    }

    void showStatus() {
        cout << _heartRate << "�ӵ��� ���� �ڵ�" << endl;
    }
};

class Eye {
private:
    float _sight;

public:
    Eye(float sight)
        : _sight(sight)
    {
        cout << "Eye ������" << endl;
    }

    ~Eye()
    {
        cout << "Eye �Ҹ���" << endl;
    }

    void showStatus() {
        cout << _sight << "�� �÷�" << endl;
    }
};

class Human {
private:
    Heart _heart;
    Eye _leftEye, _rightEye;

public:
    Human(float heartRate, float leftSight, float rightSight)
        : _heart(heartRate), _leftEye(leftSight), _rightEye(rightSight)
    {
        cout << "Human ������" << endl;
    }

    ~Human()
    {
        cout << "Human �Ҹ���" << endl;
    }
    void CheckHealthStatus()
    {
        _heart.showStatus();
        cout << "LeftEye ";
        _leftEye.showStatus();
        cout << "RightEye ";
        _rightEye.showStatus();
    }
};

class Watch {
private:
    string _color;

public:
    Watch(string color)
        : _color(color)
    {
        cout << "---- Watch ������" << endl;
    }


    ~Watch()
    {
        cout << "---- Watch �Ҹ���" << endl;
    }

    void ShowCurrentTime() {
        cout << "[ " << _color << "�ð� ���� �ð� ]" << endl;

        time_t timer;
        struct tm* t;

        timer = time(NULL); // ���� �ð�
        t = localtime(&timer);

        cout << t->tm_hour << "��" << t->tm_min << "��" << t->tm_sec << "�� �Դϴ�" << endl << endl;
    }
};

class Human2 {
private:
    Watch* _pWatch;

public:

    Human2(Watch* pWatch)
        : _pWatch(pWatch)
    {
        cout << "----- Human ������" << endl;
    }

    ~Human2() {
        cout << "---- Human �Ҹ���" << endl;
    }

    void SetWatch(Watch* pWatch) {
        _pWatch = pWatch;
    }

    void ShowWatch() {
        _pWatch->ShowCurrentTime();
    }
};

class SmartPhone {
private:
    string _blend;
    string _callNumber;
public:

    SmartPhone(string blend, string callNumber)
        :_blend(blend), _callNumber(callNumber)
    {
        cout << "SmartPhone ������" << endl;
    }

    ~SmartPhone()
    {
        cout << "SmartPhone �Ҹ���" << endl;
    }
    
    void call(string number) {
        cout << _callNumber << "����" << number << "�� ��ȭ�� �̴ϴ�" << endl;
    }
};

class Human3 {
private:
    SmartPhone& _phone;

public:
    Human3(SmartPhone& phone)
        : _phone(phone)
    {
        cout << "---- Human ������" << endl;
    }

    ~Human3() {
        cout << "---- Human �Ҹ���" << endl;
    }

    void UsePhone(string number) {
        _phone.call(number);
    }

};


int main() {

    /*
    Car car("��ȣŸ�̾�");

    car.Info();
    */

    // Composition: ���Ե� ��ü�� �����ֱ⸦ ���� �Ҷ� (���� ����)
     
    /*
    cout << "Human ��ü ����" << endl;

    {
        Human human(60, 1.5f, 1.3f);

        human.CheckHealthStatus();
    }

    cout << "���α׷� ����" << endl;
    */

    // Agreggation: ���Ե� ��ü�� �����ֱ⸦ �޸� �ϴ� ��� (���� ����)

    /*
    Watch redWatch("red");
    Watch blackWatch("black");

    cout << "Human ��ü ����" << endl;
    {
        Human2 human(&redWatch);

        human.ShowWatch();

        human.SetWatch(&blackWatch);

        human.ShowWatch();
    }

    cout << "���α׷� ����" << endl;
    */

    // Agreggation�� ���������� ����.

    /*
    SmartPhone smartPhone("�Ｚ", "010-123-1234");

    cout << "Human ��ü ����" << endl;

    {
        Human3 human(smartPhone);

        human.UsePhone("010-222-2222");
    }

    cout << "���α׷� ����" << endl;
    */

    return 0;
}