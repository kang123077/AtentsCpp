#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

/*
int main() {
	list<int> ls;

	for (int i = 0; i < 10; i++)
	{
		ls.push_back(i);
	}

	ls.push_front(100);

	// list<int>::iterator iter = ls.begin();

	auto iter = ls.begin(); // 타입유추

	for (iter = ls.begin(); iter != ls.end(); iter++) {
		cout << *iter << endl;
	}

	for (auto value : ls) { // for - in 문
		cout << "value = " << value << endl;
	}

	return 0;
}
*/

/*
int main() {
	stack<int> st;

	for (int i = 0; i < 10; i++) {
		st.push(i);
	}

	while (!st.empty()) { // 스택이 빌 때까지
		cout << st.top() << endl; // 값을 가져오고
		st.pop(); // 값을 뺌
	}

	return 0;
}
*/

/*
int main() {
	queue<int> qu;

	for (int i = 0; i < 10; i++) {
		qu.push(i);
	}

	cout << "size = " << qu.size() << endl;

	while (!qu.empty()) {
		cout << qu.front() << endl;
		qu.pop();
	}

	return 0;
}
*/

/*
int main() {
	vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	auto iter = vec.begin();

	for (iter = vec.begin(); iter != vec.end(); iter++) {
		cout << *iter << endl;
	}

	cout << "Deque" << endl;
	deque<int> dg;

	dg.push_front(5);
	dg.push_back(6);

	dg.push_back(7);

	dg.push_front(10);

	auto iter2 = dg.begin();

	for (iter2 = dg.begin(); iter2 != dg.end(); iter2++) {
		cout << *iter2 << endl;
	}

	return 0;
}
*/

/*
int main() {
	map<string, int> mp;

	mp.insert({ "apple", 100 });
	mp.insert({ "banana", 200 });
	mp.insert({ "pineapple", 120 });

	mp["pineapple"] = 100;

	cout << "apple : " << mp["apple"] << endl;
	cout << "banana : " << mp["banana"] << endl;
	cout << "pineapple : " << mp["pineapple"] << endl;


	//if(mp.find("banana") != mp)


	return 0;
}
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>

struct Student {
public:
	int _grade;
	int _className;
	string _name;
};



int main() {
	char buff[100];
	list <Student> a;

	for (int i = 0; i < 10; i++) {
		sprintf(buff, "monster_%d", i);
		Student st{ i, i, buff };
		a.push_back(st);
	}


	for (auto i : a) {
		cout << i._grade << ", " << i._className << ", " << i._name << endl;
	}

	Student fst{ 1, 1, "monster_1" };

	auto fi = find(a.begin(), a.end(), fst);

	cout << "find" << endl;
	cout << (*fi)._grade << endl;
	cout << (*fi)._className << endl;
	cout << (*fi)._name << endl << endl;

	return 0;
}

*/