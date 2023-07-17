#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
using namespace std;

/* ������ ����µ� �־� vector, list������ ��������� ���� �˾ƺ���. */

class Player {
public:
    Player() : _playerId(0) {}
    Player(int playerId) : _playerId(playerId) {}
public:
    int _playerId;
};

int main() {

    /* ���� ������ Player�� vector�� ������ �����̴�.
    ������ �Ʒ��� ���� vector<Plater*> v;�� ������ ���� �� �� �ִ�.

    �� ������������ ������ ���ΰ�?
    -> Player ������ ������ �ϸ� vector �� capacity ������
    vector<Player> v; �� �޸𸮰� ���������� ������ �� �ִ� ���� �����ϱ� ����
    ����ϴ� ���̶� ���� �ȴ�. */
    vector<Player*> v;

    // Player 10���� ����
    for (int i = 0; i < 100000; i++) {
        Player* p = new Player(i);

        v.push_back(p);
    }

    // ������ �÷��̾� 5���� ����
    for (int i = 0; i < 50000; i++) {
        int randIndex = rand() % v.size();

        Player* p = v[randIndex];
        delete p;

        v.erase(v.begin() + randIndex);
    }

    /* ���� vector<Player*> v;�� ��Ȳ�� ���۳� 10������ ������ �迭�� ���� �ȴ�.
    ���ư� �����ð����� ����� vector / list�� ���, searching �� ���� �κ���
    �ſ� ����� ���� �� �� �־���.

    (�Ը� ��������� �� ������ �ſ� ũ��ƽ�ϰ� ���� �� �ۿ� ����.) -> vector / list�� �Ѱ�

    ���� �츮�� ����Ϸ��� �������� �ϳ��� �÷��̾ ã�ƾ��ϴ� ��찡 �߻��Ѵٸ�?

    if (v[index]._playerId == 10000) {
        logic....
    }

    ���� ���� �ۼ��� if���� �ᱹ full scan�� ���� ã�Ƴ����ϴ� ������ �ʿ������� ��ĥ �� �ۿ� ����.

    vector / list�� ġ������ ����
    -> ���ϴ� ���ǿ� �ش��ϴ� �����͸� ������ ã�� �� [����] */

    /* --------------------------------------------------------------------------- */

    /* ���� �����̳�

    map : ���� ���� Ʈ�� (AYL)
    - ��� ��� �� ������ ������� ����ȴ�.
    */

    class Node {
    public:
        Node* _left;
        Node* _right;
        // int     _key;
        // Player* _value;
        // �� �� ���� �����͸� �ϳ��� ��� ����ϴ� ������ pair
        pair<int, Player*> _data;
    };

    // map(Key, Value)�� ���·� ����ȴ�.
    map<int, int> m;

    for (int i = 0; i < 100000; i++) {

        // map�� insert() �� ���, pair�� �޴� ������ Ȯ�εȴ�.
        // pair�� �����ΰ�? -> �� ���� ������ �������� ��� ���� �ȴ�.
        m.insert(pair<int, int>(i, i * 100));
    }

    for (int i = 0; i < 50000; i++) {
        int randValue = rand() % 50000;

        // Erase By Key
        m.erase(randValue);
    }

    // map�� vector / list �� ���� �ſ� ������ ���ϴ� ���� ã�� �� �ִ�.
    // ��� ������ ���ΰ�?
    map<int, int>::iterator findIt = m.find(1000); // find��� �Լ��� �̿��ϸ� �ȴ�.

    if (findIt != m.end()) cout << "find!" << endl;
    else cout << "Not find.." << endl;

    /* findIt �� ��ȯŸ���� �����ΰ�?
    => ���ϴ� ���� ã�� ���, �ش��ϴ� ���� ��ȯ
    => ���ϴ� ���� �� ã�� ���, m.end() ��� ���� ��ȯ

    �̷��� ��ȯ�ϴ� ������ ��Ȯ�ϱ⿡ �� �� �ִ�. */

    // map ��ȸ�ϴ� ���
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {

        // pair�� ���� ��������
        pair<const int, int>& p = (*it);
        int k = p.first;
        int vec = p.second;

        int key = it->first;
        int value = it->second;

        cout << key << " " << value << endl;
    }

    // ������ �߰��ϰ�, ������ �����ϴ� ��ɿ� ���� �˾ƺ���.

    // ù��° ���!
    map<int, int>::iterator findIt = m.find(10000);
    if (findIt != m.end()) {
        findIt->second = 2000;
    }
    else {
        m.insert(make_pair(10000, 10000));
    }

    // �ι�° ���!
    m[5] = 100;

    m.clear();

    /* [] ������ ����� �� ����
    ������ ������� ���� ���� (Key/Value) ������ �����Ͱ� �߰��ȴ�! */
    for (int i = 0; i < 10; i++) {
        cout << m[i] << endl;
    }

    // ���� ������ �ش� �����Ͱ� �����ϴ����� ���θ� �������� �� ���ʿ��� �����Ͱ� �����Ǿ� �޸� ������ ����ų �� �ִ�.
    // �׷��⿡ �������� ������ find()�� �����ؾ� �Ѵٴ� ���̴�.

    return 0;

}