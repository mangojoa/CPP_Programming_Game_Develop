#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/* 오늘의 주제: 중괄호 초기화 { } */

class Knight {
public:

    Knight() {

    }

    Knight(int a, int b) {
        cout << "Knight(int, int)" << endl;
    }

    // A : 클래스에서 initializer_list를 사용하는 방법!
    // 함수의 인자값으로 initializer_list<int> li를 사용하는 것이다.
    Knight(initializer_list<int> li) {
        cout << "Knight(initializer_list)" << endl;
    }

    /* 중괄호 초기화 { } 를 사용하는데 있어 가장 중요한 것은 기존의 생성자와 겹치는 경우를 고려해야한다.
    * 
    * 그렇지 않으면 애써 만든 생성자를 구경조차 하지 못하는 경우가 발생한다.

    어떻게 사용하는 것이 올바를까?

    하실 정답은 없다. => 작성하는 사람 마음이기 때문이다.

    위와 같은 상황도 사실은 
    Knight(initializer_list<int> li) {} 를 삭제한다면 정상으로 돌아간다. 

    container와는 궁합이 매우 좋기 때문에 사용하지 않는 것도 나름의 불편함을 만들기도 한다.
    반대로 사용을 줄인다면 기존의 초기화 일관성이 무너진다.

    즉, 이는 사용하는 사람이 C++ 문법에 얼마나 진보적인 성향을 가지느냐에 따라 달리지곤 한다.... */
};

int main() {

    int a = 0;
    int b(0);
    int c{ 0 };

    Knight k1;
    Knight k2 = k1; // 복사 생성자 (대입 연산자X)

    Knight k3{ k2 };

    int arr[] = { 1, 2, 3, 4 };

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> v2(10, 1);

    // C++는 각각의 초기화 방법이 다 다르다. (이게 제일 문제다...)
    // C++ 11 에서는 이를 간단하게 초기화 할 수 있는 중괄호 초기화 { } 가 등장한다!
    // 이는 container 와 궁합이 매우 좋다!
    vector<int> v3{ 1, 2, 3, 4 };

    // 중괄호 초기화 {}의 장점
    // 1) vector 등 container 와 잘 어울린다.
    vector<int> v4{ 1, 2, 3, 4 };

    // 2) 축소 변환 방지
    int x = 0;
    double y{ x }; // 의도치 않게 진행되는 데이터의 손실을 미연에 방지하는 개념으로 사용할 수 있다!

    // 3) Bonus
    // 아래의 두 개는 전혀 다른 코드이다! (얼핏 비슷한거 같지만 전혀 다르다)
    Knight k4(); // -> 이는 함수를 생성하는 코드로 인식한다.
    Knight k5{ }; // -> 이는 기본 생성자를 호출하는 코드로 인식한다.

    /* ====================================================== */

    // 중괄호 초기화 {}의 단점 
    Knight k6{ }; // -> 위에서 본 것처럼 기본 생성자를 호출한다.

    Knight k7{ 1, 2 };
    /* 하지만 이는 조금 다르게 작동한다.
    vector<int> v3{ 1, 2, 3, 4 };
    위에서 본 것처럼 vector 에는 몇개의 인자를 받아서 생성할지에 대한 정보 없이
    무작위로 넣어서 생성했지만 정상적으로 컴파일러가 인식하는 것을 알 수 있었다.

    왜 일까? => 이는 initializer_list 때문에 그렇다
    initailizer_list는 몇개가 들어올지 모르는 상황
    즉, 이와 같은 초기화 시점에서 사용하기 적합한 기능이다.

    몇 개가 들어오든 이를 하나의 list로 만들어 생성할 수 있도록 한다.
    그렇기에 vector<int> v3{ 1, 2, 3, 4 }; 가 정상적으로 인식된 것이다.

    그럼 이를 class 에선 어떻게 구현하는가? => A 로 */

    /* 그럼 여기서 또 한가지 질문이 든다!
    class Knight {
    public:
        Knight() {}
        Knight(int a, int b) {
            cout << Knight(int, int) << endl;
        }
        Knight(initializer_list<int> li) {
            cout << Knight(initializer_list) << endl;
        }
    }
    1. 인자값 int, int 를 받는 기타 생성자가 호출이 되는가?
    or
    2. 인자값이 initializer_list인 생성자가 호출이 되는가?

    가슴이 웅장해지는 대결 속에서 승자는? => 2번 (우선순위가 높기 때문에)
    하지만 이로 인해서 문제가 발생하는 것은 애써 만들어둔 기타 생성자를 사용할 수 없다는 것이다… */

    return 0;
}