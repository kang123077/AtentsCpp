#include <iostream>
#include <string>

using namespace std;

// class 클래스명 {
// 단순화한 데이터를 나열
// }
// 캡슐화(Capsulazation) -> Datatype
// Son이라는 클래스형 데이터 타입을 만들었다

class Son {
public:
	string jumin;
	string name;
	int age;
	string address;
};

class Son2 {
private:
	string name;
	string team;
	string position;
	float kick;
	float pass;
	float stamina;
	float running;
public:
	void setName(string value) {
		name = value;
	}
	string getName() {
		return name;
	}
	void setTeam(string value) {
		team = value;
	}
	string getTeam() {
		return team;
	}
	void setPosition(string value) {
		position = value;
	}
	string getPosition() {
		return position;
	}
	void setKick(float value) {
		kick = value;
	}
	float getKick() {
		return kick;
	}
	void setPass(float value) {
		pass = value;
	}
	float getPass() {
		return pass;
	}
	void setSta(float value) {
		stamina = value;
	}
	float getSta() {
		return stamina;
	}
	void setRun(float value) {
		running = value;
	}
	float getRun() {
		return running;
	}
};

int main() {
	//Son sona;
	//sona.jumin = "960930";
	//sona.name = "손흥민";
	//sona.age = 31;
	//sona.address = "rondon";

	//cout << "주민번호: " << sona.jumin << endl;
	//cout << "이름: " << sona.name << endl;
	//cout << "나이: " << sona.age << endl;
	//cout << "주소: " << sona.address << endl;

	//game.team = "토트넘";
	//game.position = "미드필더";
	//game.kick = 105.2;
	//game.pass = 122.7;
	//game.stamina = 98.5;
	//game.running = 103.2;

	Son2 game;
	game.setName("손흥민");
	game.setTeam("토트넘");
	game.setPosition("윙포워드");
	game.setKick(105.2);
	game.setPass(122.7);
	game.setSta(113.1);
	game.setRun(102.3);

	cout << "이름 : " << game.getName() << endl;
	cout << "팀명 : " << game.getTeam() << endl;
	cout << "포지션 : " << game.getPosition() << endl;
	cout << "킥 : " << game.getKick() << endl;
	cout << "패스 : " << game.getPass() << endl;
	cout << "스태미너 : " << game.getSta() << endl;
	cout << "달리기 : " << game.getRun() << endl;
	return 0;
}