#include <iostream>

using namespace std;

namespace SamSung {
    namespace Develop1 {
        class Math {
        public:
            int add(int a, int b) {
                return a + b;
            }
        };
    }
}

namespace LG {
    class Math {
    public:
        int add(int a, int b) {
            return  a + b;
        }
    };
}

namespace {
    int global = 10;
}


int main() {
    using namespace SamSung::Develop1;

    int a = 20;
    int b = 30;

    Math sMath;

    LG::Math lMath;


    cout << a << " + " << b << " = " << sMath.add(a, b) << endl;
    cout << a << " + " << b << " = " << lMath.add(a, b) << endl;


    cout << global << endl;



    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {

    int inputvalue = 0;
    printf("나눌 값을 입력하세요: ");
    scanf("%d", &inputvalue);

    int b = 10;

    try {
        if (inputvalue == 0) throw string("0으로 나눌수 없습니다.");

        float ret = b / inputvalue;
    }
    catch (string error) {
        cout << error << endl;
    }

    return 0;
}