#include <iostream>
using namespace std;

// 데이터의 연산 => 데이터를 가공하는 방법
int a, b;

// 비교 연산을 위한 변수
bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

// 논리 연산을 위한 변수
int hp = 100;
bool actor;
bool isInvincible;

// 비트 연산을 위한 변수
bool stunned;
bool polymorph;

// 비트 플래그를 위한 변수
unsigned char flag; // 부호를 없애야 >> 를 하더라도 부호비트가 딸려오지 않음

int main() {
    
    // 대입연산
    a = b;
    
    // 사칙연산 
    a = b + 3;
    a = b - 3;
    a = b * 3;
    a = b / 3;
    a = b % 3;

    // 증감연산
    a = a + 1;
    a++;
    ++a;
    a--;
    --a;

    b = a++;
    b = ++a;

#pragma region 비교연산
    /* 이는 언제 필요한 것인가 
    판별이 필요한 상황에 전반적으로 사용된다고 보면 된다.
    ex) HP가 0이 된 상황 / 버프가 들어온 상황 등

    a == b : a와 b의 값이 같은가?*/
    isSame = (a == b);
    
    // a != b : a와 b의 값이 다른가?
    isDifferent = (a != b);

    // isSame 과 isDiffernt 는 상반되는 개념이다.

    // a > b : a가 b보다 큰가? / a >= b : a가 b보다 크거나 같은가?
    isGreater = (a > b);

    // a < b : a가 b보다 작은가? / a <= b : a가 b보다 작거나 같은가?
    isSmaller = (a < b);

#pragma endregion

#pragma region 논리연산 

    /* 언제 필요한가?
    조건에 대한 논리적 사고가 필요할 때 전반적으로 사용
    ex) 로그인할 때 회원의 정보가 일치할때 
    */

    // ! not 
    actor = !isSame;

    // && and 
    actor = (hp < 0 && isInvincible == false);
    
    // || or
    actor = (hp > 0 || isInvincible == true);

#pragma endregion

#pragma region 비트 연산

    /*
    언제 비트연산을 사용하는가 ??? (사실 많이 사용하지는 않는다)
    비트 단위의 조작이 필요한 상황에 쓰인다
    대표적으로 BitFlag 에 사용된다.
    */

    /*
    - bitwise not 
    단일 숫자의 모든 비트를 대상으로 모든 자리의 값을 뒤바꿈

    & bitwise and
    두 숫자의 모든 비트 쌍을 대상으로 and를 진행한다. (둘다 1이면 1, 다르면 0)

    | bitwise or
    두 숫자의 모든 비트 쌍을 대상으로 or를 진행한다. (bitwise and 와 상반되는 개념이다.)

    ^ bitwise xor
    두 숫자의 모든 비트 쌍을 대상으로 xor를 진행한다. (둘다 1이면 0, 다르면 1)

    << 비트 좌측 이동
    비트열을 n만큼 왼쪽으로 이동 
    왼쪽의 넘치는 n개의 비트는 버리고 새로 생성되는 n개의 비트는 0
    *2를 할 때 자주 보이는 패턴

    >> 비트 우측 이동 
    비트열을 n만큼 오른쪽으로 이동
    오른쪽의 넘치는 n개의 비트는 버리고, 왼쪽 생성되는 n개의 비트는 
    - 부호 비트가 존재할 경우 부호 비트를 따라간다 (부호 없는 정수라면 이 부분을 유의)
    - 아니면 0 

    일반적인 숫자의 경우, 대부분이 0 이라는 경우이다.
    부호가 따라가는 현상을 막기위해서는 unsigned로 선언하는 것이 바람직하다.
    */

    /* 실습 비트 플래그를 이용한 상태이상 개념을 표현하기
    
    Ob0000 [무적][변이][스턴][공중부양]
    0000 0[무적]0[변이]0[스턴]0[공증부양] 를 나타내도록 한다고 가졍하자.
    0000 1000 이라면 [무적]이 활성화 된 것으로 간주한다. (나머지도 해당 데이터가 1인 경우 같다고 본다.)

    그럼 여기서 비트 플래그를 왜 사용해야 하는가 ??
    게임에서는 언제나 메모리를 과다하게 사용할 수 밖에 없기에 
    이에 대한 최적화(다양한 의미가 될 수 있지만 어디까지나 메모리를 최소한의 조건으로 사용한다는 가정이라고 하겠다.)를 진행해야한다.

    이때 비트 플래그의 개념을 이용한다면 매우 유용하다.

    일반적으로 이를 변수의 개념으로 사용한다면? 해당 상태이상에 따른 변수 생성, 레지스터, 메모리 등 ... 사용될 부분이 많다.
    하지만 변수를 생성한다는 개념에서 이미 위의 상태이상 4개를 전부 생성한다? => 변수 4개 생성
    비트 플래그를 통해 상태이상을 제어한다? => 변수 1개 생성 

    최적화의 이름에 걸맞게 변수를 생성하는 것 부터 다르다. (물론 자세한 내용까지 보면 더 심오하겠지 ..)
    그렇기에 비트 플래그를 사용하는 것이다.

    다시 실습으로 넘어가자. 
    */

    // 무적 상태로 만든다. 
    flag = 8; // 이렇게 선언을 하면 무적 상태로 만들 수 있게 된다.

    /*
    하지만 이는 bite 개념이기에 실전에서 사용하기엔 부적합하다. (보통은 qword를 사용한다고 한다.)
    그렇기에 이에 비트 연산자를 더해 사용한다면
    위와 다르게 1을 왼쪽으로 << 3 칸이동한다는 식으로 표현했다.
    의미는 같으나 전달에 있어 용이함을 나타낸다. */
    flag = (1 << 3); 

    // 변이 상태를 추가한다 ( 무적 + 변이 )
    flag |= (1 << 2);

    // 무적인지 확인하고 싶을 땐 ? (다른 상태는 무시한다.)
    // bitmask (원하는 값을 추출할 때 사용함)
    bool invincible = (flag & (1 << 3)) != 0;
   
    // 무적이거나 스턴 상태인지 확인하고 싶다면?
    bool stunOrinvincible = ((flag & 0b1010) != 0);
   

#pragma endregion
}