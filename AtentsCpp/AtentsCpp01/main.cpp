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

int main() {
	Son sona;
	sona.jumin = "960930";
	sona.name = "�����";
	sona.age = 31;
	sona.address = "rondon";

	cout << "�ֹι�ȣ: " << sona.jumin << endl;
	cout << "�̸�: " << sona.name << endl;
	cout << "����: " << sona.age << endl;
	cout << "�ּ�: " << sona.address << endl;

	return 0;
}