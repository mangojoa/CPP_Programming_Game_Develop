#include <iostream>
using namespace std;

/* 연산자 오버로딩
일단 [연산자 함수]를 정의해야 한다.
연산자 함수는 두 가지 방식으로 만들 수 있다.

연산자도 함수처럼 오버로딩을 통해 새롭게 재정의할 수 있다.

연산자 함수 기본 문법
Type function_name(Arg_List) {  } 으로 사용하는데 이를 실전에서 사용해보자. */

/* 전역 연산자 함수
전역함수로 선언을 하면 피연산자에 대한 제약을 벗어나게 된다. */
Position operator+(int a, const Position& b) {
    Position ret;

    ret._x = b._x + a;
    ret._y = b._y + a;

    return ret;
}

/* 맴버 연산자 함수(a op b)
왼쪽을 기준으로 실행된 (a가 클래스여아 가능, a를 '기준 피연산자'라고 함)
한계) a가 클래스가 아니면 사용할 수 없다. */
class Position {
public:
    /* 기본 문법에서는 function_name 이라고 설명했지만 보통은 operator[연산자]로 사용된다.
    Type의 경우 해당 클래스의 이름을 넣어주면 된다. */
    Position operator+(const Position& arg) {
        Position pos;
        pos._x = _x + arg._x;
        pos._y = _y + arg._y;
        return pos;
    }

    // 다른 형태(인자값이 다른)로 함수를 만들어보자.
    Position operator+(int arg) {
        Position pos;
        pos._x = _x + arg;
        pos._y = _y + arg;
        return pos;
    }

public:
    int _x;
    int _y;
};

int main() {

    Position pos;
    pos._x = 0;
    pos._y = 0;

    Position pos2;
    pos2._x = 1;
    pos2._y = 1;

    /* 기존에 생성된 객체들을 더해서 새로운 객체를 만들려고 할 때, '+' 연산자를 사용하면?
    Position pos3 = pos + pos2; 당연히 되지 않는다. 이는 피연산자에 호환이 되지 않는 연산자이기 때문이다.
    이를 호환하기 위해서는 어떻게 해야하는가? */

    // Position operator+(const Position& arg) {} 작성 후
    Position pos3 = pos + pos2; // 해당 문법이 이상 없음을 볼 수 있다.

    // 하지만 이는 기존의 함수를 사용할 때와 조금 위화감이 드는 방법인데 
    Position pos4 = pos.operator+(pos2); // 이렇게 문법적으로 operator+(const Position& arg)를 작성할 수 있다. (둘다 같은 문법임)

    // 다른 형태로 만든 연산자를 실행해보자
    Position pos5 = pos4 + 1; // 전역 버전으로 만든다면 이는 통과하게 된다.

    // 하지만 이 맴버 연산자 함수의 단점이 존재하는데
    // Position pos6 = 1 + pos5; 이와 같이 피연산자가 뒤에 올 경우에는 작동을 하지 못한다.
    // 그렇다면 이를 해결하는 방법은 무엇인다 -> 바로 전역 연산자 함수를 사용하는 것이다.
    
    
}