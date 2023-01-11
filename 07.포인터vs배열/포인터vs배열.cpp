#include <iostream>
using namespace std;

/* 포인터와 배열의 차이에 대하여

const char* test1 = "Hello, World";
char test2[] = "Hello, World";
이 부분만 보면 포인터와 배열이 같은 것으로 착각할 수 있다. (실제로 다르다.)
*/

void Test(char a[]) { // 우리가 아무리 배열로 인자값을 작성하더라도 컴파일러는 이를 포인터로 치환한다.
    // 즉 배열의 내용 전체를 넘긴게 아니라, 시작주소(포인터)만 넘긴 것
    a[0] = 'x';
}

int main() {

    const char* test1 = "Hello World";
    /* 이를 어셈블리 언어로 알아보자!
    dword ptr [test1].offwet string "Hello World" (09E9B30h)

    09E9B30h 해당 주고에 있는 아스키 코드로 저장된 "Hello World"를 가져다가 test1에 넣어주는 모습을 볼 수 있다.
    */

    char test2[] = "Hello World";
    /* 이를 어셈블리 언어로 알아보자!
    eax, dword ptr [string "Hello World" (09E9B30h)]
    dword ptr [test2],eax

    ecs, dword ptr ds:[9E9B34h]
    dword ptr [ebp-18h],ecx

    edx, dword ptr ds:[9E9B38h]
    dword ptr [ebp-14h],edx

    이는 char 타입의 바이트(4byte) 만큼을 복사하여 여러차레 넣어주는 모습을 보여준다.

    1. 배열은 바구니가 생성되는 개념이 아니다. 포인터는 이에 비해 바구니를 생성한다.

    포인터 => 주소를 담는 바구니
    배열 => 그 자체로 같은 데이터끼리 붙어있는 '바구니 모음'
            - 다만 [배열 이름]은 '바구니 모음'의 [시작 주소]

    지금 포인터는 const 형태로 생성되어 있지만 배열은 그렇지 않다.
    이는 데이터를 접근하여 바꿀 수 있다는 것이 차이도 드러날 수 있다. 
    test1[1] = 'T';
    test2[1] = 'A';

    이를 실행하면 pointer로 선언한 test1의 경우, 수정되지 않는다.
    하지만 Array로 선언한 test2의 경우, 해당 값에 'e' -> 'A'로 수정된 것을 확인할 수 있다. 
    (이는 함수에서도 마찬가지로 작용한다.) */

    // Test() 함수에 넣은 tset2[]은 과연 어떻게 될까? -> 그 값은 변하게 된다.
    // 이를 어셈블리 언어로 풀어본다면 일반적인 포인터를 넘기는 방식과 비슷한 양상을 보인다.
    Test(test2);

}