#include <iostream>
using namespace std;

// 포인터 실습

struct StatInfo {
    int hp;
    int atteck;
    int defence;
};

void EnterLobby();
// pointer를 배우기 이전에 사용한 함수
StatInfo CreatePlayer();
// pointer를 배운 후의 사용한 함수
void CreateMonster(StatInfo* info);

bool StartBattle(StatInfo* player, StatInfo* monster);


int main() {
    EnterLobby();
}

void EnterLobby() {
    cout << "로비에 입장했습니다." << endl;

    StatInfo player;
    player.hp = 0xbbbbbbbb;
    player.atteck = 0xbbbbbbbb;
    player.defence = 0xbbbbbbbb;

    /* CreatePlayer(); 의 작동원리를 파해치자
    [매개변수][RET][지역변수(temp(100, 10, 2), player(100, 10 2))] 
    CreatePlayer() 함수 안의 지역변수로 생성된 ret에 담긴 값을 return 하는 원리로 작동하며

    [매개변수(&temp)][RET][지역변수(ret(100, 10, 2))]
    return 값으로 받은 값을 player()에 복사하는 과정이 진행된다.

    기존의 방법은 어셈블리 언어로 살펴볼때 상당히 많은 복사과정을 거쳐서 진행되는데
    이는 현재 player에 많은 정보가 없기에 문제가 되지는 않지만, MMORPG의 경우에는 
    palyer의 정보는 매우 방대하기에 이 방법으로 진행을 하다가는 부하를 일으킬 수 있는 단점이 존재한다.
    */
    player = CreatePlayer();

    StatInfo monster;
    monster.hp = 0xbbbbbbbb;
    monster.atteck = 0xbbbbbbbb;
    monster.defence = 0xbbbbbbbb;
    /* CreateMonster(); 의 작동원리를 파해치자
    [매개변수][RET][지역변수(monster(40, 8, 1))]
    info->hp = 40;
    info->atteck = 8;
    info->defence = 1;
    안에서 다음과 같이 주소값에 직접 복사하여 넣고 있는 과정을 거치고 있기 때문에 
    CreatePlayer(); 와 달리 복사과정이 많지 않다는 것이 가장 큰 차이점이다.

    [매개변수(&monster)[RET][지역변수()]]
    어셈블리 언어적인 코드가 CreatePlayer();에 비해 적다는 것과 동시에
    지역분수를 사용하지 않음으로써 메모리적인 부분에서도 효율적이며 
    무엇보다 메모리 주소값에 직접넣기에 유용하다.(하지만 잘못될 경우 이만큼 위험한 것도 없다는 점이다.)
    */
    CreateMonster(&monster);

    bool victory = StartBattle(&player, &monster);

    if (victory) cout << "victory!" << endl;
    else cout << "lose!" << endl;

}

StatInfo CreatePlayer() {
    StatInfo ret;
    
    cout << "플레이어 생성" << endl;

    ret.hp = 100;
    ret.atteck = 10;
    ret.defence = 2;

    return ret;
}

void CreateMonster(StatInfo* info) {
    
    cout << "몬스터 생성" << endl;
    
    // 간접 맴머 연산자를 사용하여 간단하게 진행할 수 있다.
    info->hp = 40;
    info->atteck = 8;
    info->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster) {
    while(true) {
        int damage = player->atteck - monster->defence;
        if (damage < 0) damage = 0;

        monster->hp -= damage;
        if (monster->hp < 0) monster->hp = 0;

        cout << "몬스터 HP : " << monster->hp << endl;

        if (monster->hp = 0) return true;

        damage = monster->atteck - player->defence;
        if (damage < 0) damage = 0;

        cout << "플레이어 HP : " << player->hp << endl;

        player->hp -= damage;

        if (player->hp < 0) player->hp = 0;

        if (player->hp == 0) return false;
    }
}