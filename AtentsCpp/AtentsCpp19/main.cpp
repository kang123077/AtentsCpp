#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* _parr;
    int _size;

public:
    DynamicArray()
        : DynamicArray(0) {}

    DynamicArray(int size)
        : _size(size)
    {
        if (_size >= 0) {
            _parr = new int[_size];
        }
        else {
            _parr = NULL;
        }
    }

    ~DynamicArray()
    {
        delete _parr;
    }

    void MakeArray(int size) {

        _parr = new int[size];
    }

    int GetSize() {
        return _size;
    }

    //�迭 ÷�ڿ����� �����ε�
    int& operator[](int index) {
        return _parr[index];
    }

    DynamicArray& operator=(DynamicArray& ref) {
        delete _parr;   // ������ �����޸𸮸� ��ȯ

        _size = ref._size;

        _parr = new int[_size];   // ���ο� �����޸� �Ҵ�

        // ref�� �����޸𸮿� �ִ� ���� ����
        for (int i = 0; i < _size; i++) {
            _parr[i] = ref._parr[i];
        }

        return *this;
    }

};

/*
int main() {
    DynamicArray array(10);
    DynamicArray array2(20);

    for (int i = 0; i < array2.GetSize(); i++) {
        array2[i] = i * 2;
    }

    for (int i = 0; i < array2.GetSize(); i++) {
        cout << "array2[" << i << "] = " << array2[i] << endl;
    }

    cout << endl << endl;
    array = array2;

    array.operator=(array2);


    for (int i = 0; i < array.GetSize(); i++) {
        cout << "array[" << i << "] = " << array[i] << endl;
    }




    return 0;
}
*/