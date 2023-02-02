#include <iostream>
using namespace std;

/* 객체지향 (Object Oriented Programming)
- 상속성
- 은닉성
- 다형성 등이 존재한다. */

/* 은닉성 = 캡슐화
몰라도 되는 것은 깔끔하게 숨기겠다.
숨겨야 하는 이유?
1. 정말 위험하고 건드리면 안되는 경우
2. 다른 결로로 접근하길 원하는 경우 */

class Car {
	/* 이전까지는 class 내부에 public 으로만 선언했기에 어디에서나 객체를 생성하면 접근이 가능하도록 되어있는 상태이다.
	하지만 이는 괸장히 위험한 상황이다. 알 필요가 있고 없는 기능은 프로젝트를 진행하다보면 생기는데 
	
	이를 관제하지 않는다면 매우 큰일로 번질 수가 있고, 자신이 이무리 '이 기능은 사용하지마세요'라는 뉘앙스의 함수를 생성했더라도
	같이 사람들은 대부분이 이를 알아차리기가 매우 힘들다 그렇기에 이에 대한 규제를 해두어야 한다.

	이를 제한하는 방법으로는 '접근 지정자'라는 개념이 존재한다. [public, protected, private] 에 대한 개념이 존재한다.

	public -> 누구나
	protected -> 하위 클래스만 (자신을 상속받은 하위 클래스만 사용가능하다)
	private -> 누구도 사용 못해! */
public: 
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}
	void TurnKey() {
		RunEngine();
	}

protected:
	void DisassembleCar() {}
	void RunEngine() {}
	void ConnectCircuit() {}

private:
	void DetailEngine() {}

public:

};

class SUV : public Car {
public:
	void RemoteControllerEngine() {

		/* RunEngine을 사용하기 위해서는 RunEngine을 private로 선언한 클래스를 상속받고 있어야 한다.*/
		RunEngine();
	}
};

int main() {

	Car car;
	car.

}