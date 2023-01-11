#include <iostream>
using namespace std;

int MultiplyBy(int a, int b) {
    int c = a + b;

    return c;

}

/* 실행을 위한 다양한 옵션
F5 디버깅 모드 실행 (브레이크 포인트까지 / 없으면 계속 진행)
F10 프로시저 단위 실행 (함수 단위로 실행 / main() 에서만 진행되는 개념)
F11 한 단계씩 코드 실행 (인스트럭선 단위로 진행 / 함수 안으로도 진입하여 결과들의 진행을 알 수 있다.) */

int main() {
    /* 스택 프레임에 대하여... (함수를 실행했을때, 어떤 원리로 진행되는지 자세하게 알아보자!)
    높은 메모리 주소 -> 낮은 주소로 증가했다가 줄어드는 개념

    스택 메모리 영역(함수들 끼리 사용하는 메모장의 개념)은 어떻게 생성되는가 ?
    => 프로그램이 실행될 때, 얼마만큼의 스택을 줄 수 있는지 할당해준다.

    ex) main() => func01() => func02()
    한 영역(main과 같은)에는 [매개변수, 반환주소값, 지역변수]가 할당되어 있다.

    [증가영역]
    main()에서 func01()를 호출하는 경우, 매개변수를 보내고 반환주소값을 저장하며, func01()의 스택메모리 영역이 형성된다.

    [감소영역]
    func02() 에서 프로세스가 마무리 되면 반환값을 들고 func01()의 반환주소값을 통해 func01()의 스택메모리 영역으로 돌아간다.*/

    int a = 3;
    int b = 5;

    /* 이제 자세히 알아보자!

    int result = MultiplyBy(b, a) 함수가 실행될 때, 우선 매개변수를 오른쪽기준으로 먼저 넣는다.
    레지스터를 알고 싶다면, ctrl + alt + g 를 통해 확인할 수 있다.
    mov eax, dword ptr [a]
    push eax
    mov ecx, dword ptr [b]
    push ecx

    MultiplyBy을 call 하고 난 후,
    call MultiplyBy (07114ABh)

    반환 주소값을 넣어줘야한다.
    add esp, 8

    이후, MultiplyBy를 call한 스택 메모리 영역으로 들어가보면
    -----------------------------------
    jmp MultiplyBy (0712570h)

    이전 베이스 포인터의 주소값을 push해서 보관하고 있는다. = 이전 스택 메모리 영역의 반환주소값에 해당한다.
    push ebp

    MultiplyBy의 스택 프레임을 관리하는 부분이다.
    mov ebp, esp
    sub ebp, 0CCh

    내부적으로 사용할 변수에 대한 영역을 할당하는 공간을 할당한다.

    MultiplyBy 안의 int c = a + b;
    mov eax,dword ptr [a]
    imul ecx,dword ptr [b]
    mov dword ptr [c], eax

    retun c;
    mov eax, dword ptr [c]

    사용한 스택 프레임을 정리하는 구간
    add esp, 0CCh
    cmp ebp, esp
    ret 해당하는 주소로 이동한다는 의미

    -----------------------------------
    MultiplyBy 스택 프레임 영역으로 돌아와서 이후 진행할 MultiplyBy 영역을 마저 진행한다고 보면 된다.

    add esp, 8

    메모리를 잘못 조작할 경우, 크러시가 나거나 문제가 발생할 수 있다.
    그렇기에 메모리의 동작 방식에 대한 숙지가 필수적으로 요구된다. ( C++는 메모리를 조작할 수 있는 특징이 있기 때문이다. )


    */
    int result = MultiplyBy(b, a);

    return 0;
}