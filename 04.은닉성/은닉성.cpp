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

/* 상속 접근 지정자 => 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하진 않는다. 
그렇기에 public / protected / private 이 존재한다. */

class SUV : public Car {
public:
	void RemoteControllerEngine() {

		/* RunEngine을 사용하기 위해서는 RunEngine을 private로 선언한 클래스를 상속받고 있어야 한다.*/
		RunEngine();
	}
};

/* '캡슐화'
연관된 데이터와 함수를 논리적으로 묶어놓은 것 */
class Berserker {

	/* 캡슐화를 진행해야하는 이유가 무엇인가?
	
	이 class의 경우, _hp가 50이하로 떨어지게 되면 기존 능력치가 강해지는 로직이 실행된다고 하자.
	하지만 이를 int main() {...} 에서 관리하게 된다면 기존의 관리자는 알고 있겠지만

	다른 사람이나 새로운 사람들은 이지하지 못하고 해당 로직을 변경 or 삭제를 진행할 수 도 있다. 
	(매우 위험하고 올바르지 못한 상황이라고 볼 수 있다.)

	그렇기에 캡슐화라는 개념이 진행되어야 한다는 것이다. 

	public으로 class의 값을 접근해서 마음대로 수정을 하게 된다면 누구나 쉽게 이를 조작할 수 있다.
	그렇기에 이를 private로 선언하고 호출하고 실행하는 부분을 따로 만들어야 한다는 것이다. 

	Get/Set 이라는 개념이 존재하는데 접근할 때는 SET / 호출할 때는 GET의 개념을 적용한다는 것이다.

	int GetHp() / int SetHp(인자값) 으로 구성해서 사용해보자. */
public:
	int GetHp() { return _hp; }
	int SetHp(int hp) {
		_hp = hp;
		if (_hp <= 50) SetBerserkerMode();
	}

	/* 이전까지 배운대로라면 SetBerserkerMode() 와 int _hp는 public으로 선언하여 쉽게 접근했지만
	
	이제는 GET / SET 개념을 이용해서 int _hp에 따라 달라지는 로직을 작성했다.

	이는 private 로 선언했기에 더이상 밖에서는 이를 부를 수 없다.

	하지만 이제 SetHp(int hp) {} 를 통해서 b.SetHp(20);를 실행하면 private _hp와 SetBerserkerMode()를 실행할 수 있다.

	그럼과 동시에 안전하게 데이터를 불러와 로직을 실행할 수 있게 된다.
	*/
	
private:
	void SetBerserkerMode() {
		cout << "매우 강해집니다!" << endl;
	}
private:
	int _hp = 100;
};

int main() {

	Car car;
	car.TurnKey();

	Berserker b;
	b._hp = 20;
	if (b._hp > 50) b.SetBerserkerMode();

	b.SetHp(20);

}