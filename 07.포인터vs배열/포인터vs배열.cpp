#include <iostream>
using namespace std;

/* 포인터와 배열의 차이에 대하여

const char* test1 = "Hello, World";
char test2[] = "Hello, World";
이 부분만 보면 포인터와 배열이 같은 것으로 착각할 수 있다. (실제로 다르다.)
*/

int main() {

    const char* test1 = "Hello, World";
    /* 이를 어셈블리 언어로 알아보자!
    dword ptr [test1].offwet string "Hello World" (09E9B30h)

    09E9B30h 해당 주고에 있는 아스키 코드로 저장된 "Hello World"를 가져다가 test1에 넣어주는 모습을 볼 수 있다.
    */

    char test2[] = "Hello, World";
    /* 이를 어셈블리 언어로 알아보자!
    eax, dword ptr [string "Hello World" (09E9B30h)]
    dword ptr [test2],eax

    ecs, dword ptr ds:[9E9B34h]
    dword ptr [ebp-18h],ecx

    edx, dword ptr ds:[9E9B38h]
    dword ptr [ebp-14h],edx

    09E9B30h 해당 주소에 있는 아스키 코드로 저장된 "Hello World"를 가져다가 test1에 넣어주는 모습을 볼 수 있다.
    */

}