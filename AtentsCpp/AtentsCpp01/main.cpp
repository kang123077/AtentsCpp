#include <iostream>
#include <string>

using namespace std;

// class Ŭ������ {
// �ܼ�ȭ�� �����͸� ����
// }
// ĸ��ȭ(Capsulazation) -> Datatype
// Son�̶�� Ŭ������ ������ Ÿ���� �������

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
	//sona.name = "�����";
	//sona.age = 31;
	//sona.address = "rondon";

	//cout << "�ֹι�ȣ: " << sona.jumin << endl;
	//cout << "�̸�: " << sona.name << endl;
	//cout << "����: " << sona.age << endl;
	//cout << "�ּ�: " << sona.address << endl;

	//game.team = "��Ʈ��";
	//game.position = "�̵��ʴ�";
	//game.kick = 105.2;
	//game.pass = 122.7;
	//game.stamina = 98.5;
	//game.running = 103.2;

	Son2 game;
	game.setName("�����");
	game.setTeam("��Ʈ��");
	game.setPosition("��������");
	game.setKick(105.2);
	game.setPass(122.7);
	game.setSta(113.1);
	game.setRun(102.3);

	cout << "�̸� : " << game.getName() << endl;
	cout << "���� : " << game.getTeam() << endl;
	cout << "������ : " << game.getPosition() << endl;
	cout << "ű : " << game.getKick() << endl;
	cout << "�н� : " << game.getPass() << endl;
	cout << "���¹̳� : " << game.getSta() << endl;
	cout << "�޸��� : " << game.getRun() << endl;
	return 0;
}