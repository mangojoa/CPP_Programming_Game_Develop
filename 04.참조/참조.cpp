#include <iostream>
using namespace std;

/* ������ ����
call by value / call by reference �� ���Ͽ�
*/

struct Statinfo {
    int hp;
    int attact;
    int defence;
};

// ���� �����ϴ� ���,

// [�Ű�����][RET][��������(info)] [�Ű�����(&info)][RET][��������]
void CreateMonster(Statinfo* info) {
    info->hp = 100;
    info->attact = 20;
    info->defence = 10;
}

// [�Ű�����][RET][��������(info)] [�Ű�����(info(199, 19, 9))][RET][��������]
void CreateMonster(Statinfo info) {
    info.hp = 199;
    info.attact = 19;
    info.defence = 9;
}

// ���� �������� �ʴ´ٸ�, ���� �� �ϴ� ������ ����.

// 1) �� ���� ���
// [�Ű�����][RET][��������(info)] [�Ű�����(info(           ))][RET][��������]
void PrintInfobyCopy(Statinfo info) {
    cout << "------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATT : " << info.attact << endl;
    cout << "DEF : " << info.defence << endl;
    cout << "------------" << endl;
}

// 2) �ּ� ���� ���
// [�Ű�����][RET][��������(info)] [�Ű�����(&info)][RET][��������]
void PrintInfobyPtr(Statinfo* info) {
    cout << "------------" << endl;
    cout << "HP : " << info->hp << endl;
    cout << "ATT : " << info->attact << endl;
    cout << "DEF : " << info->defence << endl;
    cout << "------------" << endl;
}

/* Statinfo ����ü�� 1000����Ʈ ¥�� ���� �������?
- (�� ����) Statinfo�� �ѱ�� 1000����Ʈ�� ���ø޸𸮿� ���簡 ����Ǳ⿡ ��û�� ���ɺ��ϰ� �Ͼ��.
- (�ּ� ����) Statinfo*�� 8����Ʈ
- (���� ����) Statinfo&�� 8����Ʈ
*/


/* 3) ���� ���� ���
�� ���� ó�� ���ϰ� ����ϰ� ! �ּ� ����ó�� �ְ��� �̿��� ��¥�� �����ϴ� �ϼ������� ����� ������ �� �ִ�.
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

    // �������� = �ο췹��(�����) �������� ���� �۵� ����� int*�� �Ȱ���.
    // ������ �����غ��� �����Ͷ� 100% �Ȱ��ٰ� ����ȴ�.
    int& reference = number;

    /* C++ �������� �ٶ󺼶� reference ??
    number ��� �ٱ��Ͽ� reference ��� �ٸ� �̸��� ����� ������ �޾Ƶ鿩���Ѵ�.
    ������reference �ٱ��Ͽ� �� �����ų� ������,
    ���� number �ٱ���(��¥)�� �� ���� �����ų� �ְ� �ִٴ� ���̴�.
    */
    reference = 3;

    // ������ �׷��ٸ� �����Ϳ� ������ ������ ������ �����ΰ�?
    // ���� ���޿� ���� ���̰� �����ϱ⿡ �̸� ������ ���̴�!

    Statinfo info;
    CreateMonster(&info);

    PrintInfobyCopy(info);
    PrintInfobyPtr(&info);
    PrintInfobyRef(info);
}
