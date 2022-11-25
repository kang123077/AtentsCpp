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
        cout << _number << "에서 " << sendNumber << "로 전화를 합니다." << endl;
    }

    void ReceiveCall(string receiveNumber) {
        cout << receiveNumber << "에서 전화가 왔습니다. " << endl;
    }

    void SendMessage(string phoneNumber, string Message) {
        cout << phoneNumber << "로 " << "[" << Message << "] 를 보냅니다. " << endl;
    }

    void ReceiveMessage(string phoneNumber, string Message) {
        cout << phoneNumber << "에서 [" << Message << "]가 도착했습니다. " << endl;
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
        cout << "폰에 " << _id << "로 로그인합니다." << endl;
    }

    void LogOut() {
        cout << "폰에서 로그아웃합니다." << endl;
    }

    void SendKakaoTalk(string Message) {
        cout << Message << "를 카카오톡으로 보냅니다." << endl;
    }

    void ReceivedKakaoTalk(string id, string Message) {
        cout << id << "로 부터 " << Message << "를 받습니다." << endl;
    }

    void PlayGame(string gameName) {
        cout << gameName << "을 플레이 합니다." << endl;
    }

    void Calculate() {
        cout << "계산기를 사용합니다." << endl;
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

// Phone크래스와 Computer 클래스를 만들고 다중상속을
// 시켜서 SmartPhone 클래스를 만들고 기능을 작동 시켜 보세요...

//int main() {
//    SmartPhone sPhone("010-111-1111", "monster", "*******");
//
//    sPhone.UsePhone();
//
//    sPhone.UseCall("010-222-2222");
//    sPhone.SendMessage("010-333-3333", "지금 뭐해");
//
//    sPhone.PlayGame("리니지");
//
//
//    return 0;
//}