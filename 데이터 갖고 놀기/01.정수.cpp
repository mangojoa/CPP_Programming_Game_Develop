#include <iostream>

using namespace std;

/* [22.07.24] 디스어셈블리 ctrl+alt+D
int main() {
    cout << "Hello, Would!";
}
이렇게 간단한 실행문을 어셈블리 언어로 풀어서 볼 수 있는 기능이다.
*/

/* [22.07.24] data와 bss
0이 아닌 초기화 값이 있으면 .data 영역
int hp = 100;

초기값이 0이거나, 초기값이 없는 변수라면 .bss 영역
int hp = 0;
int hp

정수를 선언하는 다양한 방법 ?!
char a;  // 1바이트 (-127 ~ 127)
short b; // 2바이트 (-32768 ~ 327467)
int c;   // 4바이트 (-21.4억 ~ 21.4억)
__int64 d; // 8바이트 (어마어마함 ... 그냥 엄청 큼)

unsigned (- 영역을 사용하지 않고 0 부터 사용한다는 의미)
ex) unsigned char a; unsigned short b;

왜 이렇게 선언하는 방법이 다른것인가?
이는 변수라는 개념의 상자가 있다면 이 상자의 틀이 다른 개념이다.
*/

int main() {
    cout << "dd";
}