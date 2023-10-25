#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/* enum class (scoped enum)
1) 이름 공간 관리 (scoped)
*/

/* 기존에 사용되던 enum class의 문제점 ?!
우선적으로 앞에 PT_ 라는 네이밍 규칙이 적용되어 작성되어왔다.

하지만 굳이 그렇게 작성할 필요가 있는가?

이 안에서 나이트면 나이트 인건데! 하는 생각을 할 수 있다.
(하지만 과거에 만들어진 C++는 그리 상냥한 편이 아니다...)

PlayerType에서 Knight를 선언한 후,
MonsterType에서 Knight(몬스터)를 선언했다고 해보자.
(일반적인 개념으로 공간이 아예 다른 곳에 선언한 변수이기에
다른 값으로 인식할 것으로 기대할 수 있으나 현실을 컴파일러가 통과시켜주지 않는다.)
-> 재정의된 '열거자' 라고 Error가 출력된다.

그래서 과거에 사용된 enum class의 이름을 unscoped enum이라고 한다. */

enum PlayerType {
    Knight,
    Archer,
    Mage
};

enum MonsterType {
    Knight,
    Archer
};
// 위의 unscoped enum 의 경우 같은 네이밍이 다른 영역에 선언되었음에도 실행되기 전까지는
// Error임을 알 수 없다. (그렇기에 앞에 enum의 네이밍 규칭이 필수적으로 동반되어야 공간 분리가 진행된다.)

// 하지만 enum class 의 경우, 
// 다른영역에 같은 네이밍으로 선언해도 무리가 없다. (범위가 정해진 영역에서만 유효하다는 의미)
enum class PlayerType01 {
    Knight,
    Archer,
    Mage
};

enum class MonsterType01 {
    Knight,
    Archer,
    Mage
};

int main() {

    /* 공간분리가 정상적으로 이루어졌다 한들 단점은 언제나 따라다니기 마련이다.
    2) 암묵적인 변환 금지
    Enum Class 에서 선언된 변수들의 값은 int형으로 1씩 증가하는 구조로 되어있다.

    하지만 이를 다음과 같이 캐스팅을 한다고 하면 어떻게 될까? */
    double value = PlayerType01::Knight;
    /* 분명 PlayerType01::Knight 의 값은 0 이지만 이를 double로 변환할 수 없다.
    Enum Class 에서는 암묵적인 변환(케스팅)이 금지되어 있기 때문이다.

    이는 Enum Class가 Enum 에 비해 단점이 될 수 있는 부분이라고 생각할 수 있다.

    물론 처음에는 그렇게 생각했으나 귀찮은 과정을 더하므로써 완벽에 기할 수 있다는 생각이
    실수를 줄일 수 있는 하나의 장치가 될 수 있겠다는 것으로 인해 

    이러한 방법도 결코 틀린 건 아니라는 것을 알게 되었다. */

    double value = static_cast<double>(PlayerType01::Knight);




    return 0;
}