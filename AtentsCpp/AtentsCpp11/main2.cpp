#include <iostream>
#include <string>

using namespace std;

//값 타입으로 받으면 상속시 데이터가 날아가서 참조형으로 구현
class Arm {
private:
	int _type;
	string _name;

public:
	Arm(string name, int type)
		: _name(name), _type(type) {}

	string GetName() {
		return _name;
	}

	int GetType() {
		return _type;
	}
};

class CannonArm : public Arm {
public:
	CannonArm()
		:Arm("CannonArm", 0) {}
};

class LazerArm : public Arm {
public:
	LazerArm()
		:Arm("LazerArm", 1) {}
};

class BombArm : public Arm {
public:
	BombArm()
		:Arm("BombArm", 2) {}
};

class RocketArm : public Arm {
public:
	RocketArm()
		:Arm("RocketArm", 3) {}
};

class Robot {
private:
	Arm* _leftArm;
	Arm* _rightArm;

public:
	Robot(Arm* leftArm, Arm* rightArm)
		: _leftArm(leftArm), _rightArm(rightArm) {}
	/*
		switch (_leftArm.GetType()) {
		case 0:
		   cout << "cannonArm Type" << endl;
		   break;

		case 1:
		   cout << "lazerArm Type" << endl;
		   break;

		case 2:
		   cout << "bombArm Type" << endl;
		   break;

		case 3:
		   cout << "rocketArm Type" << endl;
		   break;
		}
	*/
	void Info() {
		cout << "왼쪽 팔 :" << _leftArm->GetName() << endl;
		cout << "오른쪽 팔 : " << _rightArm->GetName() << endl;
	}

	void SetLeftArm(Arm* parm) {
		_leftArm = parm;
	}

	void SetRightArm(Arm* parm) {
		_rightArm = parm;
	}

};

/*
class CannonArmRobot : public Robot {
public:
	CannonArmRobot(CannonArm& leftArm, CannonArm& rightArm)
		:Robot(leftArm, rightArm)
	{}
};
// 자식의 데이터타입을 부모의 데이터 타입으로 덮어씌우는 업캐스팅
class LazerArmRobot : public Robot {
public:
	LazerArmRobot(LazerArm& leftArm, LazerArm& rightArm)
		:Robot(leftArm, rightArm)
	{}
};

class BombArmRobot : public Robot {
public:
	BombArmRobot(BombArm& leftArm, BombArm& rightArm)
		:Robot(leftArm, rightArm)
	{}
};

class RocketArmRobot : public Robot {
public:
	RocketArmRobot(RocketArm& leftArm, RocketArm& rightArm)
		:Robot(leftArm, rightArm)
	{}
};
*/

int main() {
	CannonArm cannonArm;
	LazerArm lazerArm;
	BombArm bombArm;
	RocketArm rocketArm;

	Robot cannonArmRobot(&cannonArm, &cannonArm);
	Robot lazerArmRobot(&lazerArm, &lazerArm);
	Robot bombArmRobot(&bombArm, &bombArm);
	Robot rocketArmRobot(&rocketArm, &rocketArm);
	Robot leftLazerRightCannonArmRobot(&lazerArm, &cannonArm);
	Robot lBombRLazerArmRobot(&bombArm, &lazerArm);


	cannonArmRobot.Info();
	cout << endl;
	lazerArmRobot.Info();
	cout << endl;
	bombArmRobot.Info();
	cout << endl;
	rocketArmRobot.Info();
	cout << endl;
	leftLazerRightCannonArmRobot.Info();
	cout << endl;
	lBombRLazerArmRobot.Info();
	lBombRLazerArmRobot.SetLeftArm(&cannonArm);
	cout << endl;
	lBombRLazerArmRobot.Info();
	cout << endl;


	return 0;
}