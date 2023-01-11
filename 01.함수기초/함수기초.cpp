#include <iostream>
using namespace std;

/* 함수(Function)
코드에 묶음 이라고 정의하는 것이 맞을 수 있다.
(하지만 일반적인 코드의 묶음이라고 생각하기 보다는 재사용성을 가지고 있기에 다르다.)

input 으로 무엇을 받고(받지 않을수도 있다.), output으로 무엇을 반환할지 정해준다.

반환타입 함수이름([인자타입 매개변수]) {
    logic ~~

    return output; (반환하는 타입이 없을 경우에는 생략할 수 있다.)
}
*/

// 기본적인 함수를 만들어보자 input:x output:x
void printHelloWorld() {
    cout << "Hello, World!" << endl;
}

// input = int a를 받아서 console 에 출력해보자.
void printNumber(int a) {
    cout << "받은 int a = " << a << endl;
}

// 수를 연산하고 이를 반환해보자.
int culNumber(int a) {

    int result = a * 2;

    return result;
}

int main() {

    int result = culNumber(3);

    printHelloWorld();
    printNumber(result);
}