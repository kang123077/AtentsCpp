#include <iostream>

using namespace std;

class RealFather {
public:
	int _age;

public:
	RealFather(int age)
		: _age(age) {}

	int GetAge() {
		return _age;
	}
};

class StepFather {
public:
	int _age;

public:
	StepFather(int age)
		: _age(age) {}

	int GetAge() {
		return _age;
	}

};

class Child : public RealFather, public StepFather {
public:
	int _age;
public:
	Child(int realAge, int stepAge, int ownAge)
		: RealFather(realAge), StepFather(stepAge), _age(ownAge)
	{
	}


	int GetAge() {
		return _age;
	}
};

class Lion {
private:
	string _name;

public:
	Lion(string name)
		: _name(name) {}

	string GetName() {
		return _name;
	}

	void GetSound() {
		cout << "끄왕" << endl;
	}
};

class Tiger {
private:
	string _name;

public:
	Tiger(string name)
		: _name(name) {}

	string GetName() {
		return _name;
	}

	void GetSound() {
		cout << "어흥" << endl;
	}
};

class Liger : public Tiger, public Lion {
private:
	string _name;
public:
	Liger(string yourname, string mothername, string fathername)
		: _name(yourname), Tiger(mothername), Lion(fathername) {}

	string getmothername() {
		return Tiger::GetName();
	}

	string getfathername() {
		return Lion::GetName();
	}

	string GetName() {
		return _name;
	}
};

//int main() {
//
//	Child child(50, 45, 15);
//
//	cout << "Child GetAge = " << child.GetAge() << endl;
//	cout << "RealFather GetAge = " << child.RealFather::GetAge() << endl; // 모호함이 발생
//	cout << "StepFather GetAge = " << child.StepFather::GetAge() << endl; // 모호함이 발생
//
//	Liger liger("라이거", "타이거", "라이온");
//
//	cout << "liger's mothername = " << liger.getmothername() << endl;
//	cout << "liger's fathername = " << liger.getfathername() << endl;
//	cout << "liger's name = " << liger.GetName() << endl;
//
//	return 0;
//}