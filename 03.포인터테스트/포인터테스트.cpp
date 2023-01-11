#include <iostream>
using namespace std;

// ������ �ǽ�

struct StatInfo {
    int hp;
    int atteck;
    int defence;
};

void EnterLobby();
// pointer�� ���� ������ ����� �Լ�
StatInfo CreatePlayer();
// pointer�� ��� ���� ����� �Լ�
void CreateMonster(StatInfo* info);

bool StartBattle(StatInfo* player, StatInfo* monster);


int main() {
    EnterLobby();
}

void EnterLobby() {
    cout << "�κ� �����߽��ϴ�." << endl;

    StatInfo player;
    player.hp = 0xbbbbbbbb;
    player.atteck = 0xbbbbbbbb;
    player.defence = 0xbbbbbbbb;

    /* CreatePlayer(); �� �۵������� ����ġ��
    [�Ű�����][RET][��������(temp(100, 10, 2), player(100, 10 2))]
    CreatePlayer() �Լ� ���� ���������� ������ ret�� ��� ���� return �ϴ� ������ �۵��ϸ�

    [�Ű�����(&temp)][RET][��������(ret(100, 10, 2))]
    return ������ ���� ���� player()�� �����ϴ� ������ ����ȴ�.

    ������ ����� ����� ���� ���캼�� ����� ���� ��������� ���ļ� ����Ǵµ�
    �̴� ���� player�� ���� ������ ���⿡ ������ ������ ������, MMORPG�� ��쿡��
    palyer�� ������ �ſ� ����ϱ⿡ �� ������� ������ �ϴٰ��� ���ϸ� ����ų �� �ִ� ������ �����Ѵ�.
    */
    player = CreatePlayer();

    StatInfo monster;
    monster.hp = 0xbbbbbbbb;
    monster.atteck = 0xbbbbbbbb;
    monster.defence = 0xbbbbbbbb;
    /* CreateMonster(); �� �۵������� ����ġ��
    [�Ű�����][RET][��������(monster(40, 8, 1))]
    info->hp = 40;
    info->atteck = 8;
    info->defence = 1;
    �ȿ��� ������ ���� �ּҰ��� ���� �����Ͽ� �ְ� �ִ� ������ ��ġ�� �ֱ� ������
    CreatePlayer(); �� �޸� ��������� ���� �ʴٴ� ���� ���� ū �������̴�.

    [�Ű�����(&monster)[RET][��������()]]
    ����� ������� �ڵ尡 CreatePlayer();�� ���� ���ٴ� �Ͱ� ���ÿ�
    �����м��� ������� �������ν� �޸����� �κп����� ȿ�����̸�
    �������� �޸� �ּҰ��� �����ֱ⿡ �����ϴ�.(������ �߸��� ��� �̸�ŭ ������ �͵� ���ٴ� ���̴�.)
    */
    CreateMonster(&monster);

    bool victory = StartBattle(&player, &monster);

    if (victory) cout << "victory!" << endl;
    else cout << "lose!" << endl;

}

StatInfo CreatePlayer() {
    StatInfo ret;

    cout << "�÷��̾� ����" << endl;

    ret.hp = 100;
    ret.atteck = 10;
    ret.defence = 2;

    return ret;
}

void CreateMonster(StatInfo* info) {

    cout << "���� ����" << endl;

    // ���� �ɸ� �����ڸ� ����Ͽ� �����ϰ� ������ �� �ִ�.
    info->hp = 40;
    info->atteck = 8;
    info->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster) {
    while (true) {
        int damage = player->atteck - monster->defence;
        if (damage < 0) damage = 0;

        monster->hp -= damage;
        if (monster->hp < 0) monster->hp = 0;

        cout << "���� HP : " << monster->hp << endl;

        if (monster->hp = 0) return true;

        damage = monster->atteck - player->defence;
        if (damage < 0) damage = 0;

        cout << "�÷��̾� HP : " << player->hp << endl;

        player->hp -= damage;

        if (player->hp < 0) player->hp = 0;

        if (player->hp == 0) return false;
    }
}