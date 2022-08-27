#include <iostream>
using namespace std;

// 데이터의 연산 => 데이터를 가공하는 방법
int a, b;

// 비교 연산을 위한 변수
bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

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



#pragma endregion
}