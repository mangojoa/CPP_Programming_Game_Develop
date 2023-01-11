#include <iostream>
using namespace std;

struct Player {
    int hp;
    int damege;
};

/* 포인터 연산
1. 주소 연산자 (&)
2. 산술 연산자 (+ -)
3. 간접 연산자 (*)
4. 간접 맴버 연산자 (->)
*/

int main() {

    int number = 1;

    /* 1) 주소 연산자(&)
    - 해당 변수의 주소를 알려준다.
    - 더 정확히 말하면 해당 변수 타입(type)에 따라서 type* 반환
    */

    int* pointer = &number;

    /* 2) 산술 연산자 (+ -)
    - 변수를 다룰때 배운 산술연산자와 사용법은 같다고 볼 수 있다.
    - 더 정확히는 포인터에서 주소값의 '값'을 바꾸는 역할이 아니다.
    - 포인터에 담긴 주소의 위치를 변경하는데 사용된다.

    int number = 1;
    int* pointer = &number;
    *pointer += 1;

    주소값의 '값'을 변경하는게 아닌 int(4byte 정수형 바구니)의 위치를 이동하는 개념이라는 것이다.

    즉, *number의 type만큼의 메모리 이동이 이루어지는 것이다.
    */
    * pointer += 1;

    /* 3) 간접 연산자 (*)
    - 포탈을 타고 해당 주소로 이동하는 개념
    */
    number = 3;
    *pointer = 3;

    // 구조체로 선언해둔 Player가 일반적으로 int main() 에서 사용될 때의 모습니다.
    Player player;
    player.hp = 100;
    player.damege = 10;

    /* 간접 연산자를 통해 선언해둔 구조체에 접근할 수 있다.
    (*[구조체 클래스 변수])를 선언 후 .을 통해 Player를 접근할 수 있다.
    */
    Player* playerPtr = &player;
    (*playerPtr).hp = 200;
    (*playerPtr).damege = 20;


    /* 4) 간접 맴버 연산자 (->)
    - * 와 . 의 개념을 동시에 실행할 수 있는 개념
    - . 구조체의 특정 맴버를 다룰 때 사용(어셈블리 언어로 까보면 . 사실상 그냥 덧셈의 개념)
    */

    playerPtr->hp = 200;
    playerPtr->damege = 200;

}