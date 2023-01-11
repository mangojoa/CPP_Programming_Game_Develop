#include <iostream>
using namespace std;

struct StatInfo {
    int hp = 0xAAAAAAAA;
    int attack = 0xBBBBBBBB;
    int defence = 0xDDDDDDDD;
};

int main() {

    /* ���Ͱ� �ִ� 1�������� �����Ǿ�� �Ѵٸ� �̷��� ���������� ������ �����ϸ� ��ģ���̴�.
    StatInfo monster;
    StatInfo monster_2;
    �̸� �����ϰ� ����ϴ� ����� �ٷ� '�迭'�̴�. */

    /* �迭 �����ϴ� ��� = TYPE �̸�[����];
    �迭�� ������ ����� �־���� �Ѵ�.(VC �����Ϸ� ����) */
    const int monsterCount = 10;
    StatInfo monsters[monsterCount];

    /* ���²� �������� [�̸�]�� �ٱ����� �̸��̾��� */
    int a = 10;

    /* �׷��� �迭�� [�̸�] ���� �ٸ��� �����Ѵ�.
    �׷� �迭�� �̸��� �����ΰ�?
    �迭�� �̸��� �� �迭�� ���� �ּҸ� ����Ų��.
    ��Ȯ���� ���� ��ġ�� ����Ű�� type* �����͸� �ǹ��Ѵ�.*/
    const int playerCount = 10;
    StatInfo players[playerCount];

    // arr0[ (100, 10, 1) ], arr1[], arr2[], arr3[] ...
    // monster_0[ �ּ� ]
    StatInfo* monster_0 = monsters;
    monster_0->hp = 100;
    monster_0->attack = 10;
    monster_0->defence = 1;

    // arr0[ (100, 10, 1) ], arr1[ (200, 20, 2) ], arr2[], arr3[] ...
    // monster_1[ �ּ� ]
    StatInfo* monster_1 = monsters + 1; // �������� ������ add�� ������ �ƴ϶� StatInfo Ÿ���� �ٱ��ϸ� �̵��϶�� �ǹ�
    monster_1->hp = 200;
    monster_1->attack = 20;
    monster_1->defence = 2;

    // �����Ϳ� ������ ��������� ��ȯ �����ϴ�.
    // arr0[ (100, 10, 1) ], arr1[ (200, 20, 2) ], monster_2.�ּ�[ (300, 30, 3) ], arr3[] ...
    // monster_2[ �ּ� ]
    StatInfo& monster_2 = *(monsters + 2);
    monster_2.hp = 300;
    monster_2.attack = 30;
    monster_2.defence = 3;

    // [����] �̰Ŵ� ���� �ٸ� �ǹ��̴�.
    // arr0[ (100, 10, 1) ], arr1[ (200, 20, 2) ], monster_2.�ּ�[ ���빰 ], arr3[] ...
    /* temp [] �� �ռ� ������ monsters �ʹ� �ٸ��� ������ �����͸� ������
    temp = *(monsters + 2); �� �����ߴٰ� �ϴ��� �̴� monsters + 2�� �ִ� ���빰�� ���縸 �ؿͼ� ����� ��
    monsters + 2 �ּҿ� ���� �ִ� ������ �ƴϴ�. */
    StatInfo temp;
    temp = *(monsters + 2);
    temp.hp = 400;
    temp.attack = 40;
    temp.defence = 4;

    // �̸� �ڵ�ȭ�� �����غ���.
    for (int i = 0; i < 10; i++) {
        StatInfo& monster = *(monsters + i);
        monster.hp = 100 * (i + 1);
        monster.attack = 10 * (i + 1);
        monster.defence = 1 * (i + 1);
    }

    /* �׷���... *(monsters + i) �ʹ� �����ϰ� �������� ��������.... �� ���� ����� ������?
    �ٷ� '�ε���' �̴�.
    �迭�� 0�� ���� ���� ~ N��° �ε����� �ش��ϴ� �����Ϳ� �����Ϸ��� �迭�̸�[N]
    *(monsters + i) = monsters[i]; */
    for (int i = 0; i < 10; i++) {
        monsters[i].hp = 100 * (i + 1);
        monsters[i].attack = 10 * (i + 1);
        monsters[i].defence = 1 * (i + 1);
    }

    // �迭 �ʱ�ȭ ���� ���
    int numbers[5] = {}; // �̴� �⺻�� 0���� �ʱ�ȭ �ȴ�.

}