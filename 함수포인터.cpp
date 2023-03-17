#include <iostream>
using namespace std;

/* STL을 배우기 위해서는 함수포인터를 알고 가야하기 때문에
함수포인터를 배워보도록 하자. */

int Add(int a, int b) {
    return a + b;
}

int main() {

    // 일반적인 포인터 선언
    int a = 3;
    typedef int DATA;
    DATA* pointer = &a;

    /* 함수를 포인터에 담는다는 개념을 어떻게 이해해야 하는것인가?
    함수로 존재하는 int Add(int a, int b) {}
    
    포인터를 선언하는데 있어 필요한 데이터타입, 변수명, 포인터 이 3요소가 갖추어져야 
    정상적으로 작동하게 된다. 

    일반적으로 포인터를 선언하게 될때, 변수명과 포인터는 걱정이 되지 않지만
    함수를 담는 포인터를 만든다고 할때, 이를 어떻게 표현해야하는지가 의문이다.

    일반적인 포인터 -> int* pointer = &value;
    위의 방법처럼 함수를 담는 포인터는 선언할 수가 없기에 
    typedef [TYPE] [NAME]; 형태를 사용해야 한다. */
    
    typedef int(FUNC_TYPE)(int a, int b);
    /* 일반적인 typedef [TYPE] [NAME]; 형태와는 다른 모습으로 선언된다.
    이는 함수의 input / output 값을 명확히 하기위해서 형태가 다른것이다.

    매칭하기 위함 함수 -> int Add(int a, int b) {} 자체를 타입으로 지정하기 위해
    그 형태 자체에 담긴 input / output 형태를 typedef에 작성한다고 보면 된다. */

    using FUNC_TYPE = int(int a, int b); // 모던 C++에서 사용하는 방식

    // 위에서 typedef를 통한 함수의 타입을 지정했다.
    FUNC_TYPE* fn; // 변수명과 포인터를 붙이면 함수를 담을 수 있는 포인터를 선언한 것이다.

    // 이를 어떻게 사용해야 하는가?
    fn = Add;
    /* type이 일치하는 함수를 함수포인터 안에 넣어주면 된다.
    type이 일치해야 한다는 점이 번거로울 수 있으나 
    함수를 포인터 형태로 담을 수 있다는 점이 엄청난 이점으로 다가올 것이다. */

    int result = fn(1, 60); // 원래는 Add를 사용하여 인자값을 더했지만 
    // 이제는 Add를 담은 fn으로도 충분히 진행할 수 있다.

    int result2 = (*fn)(1, 40); // 이렇게 사용할 수도 있다.

}