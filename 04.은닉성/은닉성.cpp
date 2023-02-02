#include <iostream>
using namespace std;

/* ��ü���� (Object Oriented Programming)
- ��Ӽ�
- ���м�
- ������ ���� �����Ѵ�. */

/* ���м� = ĸ��ȭ
���� �Ǵ� ���� ����ϰ� ����ڴ�.
���ܾ� �ϴ� ����?
1. ���� �����ϰ� �ǵ帮�� �ȵǴ� ���
2. �ٸ� ��η� �����ϱ� ���ϴ� ��� */

class Car {
	/* ���������� class ���ο� public ���θ� �����߱⿡ ��𿡼��� ��ü�� �����ϸ� ������ �����ϵ��� �Ǿ��ִ� �����̴�.
	������ �̴� ������ ������ ��Ȳ�̴�. �� �ʿ䰡 �ְ� ���� ����� ������Ʈ�� �����ϴٺ��� ����µ� 
	
	�̸� �������� �ʴ´ٸ� �ſ� ū�Ϸ� ���� ���� �ְ�, �ڽ��� �̹��� '�� ����� �������������'��� ���ӽ��� �Լ��� �����ߴ���
	���� ������� ��κ��� �̸� �˾������Ⱑ �ſ� ����� �׷��⿡ �̿� ���� ������ �صξ�� �Ѵ�.

	�̸� �����ϴ� ������δ� '���� ������'��� ������ �����Ѵ�. [public, protected, private] �� ���� ������ �����Ѵ�.

	public -> ������
	protected -> ���� Ŭ������ (�ڽ��� ��ӹ��� ���� Ŭ������ ��밡���ϴ�)
	private -> ������ ��� ����! */
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

		/* RunEngine�� ����ϱ� ���ؼ��� RunEngine�� private�� ������ Ŭ������ ��ӹް� �־�� �Ѵ�.*/
		RunEngine();
	}
};

int main() {

	Car car;
	car.

}