#include <iostream>

using namespace std;

struct Student {
    int age;
    int grade;
};


template <typename T>
class Sort {
public:
    virtual bool CompareValue(T left, T right) = 0;

};

template <typename T>
class Acending : public Sort<T> {
    bool CompareValue(int left, int right) {
        if (left > right) {
            return 1;
        }
        else {
            return 0;
        }
    }
};

template <>
class Acending<Student> : public Sort<Student> {
    bool CompareValue(Student left, Student right) {
        if (left.age > right.age) {
            return 1;
        }
        else {
            return 0;
        }
    }
};


template <typename T>
class Decending : public Sort<T> {

    bool CompareValue(T left, T right) {
        if (left < right) {
            return 1;
        }
        else {
            return 0;
        }

    }

};

template <>
class Decending<Student> : public Sort<Student> {

    bool CompareValue(Student left, Student right) {
        if (left.age < right.age) {
            return 1;
        }
        else {
            return 0;
        }

    }

};

template <typename T>
class DynamicArray {


private:
    T* _arr;
    int _size;

public:
    DynamicArray(int size)
        : _size(size) {
        _arr = new T[_size];
    }

    ~DynamicArray() {
        delete[] _arr;
    }

    int GetSize() {
        return _size;
    }

    DynamicArray& operator=(DynamicArray& ref) {
        delete[] _arr;
        _size = ref._size;

        _arr = new T[_size];

        for (int i = 0; i < _size; i++) {
            _arr[i] = ref._arr[i];
        }

        return *this;
    }

    T& operator[](int index) {
        return _arr[index];
    }

    void info() {
        for (int i = 0; i < _size; i++) {
            cout << "_arr[" << i << "] = " << _arr[i] << endl;
        }
    }

    void Sort(Sort<T>& ref) {
        for (int i = 0; i < _size - 1; i++) {
            for (int j = 0; j < _size - (1 + i); j++) {
                if (ref.CompareValue(_arr[j], _arr[j + 1])) {
                    T temp = _arr[j];
                    _arr[j] = _arr[j + 1];
                    _arr[j + 1] = temp;

                }
            }
        }
    }

};

// ������ �����ε��� �Ҷ� ����� ���� ����Ÿ Ÿ���� �������� 
// �����ʿ� ���� ��쿡�� �Ϲ� �Լ��� ���ؼ� ������ �����ε��� 
// �ؾ��Ѵ�.
template <typename T>
ostream& operator<<(ostream& out, DynamicArray<T>& ref) {
    for (int i = 0; i < ref.GetSize(); i++) {
        out << ref[i] << ", ";
    }

    return out;
}

template <>
ostream& operator<<(ostream& out, DynamicArray<int>& ref) {
    for (int i = 0; i < ref.GetSize(); i++) {
        out << ref[i] << ", ";
    }

    return out;
}

template <>
ostream& operator<<(ostream& out, DynamicArray<Student>& ref) {
    for (int i = 0; i < ref.GetSize(); i++) {
        out << "[" << ref[i].age << ", " << ref[i].grade << "], ";
    }

    return out;
}


int main() {
    DynamicArray<Student> a(10);

    for (int i = 0; i < a.GetSize(); i++) {
        a[i].age = i;
        a[i].grade = i;
    }

    Acending<Student> asSort;
    a.Sort(asSort);

    cout << a << endl;

    Decending<Student> dcSort;
    a.Sort(dcSort);

    cout << a << endl;

    return 0;
}