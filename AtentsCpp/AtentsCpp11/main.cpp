#include <iostream>
#include <string>

using namespace std;

class CannonArm {
private:
    string _name;

public:
    CannonArm()
        : _name("CannonArm") {}

    string GetName() {
        return _name;
    }
};

class LazerArm {
private:
    string _name;

public:
    LazerArm()
        : _name("LazerArm") {}

    string GetName() {
        return _name;
    }
};

class BombArm {
private:
    string _name;

public:
    BombArm()
        : _name("BombArm") {}

    string GetName() {
        return _name;
    }
};

class CannonArmRobot {
private:
    CannonArm _leftArm, _rightArm;

public:
    CannonArmRobot() {}

    void Info() {
        cout << "¿ÞÂÊÆÈ:" << _leftArm.GetName() << endl;
        cout << "¿À¸¥ÂÊÆÈ: " << _rightArm.GetName() << endl;

    }
};

class BombArmRobot {
private:
    BombArm _leftArm, _rightArm;

public:
    BombArmRobot() {}

    void Info() {
        cout << "¿ÞÂÊÆÈ:" << _leftArm.GetName() << endl;
        cout << "¿À¸¥ÂÊÆÈ: " << _rightArm.GetName() << endl;

    }
};

class LazerArmRobot {
private:
    LazerArm _leftArm, _rightArm;

public:
    LazerArmRobot() {}

    void Info() {
        cout << "¿ÞÂÊÆÈ: " << _leftArm.GetName() << endl;
        cout << "¿À¸¥ÂÊÆÈ: " << _rightArm.GetName() << endl;
    }
};


//int main() {
//    CannonArmRobot cannonArmRobot;
//    LazerArmRobot lazerArmRobot;
//    BombArmRobot bombArmRobot;
//
//    cannonArmRobot.Info();
//    cout << endl;
//    lazerArmRobot.Info();
//    cout << endl;
//    bombArmRobot.Info();
//
//
//    return 0;
//}