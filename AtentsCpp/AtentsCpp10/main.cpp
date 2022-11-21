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

class Human {
private:
    Heart _heart;
    Eye _leftEye, _rightEye;

public:
    Human(float heartRate, float leftSight, float rightSight)
        : _heart(heartRate), _leftEye(leftSight), _rightEye(rightSight)
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

class Human2 {
private:
    Watch* _pWatch;

public:

    Human2(Watch* pWatch)
        : _pWatch(pWatch)
    {
        cout << "----- Human 생성자" << endl;
    }

    ~Human2() {
        cout << "---- Human 소멸자" << endl;
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

class Human3 {
private:
    SmartPhone& _phone;

public:
    Human3(SmartPhone& phone)
        : _phone(phone)
    {
        cout << "---- Human 생성자" << endl;
    }

    ~Human3() {
        cout << "---- Human 소멸자" << endl;
    }

    void UsePhone(string number) {
        _phone.call(number);
    }

};


int main() {

    /*
    Car car("금호타이어");

    car.Info();
    */

    // Composition: 포함된 객체가 생명주기를 같이 할때 (강한 결합)
     
    /*
    cout << "Human 객체 생성" << endl;

    {
        Human human(60, 1.5f, 1.3f);

        human.CheckHealthStatus();
    }

    cout << "프로그램 종료" << endl;
    */

    // Agreggation: 포함된 객체가 생명주기를 달리 하는 경우 (약한 결합)

    /*
    Watch redWatch("red");
    Watch blackWatch("black");

    cout << "Human 객체 생성" << endl;
    {
        Human2 human(&redWatch);

        human.ShowWatch();

        human.SetWatch(&blackWatch);

        human.ShowWatch();
    }

    cout << "프로그램 종료" << endl;
    */

    // Agreggation을 참조형으로 구현.

    /*
    SmartPhone smartPhone("삼성", "010-123-1234");

    cout << "Human 객체 생성" << endl;

    {
        Human3 human(smartPhone);

        human.UsePhone("010-222-2222");
    }

    cout << "프로그램 종료" << endl;
    */

    return 0;
}