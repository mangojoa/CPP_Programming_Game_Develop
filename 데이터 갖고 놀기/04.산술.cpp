#include <iostream>
using namespace std;

// 데이터의 연산 => 데이터를 가공하는 방법
int a, b;

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
    

}