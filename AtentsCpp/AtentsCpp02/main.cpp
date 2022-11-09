#include <iostream>

using namespace std;

class Dragon {
private:
	// ��������� �Ϲ� ������ �����ϱ� ����
	// ���� ǥ�ø� �� �δ� ���� ����
	int _health;
	int _attack;
	int _defense;

public:
	// �⺻ ������ (���ڸ� ���� �ʴ� ������)
	Dragon() {
		cout << "Dragon �⺻ ������" << endl;
		_health = 0;
		_attack = 0;
		_defense = 0;
	}

	// ���ڸ� �޴� ������
	Dragon(int health, int attack, int defense) {
		cout << "Dragon ���ڸ� �޴� ������" << endl;
		_health = health;
		_attack = attack;
		_defense = defense;
	}

	// ��� �Լ�
	void attack() {
		cout << "attack" << endl;
	}

	// ��� �Լ�
	void showinfo() {
		cout << "health : " << _health << endl;
		cout << "attack : " << _attack << endl;
		cout << "defense : " << _defense << endl;
	}
};

int main() {
	// ��ü�� ���鶧 �ڵ����� ȣ��Ǿ����� ����Լ��� �ֽ��ϴ�.
	// �����ڶ�� �մϴ�.
	// ��ü�� �����ڰ� ȣ��Ǿ������ ������ ��ü�� ������ �˴ϴ�.
	// �����ڸ� ������ ������ �����Ϸ��� �ڵ����� �⺻ �����ڸ� 
	// ���� ������ ��ŵ�ϴ�.

	Dragon dragonA;   // �⺻�����ڰ� ȣ��Ǿ� ��ü ����

	dragonA.attack();

	dragonA.showinfo();

	Dragon dragonB(100, 100, 100);

	dragonB.showinfo();


	return 0;
}