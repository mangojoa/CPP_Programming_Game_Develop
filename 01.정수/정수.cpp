#include <iostream>

using namespace std;

/* [22.07.24] 디스어셈블리 ctrl+alt+D
int main() {
    cout << "Hello, Would!";
}
이렇게 간단한 실행문을 어셈블리 언어로 풀어서 볼 수 있는 기능이다.
*/

int hp = 100;

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

참고) 이론적으로 양수만 존재할 수 있는 데이터 unsigned
무조건 unsigned를 사용할지 의견이 갈림
- 레벨이 음수라는 것은 말이 안된다. -> 그럼 차라리 그 자리에서 프로그램을 크래시 내서 버그를 빨리 찾는게 낫다.
- unsigned / sgined 사이의 변환이 필요

귀찮은데 그냥 대충 4바이트로 가면 안되는 것인가?
-> 콘솔/모바일 게임 = 메모리가 늘 부족한 상황이 놓인다.
-> 온라인 게임 = 4바이트 * 1만명
*/

char a;
short b;
int c;
__int64 d;

unsigned char ua;
unsigned short ub;
unsigned int uc;
unsigned __int64 ud;

int main() {
    // 정수 오버플로우
    b = 32767;
    b = b + 1;
    cout << b << endl; // -32768

    // 정수 언더플로우
    ub = 0;
    ub = ub - 1;
    cout << ub << endl;

    cout << "체력이 " << hp << " 남았습니다." << endl;
}