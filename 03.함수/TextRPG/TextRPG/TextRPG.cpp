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

// �κ� ����������,
void EnterLobby();

// ĳ���͸� �����Ҷ�,
void SelectPlayer();

// �ʵ� ���� ���θ� �����Ҷ�,
void EnterField();

// �ʵ忡�� ���� ���͸� ������ ��,
void CreateRandomMonster();

// ���Ϳ� ��ȥ�� �´��̸� �Ҷ�,
void EnterBattle();

int main() {
    
    srand(time(0));
    EnterLobby();

}

void EnterLobby() {
    
    while (true) { 
        cout << "---------------------------" << endl;
        cout << "�κ� �����ϼ̽��ϴ�." << endl;
        cout << "---------------------------" << endl;

        // �÷��̾� ���� ����
        SelectPlayer();

        cout << "---------------------------" << endl;
        cout << "[1] �ʵ� ���� [2] ���� ����" << endl;
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
        cout << "������ ����ּ���!" << endl;
        cout << "[1] Knight [2] Archer [3] Mage" << endl;
        cout << "> ";

        cin >> playerType;

        if (playerType == PT_Knight) {

            cout << "Knight ������....." << endl;
            hp = 150;
            attact = 10;
            defence = 10;
            break;
        }
        else if (playerType == PT_Archer) {
        
            cout << "Archer ������....." << endl;
            hp = 100;
            attact = 15;
            defence = 3;
            break;
        }
        else if (playerType == PT_Mage) {

            cout << "Mage ������....." << endl;
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
        cout << "�ʵ忡 �����߽��ϴ�!" << endl;
        cout << "---------------------------" << endl;

        cout << "[PLAYER] HP : " << hp << " / ATT : " << attact << " / DEF : " << defence << endl;

        CreateRandomMonster();
        
        cout << "---------------------------" << endl;
        cout << "[1] ���� [2] ����" << endl;
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
        cout << "Slime ������....! (HP:15 / ATT: 5 / DEF: 0)" << endl;
        monsterHp = 15;
        monsterAttact = 5;
        monsterDefence = 0;
        break;
    case MT_Orc:
        cout << "Orc ������....! (HP:40 / ATT: 10 / DEF: 3)" << endl;
        monsterHp = 40;
        monsterAttact = 10;
        monsterDefence = 3;
        break;
    case MT_Skeleton:
        cout << "Slime ������....! (HP:80 / ATT: 15 / DEF: 5)" << endl;
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

        cout << "���� ���� ü�� : " << monsterHp << endl;

        // ������ ü���� 0�� �Ǿ� óġ�Ǿ��ٸ�
        if (monsterHp == 0) {
            cout << "���͸� óġ�߽��ϴ�!" << endl;
            return;
        }

        // ������ ü���� 0�� ���� �ʾҴٸ�
        damage = monsterAttact - defence;
        if (damage < 0) damage = 0;

        // ������ �ݰ�
        hp -= damage;
        if (hp < 0) hp = 0;

        cout << "�÷��̾� ���� ü�� : " << hp << endl;

        if (hp == 0) {
            cout << "����� ����߽��ϴ�..GAME OVER" << endl;
            return;
        }
    }
}