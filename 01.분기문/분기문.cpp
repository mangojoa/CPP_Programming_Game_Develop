#include <iostream>
using namespace std;

/* [22.11.11]
분기문과 반복문에 대한 설명이였기에 이에 대한 지식은 충분했기에 생략 후,
실습만 진행
*/

// 1. 입력된 int에 따라 순차적으로 증가하는 로직을 작성하라
int main() {
    int a;
    cin >> a;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < (i + 1); j++) {
            cout << "*";
        }
        cout << endl;
    }

}

// 2. 입력된 int에 따라 순차적으로 감소하는 로직을 작성하라
int main() {
    int b;
    cin >> b;

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < (b - i); j++) {
            cout << "*";
        }
        cout << endl;
    }


}

// 3. 