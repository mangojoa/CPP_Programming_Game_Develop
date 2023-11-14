#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/* ������(rvalue) ������ std::move
* 
* lvalue(�ް�) / rvalue(������) �̶� �����ΰ�?
* 
* - lvalue : ���Ͻ��� �Ѿ ��� ���ӵǴ� ��ü
* - rvalue : lvalue�� �ƴ� ������ (�ӽ� ��, ������, ����, i++ ��) */

class Knight {
public:

public:
	int _hp = 100;
};

/* void TestKnight_Copy(Knight knight) {  }
���� ����� ���, Knight Ŭ������ ���� �����ڸ� ���ؼ� ����Ǵ� ���μ����̴�.

���� ���� �ȿ��� ���� ���� �����ϴ��� ���� k1���� � ���⵵ �� �� ������ 

Knight Ŭ������ �ܼ��ϸ� ��������� ���� (������� ������ ����)
�ſ� ������ Ŭ������� �̴� ū ������� ��ġ�� ġ������ �������� �ۿ��� �� �ִ� �������� �ۿ��� �� �ִ�. */
void TestKnight_Copy(Knight knight) {  }

/* ������ �̸� ������ (Ȥ�� ������)�� �̿��ؼ� �����Ѵٸ� �̾߱Ⱑ �ٸ���.
why? -> �켱������ ���簡 �̷������ ������ �ƴ� ����(Ȥ�� ���ڰ��� �ش��ϴ� ������ / �������� ���� ��ġ)�� 
���������� �����ϴ� ������ �۵��Ѵ�. (�̸� �ް�������� �Ѵ�.) 

�� lvalue�� �ش��ϴ°�?
-> ���������� ���� ��ü�� �ش�Ǵµ� ���⼭�� Knight�� �ش�ȴ�. 
�ӽ������� ���� Ŭ������ �ƴϸ� ������ Knight ������ ������(Ȥ�� ������)�� �̿�

��, ���������� ���� ��ü�� �ش��ϹǷ� lvalue!! */
void TestKnight_LValueRef(Knight& knight) {  }
void TestKnight_ConstLValueRef(const Knight& knight) {  }

void TestKnight_RValueRef(Knight&& knight) {  }

int main() {

	Knight k1;

	TestKnight_Copy(k1); // �Ϲ� ��������� �̿�
	TestKnight_LValueRef(k1); // lvalue ���� (������/������) ���

	{
		void TestKnight_LValueRef(Knight & knight);
		TestKnight_LValueRef(Knight());
	}
	/* �׷� �̹����� Knight()��� �ӽð��� ���ڷ� �־�ٸ� ��� �ɱ�?
	
	�����Ϸ��� "��const ������ ���� �ʱ� ���� lvalue���� �մϴ�." ��� Error ������ ����ϰ� �ִ�. 

	�� �̷��� ����� �Ǵ� ���ΰ�?
	���� �����Ϸ��� ���ϰ� �ִ� ����ó�� ������ �츮�� ����ϴ� ��κ��� �Լ��� lvalue�� �������� ���ڰ��� �־���Ѵ�.

	������ ���� ����ϴ� Knight() ��� ���ڰ��� �ӽ����� Knight class�� �ӽ� �⺻ �����ڿ� �ش��Ѵ�.
	�Լ�(TestKnight_LValueRef)�� ����� ���� ���ڰ����� ���� Knight class�� �ӽ� �⺻ �����ڴ� ������⿡ lvalue�� �ش����� �ʾƼ�
	�����Ϸ��� ������ �����ϰ��� ���к� ������ �ϰ� �ִ� ���̴�.

	�����Ϸ� : ��~ �� �������� */

	/* �׷� �̸� ����� �� �ִ� ����� �������� �ʴ� ���ΰ� ?
	-> �����Ѵ�. ������ �̴� "��const ������ ���� �ʱ� ���� lvalue���� �մϴ�." Error�� �ݴ�� �ؼ��ϸ� �ȴ�.

	�� const ������ ���� �ʱ� ���� rvalue���� �մϴ�. ��� ����� ���´�.

	�׷� �̸� ������Ѻ���. */
	{
		void TestKnight_ConstLValueRef(const Knight & knight);
		TestKnight_ConstLValueRef(Knight());
	}
	/* �Լ��� ���ڰ��� const�� �޴´ٸ� ���� ������ ���� ������ �� �� �ִ�.
	������ const�� ����� ���ڰ��̹Ƿ� �������� �۾��� ������ �� ����. (readonly ����)
	{ logic.. } �ȿ��� ������ ������ ��� �����Ϸ��� ���� ���� �� �� �ִ�....

	�׷��⿡ �б������� �۾��� ������ �� �ִٴ� ����¥�� �Լ��� �Ǵ� ���̴�. */

	{ // �Ʒ��� �� �Լ��� ���� ���� �ǹ��Ѵ�.
		void TestKnight_ConstLValueRef(const Knight & knight);
		void TestKnight_RValueRef(Knight && knight);
	}
	TestKnight_RValueRef(Knight()); 

	return 0;
}