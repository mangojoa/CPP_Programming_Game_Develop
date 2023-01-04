#include <iostream>
using namespace std;

/* 포인터 vs 참조 에 대하여
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

// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수]
void PrintInfo(Statinfo* info) {
    cout << "------------" << endl;
    cout << "HP : " << info->hp << endl;
    cout << "ATT : " << info->attact << endl;
    cout << "DEF : " << info->defence << endl;
    cout << "------------" << endl;

    /*
    info[주소값]
    info = &globalInfo;

    const를 별 뒤에 붙인다면? => Statinfo* const info 
    info라는 바구니의 내용물(주소)을 바꿀 수 없게 된다.
    info는 주소값을 갖는 바구니 -> 이 주소값이 고정이다.

    주소값[데이터]
    info->hp = 10000;

    const를 별 앞에 붙인다면? => const Statinfo* info
    info 가 '가리키고 있는' 바구니의 내용물을 바꿀 수 없게 된다.
    주소값의 '원격' 바구니의 내용물을 바꿀 수 없다.
    
    */
}

void PrintInfo(Statinfo& info) {
    cout << "------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATT : " << info.attact << endl;
    cout << "DEF : " << info.defence << endl;
    cout << "------------" << endl;
}

int main() {
    Statinfo info;

    /* 포인터 vs 참조 세기의 대결
    성능 = 똑같음!
    편의성 = 참조가 포인터에 비해 사용성이 더 좋다. (이는 극히 개인의 차이)
    
    1) 편의성 관련
    편의성이 좋다는게 꼭 장점만은 아니다.

    우리가 일상에서 코드를 작성하다보면 함수의 이름/인자값만 보고 어떠한 로직이 실행되어서
    데이터의 주소에 있는 원본 데이터를 조작하는 여부를 알기란 어렵다. 
    
    극적으로 설명을 해본다면 포인터와 참조를 사용하는 함수의 이름이 같다고 가정할 때, 
    우리는 인자값을 보거나 함수에 온마우스를 통해 함수의 내용을 알 수 있다.

    포인터 함수 -> 포인터 주소를 인자값으로 받기에 확실하게 원본을 건드린다는 힌트를 내포하고 있다.
    참조 함수 -> 이는 인자값이 일반적인 함수의 인자값과 다를바가 없이 생겼다.
                (정말 비교해본다면 이를 온마우스를 하거나 직접 찾지 않고서는 알 수 없다.)

    이를 매번 확인하면서 하더라도 휴먼(?)에러가 나기 십상이기에 
    확실하게 하기 위해서는 하나의 규칙이 필요하다.
    

    ex ) 만약 간단하게 프린트만 하는 printinfo() 라는 함수에서 data의 원본값을 건드리게 된다면 ?
    상당히 난감해진다.... 프린트만 하도록 작성한 printinfo() 함수에서 느닷없이 값을 변경하는 로직이 들어가있다면
    누가 작성했는지 모르겠지만 혼내주고 싶을 것이다.

    그렇기에 이러한 불상사(?)를 막기 위해서는 const(상수화)를 통해 방지할 수 있다. 

    여기서 중요한 점은 const를 어디에 선언하느냐가 중요하다.
    */


    CreateMonster(&info);

    PrintInfo(&info);

    PrintInfo(info);
}
