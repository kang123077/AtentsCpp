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
        cout << "Heart 생성자" << endl;
    }

    ~Heart() {
        cout << "Heart 소멸자" << endl;
    }

    void showStatus() {
        cout << _heartRate << "속도의 심장 박동" << endl;
    }
};

class Eye {
private:
    float _sight;

public:
    Eye(float sight)
        : _sight(sight)
    {
        cout << "Eye 생성자" << endl;
    }

    ~Eye()
    {
        cout << "Eye 소멸자" << endl;
    }

    void showStatus() {
        cout << _sight << "의 시력" << endl;
    }
};

class Watch {
private:
    string _color;

public:
    Watch(string color)
        : _color(color)
    {
        cout << "---- Watch 생성자" << endl;
    }


    ~Watch()
    {
        cout << "---- Watch 소멸자" << endl;
    }

    void ShowCurrentTime() {
        cout << "[ " << _color << "시계 현재 시간 ]" << endl;

        time_t timer;
        struct tm* t;

        timer = time(NULL); // 현재 시간
        t = localtime(&timer);

        cout << t->tm_hour << "시" << t->tm_min << "분" << t->tm_sec << "초 입니다" << endl << endl;
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
        cout << "SmartPhone 생성자" << endl;
    }

    ~SmartPhone()
    {
        cout << "SmartPhone 소멸자" << endl;
    }

    void call(string number) {
        cout << _callNumber << "에서" << number << "로 전화를 겁니다" << endl;
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
        cout << "Human 생성자" << endl;
    }
    ~Human()
    {
        cout << "Human 소멸자" << endl;
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