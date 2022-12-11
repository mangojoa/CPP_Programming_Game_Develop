#include <iostream>
using namespace std;

enum PlayerType {
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3
};

enum MonsterType {
    MT_Slime = 1,
    MT_Orc = 2,
    MT_Skeleton = 3
};

int playerType;
int hp;
int attact;
int defence;

int monsterType;
int monsterHp;
int monsterAttact;
int monsterDefence;

// 로비에 입장했을때,
void EnterLobby();

// 캐릭터를 선택할때,
void SelectPlayer();

// 필드 입장 여부를 선택할때,
void EnterField();

// 필드에서 랜덤 몬스터를 생성할 때,
void CreateRandomMonster();

// 몬스터와 영혼의 맞다이를 할때,
void EnterBattle();

int main() {
    
    srand(time(0));
    EnterLobby();

}

void EnterLobby() {
    
    while (true) { 
        cout << "---------------------------" << endl;
        cout << "로비에 입장하셨습니다." << endl;
        cout << "---------------------------" << endl;

        // 플레이어 직업 선택
        SelectPlayer();

        cout << "---------------------------" << endl;
        cout << "[1] 필드 입장 [2] 게임 종료" << endl;
        cout << "---------------------------" << endl;

        int input;

        cin >> input;

        if (input == 1) {
            EnterField();
        }
        else {
            return;
        }

    }

}

void SelectPlayer() {
    while (true) {

        cout << "---------------------------" << endl;
        cout << "직업을 골라주세요!" << endl;
        cout << "[1] Knight [2] Archer [3] Mage" << endl;
        cout << "> ";

        cin >> playerType;

        if (playerType == PT_Knight) {

            cout << "Knight 생성중....." << endl;
            hp = 150;
            attact = 10;
            defence = 10;
            break;
        }
        else if (playerType == PT_Archer) {
        
            cout << "Archer 생성중....." << endl;
            hp = 100;
            attact = 15;
            defence = 3;
            break;
        }
        else if (playerType == PT_Mage) {

            cout << "Mage 생성중....." << endl;
            hp = 80;
            attact = 25;
            defence = 0;
            break;
        }

    }
}

void EnterField() {
    
    while (true) {
        cout << "---------------------------" << endl;
        cout << "필드에 입장했습니다!" << endl;
        cout << "---------------------------" << endl;

        cout << "[PLAYER] HP : " << hp << " / ATT : " << attact << " / DEF : " << defence << endl;

        CreateRandomMonster();
        
        cout << "---------------------------" << endl;
        cout << "[1] 전투 [2] 도주" << endl;
        cout << "> " << endl;

        int input;
        cin >> input;

        if (input == 1) { 
            EnterBattle();
            if (hp == 0) return;
        }
        else return;
    }

}

void CreateRandomMonster() {
    
    monsterType = 1 + (rand() % 3);

    switch (monsterType)
    {
    case MT_Slime:
        cout << "Slime 생성중....! (HP:15 / ATT: 5 / DEF: 0)" << endl;
        monsterHp = 15;
        monsterAttact = 5;
        monsterDefence = 0;
        break;
    case MT_Orc:
        cout << "Orc 생성중....! (HP:40 / ATT: 10 / DEF: 3)" << endl;
        monsterHp = 40;
        monsterAttact = 10;
        monsterDefence = 3;
        break;
    case MT_Skeleton:
        cout << "Slime 생성중....! (HP:80 / ATT: 15 / DEF: 5)" << endl;
        monsterHp = 80;
        monsterAttact = 15;
        monsterDefence = 5;
        break;
    }

}

void EnterBattle() {
    while (true) {
        int damage = attact - monsterDefence;
        if (damage < 0) damage = 0;

        monsterHp -= damage;
        if (monsterHp < 0) monsterHp = 0;

        cout << "몬스터 남은 체력 : " << monsterHp << endl;

        // 몬스터의 체력이 0이 되어 처치되었다면
        if (monsterHp == 0) {
            cout << "몬스터를 처치했습니다!" << endl;
            return;
        }

        // 몬스터의 체력이 0이 되지 않았다면
        damage = monsterAttact - defence;
        if (damage < 0) damage = 0;

        // 몬스터의 반격
        hp -= damage;
        if (hp < 0) hp = 0;

        cout << "플레이어 남은 체력 : " << hp << endl;

        if (hp == 0) {
            cout << "당신은 사망했습니다..GAME OVER" << endl;
            return;
        }
    }
}