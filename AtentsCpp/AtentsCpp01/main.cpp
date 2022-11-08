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

int main() {
	Son sona;
	sona.jumin = "960930";
	sona.name = "손흥민";
	sona.age = 31;
	sona.address = "rondon";

	cout << "주민번호: " << sona.jumin << endl;
	cout << "이름: " << sona.name << endl;
	cout << "나이: " << sona.age << endl;
	cout << "주소: " << sona.address << endl;

	return 0;
}