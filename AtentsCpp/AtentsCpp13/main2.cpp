#include <iostream>
#include <string>

using namespace std;

class Phone {
private:
    string _number;

public:
    Phone(string mynumber)
        : _number(mynumber) {}

    void SendCall(string sendNumber) {
        cout << _number << "���� " << sendNumber << "�� ��ȭ�� �մϴ�." << endl;
    }

    void ReceiveCall(string receiveNumber) {
        cout << receiveNumber << "���� ��ȭ�� �Խ��ϴ�. " << endl;
    }

    void SendMessage(string phoneNumber, string Message) {
        cout << phoneNumber << "�� " << "[" << Message << "] �� �����ϴ�. " << endl;
    }

    void ReceiveMessage(string phoneNumber, string Message) {
        cout << phoneNumber << "���� [" << Message << "]�� �����߽��ϴ�. " << endl;
    }
};

class Computer {
private:
    string _id;
    string _password;

public:
    Computer(string id, string password)
        : _id(id), _password(password) {}

    void Login() {
        cout << "���� " << _id << "�� �α����մϴ�." << endl;
    }

    void LogOut() {
        cout << "������ �α׾ƿ��մϴ�." << endl;
    }

    void SendKakaoTalk(string Message) {
        cout << Message << "�� īī�������� �����ϴ�." << endl;
    }

    void ReceivedKakaoTalk(string id, string Message) {
        cout << id << "�� ���� " << Message << "�� �޽��ϴ�." << endl;
    }

    void PlayGame(string gameName) {
        cout << gameName << "�� �÷��� �մϴ�." << endl;
    }

    void Calculate() {
        cout << "���⸦ ����մϴ�." << endl;
    }


};

class SmartPhone : public Phone, public Computer {
public:
    SmartPhone(string number, string id, string password)
        : Phone(number), Computer(id, password) {}


    void UsePhone() {
        Login();
    }


    void UseCall(string sendNumber) {
        SendCall(sendNumber);
    }



};

// Phoneũ������ Computer Ŭ������ ����� ���߻����
// ���Ѽ� SmartPhone Ŭ������ ����� ����� �۵� ���� ������...

//int main() {
//    SmartPhone sPhone("010-111-1111", "monster", "*******");
//
//    sPhone.UsePhone();
//
//    sPhone.UseCall("010-222-2222");
//    sPhone.SendMessage("010-333-3333", "���� ����");
//
//    sPhone.PlayGame("������");
//
//
//    return 0;
//}