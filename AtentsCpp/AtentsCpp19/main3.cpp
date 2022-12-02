#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string _name;

public:
    void SetName(string name) {
        _name = name;
    }

    string GetName() {
        return _name;
    }

};


template <typename T>
class DynamicArray {
private:
    T* _parr;
    int _size;

public:
    DynamicArray(int size)
        : _size(size)
    {
        if (_size >= 0) {
            _parr = new T[_size];
        }
        else {
            _parr = NULL;
        }
    }

    ~DynamicArray()
    {
        delete[] _parr;
    }

    int GetSize() {
        return _size;
    }

    //배열 첨자연산자 오버로딩
    T& operator[](int index) {
        return _parr[index];
    }

    DynamicArray& operator=(DynamicArray& ref) {
        delete[] _parr;   // 기존의 동적메모리를 반환

        _size = ref._size;

        _parr = new T[_size];   // 새로운 동적메모리 할당

        // ref의 동적메모리에 있는 값을 복사
        for (int i = 0; i < _size; i++) {
            _parr[i] = ref._parr[i];
        }

        return *this;
    }
};


int main() {
    char buff[100];


    DynamicArray<int> array(10);


    for (int i = 0; i < array.GetSize(); i++) {
        array[i] = i;
    }

    for (int i = 0; i < array.GetSize(); i++) {
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    cout << endl;

    DynamicArray<float> array2(10);
    for (int i = 0; i < array2.GetSize(); i++) {
        array2[i] = i * 1.342f;
    }

    for (int i = 0; i < array2.GetSize(); i++) {
        cout << "array2[" << i << "] = " << array2[i] << endl;
    }

    cout << endl;
    DynamicArray<Student> array3(10);
    for (int i = 0; i < array3.GetSize(); i++) {
        sprintf(buff, "monster_%d", i);
        array3[i].SetName(buff);
    }

    for (int i = 0; i < array2.GetSize(); i++) {
        cout << "array3[" << i << "] = " << array3[i].GetName() << endl;
    }





    return 0;
}