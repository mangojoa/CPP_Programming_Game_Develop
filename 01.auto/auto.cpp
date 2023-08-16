#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Knight {
public:
	int _hp;
};

int main() {

	// Modern C++ (C++ 11)

	/*int a = 3;
	float b = 3.14f;
	double c = 1.23;
	Knight d = Knight();
	const char* e = "dusan";*/

	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = Knight();
	auto e = "dusan";

	// auto �� ������ ��Ŀī�� ���� �����̴�.
	// ���� ����(type deduction)
	// -> ���� �ǰ� �� ���纸������~~~ (�߷��� �ؾ��ϴ� �������� ���� �ȴ�.)
	// ���α׷��� ������������ �߷��ϱⰡ ����� �� �� �ִ�. 

	auto f = &d;
	const auto test1 = b;
	const auto* test2 = e; // ��� ������ ���콺�� ������ ��� Ÿ���� �� �� �ִ�.

	// auto �� ��� ���� Ŀ���� �� �ִ� ���� �ƴϴ�. 
	// ������� ���� �Ǿ�� �̸� Ŀ�����ִ� �����̶�� ����ȴ�.

	// auto* test3 = d; ��� �Ѵٸ� �����Ϸ��� ������ ����Ʈ�� ���̴�.
	// �̴� auto �� ��� Ÿ���� �߷��� �� ���� ��� �̱⿡ �׷� ���̴�.

	// !����
	// �⺻ auto �� const, & �� �����Ѵ�.
	int& ref = a;
	const int cst = a;

	auto test1 = ref;
	auto test2 = cst; 
	// �̷��� �ռ� ������ ���� Ÿ���� ������ �ʴ� ���� �⺻�ɼ��̴�.
	// �̸� ���󰡰� �ϱ� ���ؼ��� ��� �ؾ��ұ�?
	auto& test3 = ref;
	const auto test4 = cst;
	// �ռ� ������ Ÿ�԰� ���� auto�� �������ָ� �ȴ�. (�������� �����ϴ�.)

	// ������ Ÿ���� �ؾ������ auto�� ����ϴ� ���� ���?
	// ����� ��õ���� �ʴ´�.
	// -> ��� Ÿ���� auto�� �����ϰ� �Ǹ� '������'�� �������� �ȴ�. 
	// � Ÿ������ �˾ƾ� �󸶸�ŭ�� �޸𸮸� �����ϴ����� ���� �κ��� �˱� ���� �ʱ� �����̴�.
	
	// �׷����� �ұ��ϰ� auto�� ���� ������ �����̳�?
	// Ÿ������ ������� ��쿡 ����Ѵٴ� �����̴�. 

	map<int, int> m;
	auto m = m.insert(make_pair(1, 100));

	vector<int> v;

	// vector<int>::iterator �� ����!
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}

	// make_pair(_Ty1&& _Val1, _Ty2&& _Val2) �� ���� ��ȯ Ÿ���� ���̰� �ſ�� �ð��� �����ϱ� ���� 
	// auto�� ����Ѵٰ� ����ȴ�. (�ð������� �����̶�� ���̴� -> ���ư� �������� ���̴� ȿ���� �� �� �ֱ⿡)



	return 0;
}