#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
using namespace std;

/* 게임을 만드는데 있어 vector, list만으로 어려운지에 대해 알아보자. */

class Player {
public:
    Player() : _playerId(0) {}
    Player(int playerId) : _playerId(playerId) {}
public:
    int _playerId;
};

int main() {

    /* 위에 설계한 Player를 vector로 생성할 차례이다.
    하지만 아래에 보면 vector<Plater*> v;로 선언한 것을 볼 수 있다.

    왜 포인터형으로 선언한 것인가?
    -> Player 형으로 선언을 하면 vector 의 capacity 때문에
    vector<Player> v; 의 메모리가 가변적으로 변동될 수 있는 것을 방지하기 위해
    사용하는 것이라 보면 된다. */
    vector<Player*> v;

    // Player 10만명 입장
    for (int i = 0; i < 100000; i++) {
        Player* p = new Player(i);

        v.push_back(p);
    }

    // 임의의 플레이어 5만명 퇴장
    for (int i = 0; i < 50000; i++) {
        int randIndex = rand() % v.size();

        Player* p = v[randIndex];
        delete p;

        v.erase(v.begin() + randIndex);
    }

    /* 이제 vector<Player*> v;의 상황은 구멍난 10만개의 데이터 배열인 셈이 된다.
    나아가 지난시간부터 배워온 vector / list의 경우, searching 에 대한 부분이
    매우 취약한 것을 알 수 있었다.

    (규모가 방대해지면 이 문제는 매우 크리틱하게 번질 수 밖에 없다.) -> vector / list의 한계

    만약 우리가 사용하려는 로직에서 하나의 플레이어를 찾아야하는 경우가 발생한다면?

    if (v[index]._playerId == 10000) {
        logic....
    }

    위와 같이 작성될 if문은 결국 full scan을 통해 찾아내야하는 과정을 필연적으로 거칠 수 밖에 없다.

    vector / list의 치명적인 단점
    -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 [없다] */

    /* --------------------------------------------------------------------------- */

    /* 연관 컨테이너

    map : 균형 이진 트리 (AYL)
    - 노드 기반 의 데이터 구조라고 보면된다.
    */

    class Node {
    public:
        Node* _left;
        Node* _right;
        // int     _key;
        // Player* _value;
        // 위 두 개의 데이터를 하나로 묶어서 사용하는 개념의 pair
        pair<int, Player*> _data;
    };

    // map(Key, Value)의 형태로 저장된다.
    map<int, int> m;

    for (int i = 0; i < 100000; i++) {

        // map의 insert() 의 경우, pair를 받는 것으로 확인된다.
        // pair는 무엇인가? -> 한 쌍의 데이터 묶음형태 라고 보면 된다.
        m.insert(pair<int, int>(i, i * 100));
    }

    for (int i = 0; i < 50000; i++) {
        int randValue = rand() % 50000;

        // Erase By Key
        m.erase(randValue);
    }

    // map은 vector / list 에 비해 매우 빠르게 원하는 값을 찾을 수 있다.
    // 어떻게 가능한 것인가?
    map<int, int>::iterator findIt = m.find(1000); // find라는 함수를 이용하면 된다.

    if (findIt != m.end()) cout << "find!" << endl;
    else cout << "Not find.." << endl;

    /* findIt 의 반환타입은 무엇인가?
    => 원하는 값을 찾은 경우, 해당하는 값을 반환
    => 원하는 값은 못 찾은 경우, m.end() 라는 값을 반환

    이렇게 반환하는 개념이 명확하기에 할 수 있다. */

    // map 순회하는 방법
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {

        // pair를 통해 참조값을
        pair<const int, int>& p = (*it);
        int k = p.first;
        int vec = p.second;

        int key = it->first;
        int value = it->second;

        cout << key << " " << value << endl;
    }

    // 없으면 추가하고, 있으면 수정하는 기능에 대해 알아보자.

    // 첫번째 방법!
    map<int, int>::iterator findIt = m.find(10000);
    if (findIt != m.end()) {
        findIt->second = 2000;
    }
    else {
        m.insert(make_pair(10000, 10000));
    }

    // 두번째 방법!
    m[5] = 100;

    m.clear();

    /* [] 연산자 사용할 때 주의
    대입을 사용하지 않을 때도 (Key/Value) 형태의 데이터가 추가된다! */
    for (int i = 0; i < 10; i++) {
        cout << m[i] << endl;
    }

    // 위의 방법대로 해당 데이터가 존재하는지의 여부를 진행했을 때 불필요한 데이터가 생성되어 메모리 누수를 일으킬 수 있다.
    // 그렇기에 데이터의 유무는 find()로 접근해야 한다는 것이다.

    return 0;

}