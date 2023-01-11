#include <iostream>
using namespace std;

struct StatInfo {
    int hp = 0xAAAAAAAA;
    int attack = 0xBBBBBBBB;
    int defence = 0xDDDDDDDD;
};

int main() {

    /* 몬스터가 최대 1만마리가 생성되어야 한다면 이렇게 무지성으로 변수를 선언하면 미친짓이다.
    StatInfo monster;
    StatInfo monster_2;
    이를 간단하게 사용하는 방법이 바로 '배열'이다. */

    /* 배열 선언하는 방법 = TYPE 이름[갯수];
    배열의 갯수는 상수로 넣어줘야 한다.(VC 컴파일러 기준) */
    const int monsterCount = 10;
    StatInfo monsters[monsterCount];

    /* 여태껏 변수들의 [이름]은 바구니의 이름이었음 */
    int a = 10;

    /* 그런데 배열은 [이름] 조금 다르게 동작한다.
    그럼 배열의 이름은 무엇인가?
    배열의 이름은 곳 배열의 시작 주소를 가리킨다.
    정확히는 시작 위치를 가리키는 type* 포인터를 의미한다.*/
    const int playerCount = 10;
    StatInfo players[playerCount];

    // arr0[ (100, 10, 1) ], arr1[], arr2[], arr3[] ...
    // monster_0[ 주소 ]
    StatInfo* monster_0 = monsters;
    monster_0->hp = 100;
    monster_0->attack = 10;
    monster_0->defence = 1;

    // arr0[ (100, 10, 1) ], arr1[ (200, 20, 2) ], arr2[], arr3[] ...
    // monster_1[ 주소 ]
    StatInfo* monster_1 = monsters + 1; // 포인터의 덧셈은 add의 개념이 아니라 StatInfo 타입의 바구니를 이동하라는 의미
    monster_1->hp = 200;
    monster_1->attack = 20;
    monster_1->defence = 2;

    // 포인터와 참조는 자유자재로 변환 가능하다.
    // arr0[ (100, 10, 1) ], arr1[ (200, 20, 2) ], monster_2.주소[ (300, 30, 3) ], arr3[] ...
    // monster_2[ 주소 ]
    StatInfo& monster_2 = *(monsters + 2);
    monster_2.hp = 300;
    monster_2.attack = 30;
    monster_2.defence = 3;

    // [주의] 이거는 완전 다른 의미이다.
    // arr0[ (100, 10, 1) ], arr1[ (200, 20, 2) ], monster_2.주소[ 내용물 ], arr3[] ...
    /* temp [] 는 앞서 선언한 monsters 와는 다르게 별개의 데이터를 만들어내며
    temp = *(monsters + 2); 를 진행했다고 하더라도 이는 monsters + 2에 있는 내용물을 복사만 해와서 사용할 뿐
    monsters + 2 주소에 값을 넣는 개념이 아니다. */
    StatInfo temp;
    temp = *(monsters + 2);
    temp.hp = 400;
    temp.attack = 40;
    temp.defence = 4;

    // 이를 자동화로 선언해보자.
    for (int i = 0; i < 10; i++) {
        StatInfo& monster = *(monsters + i);
        monster.hp = 100 * (i + 1);
        monster.attack = 10 * (i + 1);
        monster.defence = 1 * (i + 1);
    }

    /* 그런데... *(monsters + i) 너무 불편하고 가독성이 떨어진다.... 더 편한 방법이 없을까?
    바로 '인덱스' 이다.
    배열은 0번 부터 시작 ~ N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
    *(monsters + i) = monsters[i]; */
    for (int i = 0; i < 10; i++) {
        monsters[i].hp = 100 * (i + 1);
        monsters[i].attack = 10 * (i + 1);
        monsters[i].defence = 1 * (i + 1);
    }

    // 배열 초기화 문법 몇가지
    int numbers[5] = {}; // 이는 기본값 0으로 초기화 된다.

}