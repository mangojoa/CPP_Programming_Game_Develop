#include <iostream>
using namespace std;

/* 변수와 포인터
기존의 변수의 경우, '변수'라는 '바구니'에 값을 저장하는 개념으로 진행해왔다.

하지만 포인터의 경우는 다르다.
포인터를 선언하는 방법에 대하여 => TYPE* 변수이름;
포인터의 경우, '*포인터'라는 '바구니'에 '값의 주소'를 저장하는 개념이다. / 포인터는 '주소'를 의미한다.

모든 변수는 메모리에 저장이 되는데 해당 변수는 모두 '주소값'을 가지고 있다.
즉, 모든 변수는 '값' 과 '주소값'을 가지고 있다.
*/

/* 포인터는 주소를 통해 접근하기 때문에 이제 지역변수의 제약에서 벗어날 수 있다. 
void setHp (int hp) 라는 함수에서 아무리 hp변수를 조작한다고 한들 달라지는 것은 없었다.

하지만 인자값이 void setHp(int* hp)로 바뀐다면 이야기는 달라진다. */
void setHp (int* hp) { 
    *hp = 100;
}

int main() {

    int hp = 1;
    setHp(&hp);
    /* 기존 지역변수들의 경우, 해당 지역 외에서는 컨트롤이 되지 않았다.
    하지만 위처럼 setHp(&hp) hp의 주소값을 넣어 보내게 된다면
    void setHp(int* hp)에서 인자값인 int* hp = &hp; 의 형태로 생성이 되어 

    *hp = 100; 구문이 직접적으로 int hp의 값을 바꾸는 결과를 만들 수 있다.
    이처럼 지역/전역변수의 장벽을 허무는 역할을 할 수 있지만 
    그와 동시에 상당한 리스크를 동반할 수 있기에 포인터 사용은 언제나 유심있게 보아야한다.
    */

    int number = 1;
    int* ptr = &number;

    /* 위와 같이 변수를 생성했다면 '값'과 '주소값'을 가지고 있다.
    type* 변수이름; 의 방식으로 생성했다면 = &변수 를 통해 주소값을 저장할 수 있다.

    포인터의 개념이 많이 생소할 수 있다. 하지만 그렇다고 헷갈릴 요소를 
    참고) 포인터라는 바구니는 4바이트(32비트) or 8바이트(64비트) 고정 크기
    */

    /* 그럼 여기서 한가지 의문이 들기 마련이다.
    포인터에는 왜 type를 선언해야하는가.
    
    포인터는 주소를 담아둔 변수인데 이를 사용하는 방법에 따라 type를 선언해주어야 한다.
    예를 들어, int number = 1; 이라고 선언한 변수를 저장한 *ptr이라는 포인터가 
    number의 주소에 들어있는 값을 정상적으로 사용하기 위해서는 
    number에 담긴 값과 같은 타입으로 선언하여 사용해야 한다는 것이다.
    (해당 변수에 담긴 데이터를 int로 볼 것이냐를 저장해주는 것이다.)

    앞서 배운 개념을 토대로 "데이터를 어떻게 분석하느냐에 따라서 의미가 달라진다." 라는 뜻이 적용이 된다.

    변수를 선언하고 포인터로 읽어들일 때, 
    1바이트 2바이트 4바이트 8바이트이냐에 따라서 의미가 완전히 달라질 수 있다는 것이다.
    */
    int* ptr2;

    /* 변수와 포인터의 타입 불일치 
    int number = 2; (int = 4byte)

    __int64_t* ptr3 = (__int64_t*)&number; (__int64_t = 64byte)
    
    이렇게 서로 다른 타입로 선언시 문제가 발생한다.

    우선적으로 광대한 메모리 안에는 다양한 정보의 메모리가 자리잡고 있다.
    각각의 영역에는 중요한 데이터를 저장하고 있다. 
    각 영역을 침범하는 사태가 발생하면 문제가 발생하는데 그런 경우가 이 포인터를 조작하는데 있어 발생한다.

    대부분의 변수와 포인터의 타입을 맞추는 경우가 일반적이다. (하지만 경우에 따라 달라질 수 있다.)

    분명 int number는 4byte 영역을 메모리에 할당한다.
    하지만 포인터로 받은 __int64_t* ptr3는 64byte 영역을 차지한다.

    이와 근접한 부분에 유저의 재화를 관리하는 부분이 있다고 한다면 해당영역까지 침범할 수 있게 된다.

    즉, *ptr3 = 0xAABBCCDDEEFF; 라는 값을 넣게 된다면 4byte에 해당하는 영역을 초과하는 사태가 발생하게 된다는 것이다.
    
    그렇기에 변수와 포인터의 타입을 맞추어서 영역을 침범하는 일은 없도록 해야한다는 것이다.
    */
    __int64_t* ptr3 = (__int64_t*)&number;

    *ptr2 = 0xAABBCCDDEEFF;

}