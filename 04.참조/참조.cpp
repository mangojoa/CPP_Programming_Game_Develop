#include <iostream>
using namespace std;

/* 참조의 개념
call by value / call by reference 에 대하여
*/

struct Statinfo {
    int hp;
    int attact;
    int defence;
};

// 값을 수정하는 경우,

// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수]
void CreateMonster(Statinfo* info) {
    info->hp = 100;
    info->attact = 20;
    info->defence = 10;
}

// [매개변수][RET][지역변수(info)] [매개변수(info(199, 19, 9))][RET][지역변수]
void CreateMonster(Statinfo info) {
    info.hp = 199;
    info.attact = 19;
    info.defence = 9;
}

// 값을 수정하지 않는다면, 양쪽 다 일단 문제가 없다.

// 1) 값 전달 방식
// [매개변수][RET][지역변수(info)] [매개변수(info(           ))][RET][지역변수]
void PrintInfobyCopy(Statinfo info) {
    cout << "------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATT : " << info.attact << endl;
    cout << "DEF : " << info.defence << endl;
    cout << "------------" << endl;
}

// 2) 주소 전달 방식
// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수]
void PrintInfobyPtr(Statinfo* info) {
    cout << "------------" << endl;
    cout << "HP : " << info->hp << endl;
    cout << "ATT : " << info->attact << endl;
    cout << "DEF : " << info->defence << endl;
    cout << "------------" << endl;
}

/* Statinfo 구조체가 1000바이트 짜리 대형 구조라면?
- (값 전달) Statinfo로 넘기면 1000바이트가 스택메모리에 복사가 진행되기에 엄청난 성능부하가 일어난다.
- (주소 전달) Statinfo*는 8바이트
- (참조 전달) Statinfo&는 8바이트
*/


/* 3) 참조 전달 방식
값 전달 처럼 편리하게 사용하고 ! 주소 전달처럼 주고값을 이용해 진짜를 조작하는 일석이조의 방식을 진행할 수 있다.
*/
void PrintInfobyRef(Statinfo& info) {
    cout << "------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATT : " << info.attact << endl;
    cout << "DEF : " << info.defence << endl;
    cout << "------------" << endl;
}




int main() {

    int number = 1;

    // 참조전달 = 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같다.
    // 실제로 실행해보면 포인터랑 100% 똑같다고 보면된다.
    int& reference = number;

    /* C++ 관점에서 바라볼때 reference ??
    number 라는 바구니에 reference 라는 다른 이름을 명명한 것으로 받아들여야한다.
    앞으로reference 바구니에 뭘 꺼내거나 넣으면,
    실제 number 바구니(진짜)에 그 값을 꺼내거나 넣고 있다는 것이다.
    */
    reference = 3;

    // 하지만 그렇다면 포인터와 참조를 나누는 이유는 무엇인가?
    // 참조 전달에 대한 차이가 존재하기에 이를 나누는 것이다!

    Statinfo info;
    CreateMonster(&info);

    PrintInfobyCopy(info);
    PrintInfobyPtr(&info);
    PrintInfobyRef(info);
}
