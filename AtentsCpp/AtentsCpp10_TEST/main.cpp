#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

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

class Human {
private:
    Heart _heart;
    Eye _lefteye;
    Eye _righteye;
    Watch* _pwatch;
    SmartPhone& _smartphone;

public:
    Human(Heart heart, Eye lefteye, Eye righteye, Watch* pwatch, SmartPhone& smartphone)
        :_heart(heart), _lefteye(lefteye), _righteye(righteye), _pwatch(pwatch), _smartphone(smartphone)
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
        _lefteye.showStatus();
        cout << "RightEye ";
        _righteye.showStatus();
    }

    void SetWatch(Watch* pWatch) {
        _pwatch = pWatch;
    }

    void ShowWatch() {
        _pwatch->ShowCurrentTime();
    }

    void UsePhone(string number) {
        _smartphone.call(number);
    }
};

int main() {

    Watch redWatch("red");
    Watch blackWatch("black");
    SmartPhone galaxy("samsung", "01052022508");

    Human human(60, 1.1f, 1.2f, &redWatch, galaxy);

    human.CheckHealthStatus();

    human.ShowWatch();

    human.SetWatch(&blackWatch);

    human.ShowWatch();

    human.UsePhone("010-222-2222");

    return 0;
}