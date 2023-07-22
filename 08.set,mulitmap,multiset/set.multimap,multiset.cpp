#include <iostream>
using namespace std;

#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

int main() {
	set<int> s;
	
	/* set�� ��� (value = key �� ��ġ�ϴ� �������� �۵��Ѵٰ� ����ȴ�) */

	// �ְ�
	s.insert(10);
	s.insert(70);
	s.insert(30);
	s.insert(60);
	s.insert(50);

	// ����
	s.erase(60);

	// ã��
	set<int>::iterator findIt = s.find(50);
	if (findIt == s.end()) cout << "not find" << endl;
	else cout << "find" << endl;

	// s[10] = 10; // ������ ���� ����� �����ִ�.

	// ��ȸ�ϰ�
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << (*it) << endl;
	}
	
	/* ------------------------------------------------------------- */
	cout << "-------------------------------------------------" << endl;
	
	/* multimap => ������ map �� �ٸ� ���� �ߺ�ġ�� ����Ѵٴ� �� */

	multimap<int, int> mm;

	// �ְ� (������ map������ key���� �ߺ��� �� ������ multimap ������ �� �κ��� ���� �����̶�� ����ȴ�.)
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(2, 500));
	
	// mm[1] = 400; // �� ����� �����ִ�.

	// ���� (�̴� key�� ������� ���� �����ϴ� �Լ��ε� / key���� �ߺ��Ǵ� multimap������ �ߺ��� ��� ���� ���� �����Ѵ�.)
	unsigned int count = mm.erase(1);

	// ã�� (���ϴ� ���� ��Ȯ�� �����ϰ� �ʹٸ� �� ���� ��ġ�� �ڸ��� �˰� �־�� �Ѵ�.)
	// ���� ���� ������ key ���·� �Ǿ��ִٸ�
	// mm.find(itFind); ��ȯ���� iterator �� find() �Լ��� ���� �����ϸ� �� ��ġ�� �� �� �ִ�.
	/* iterator => mm.insert(make_pair(1, 100)); ���� ����Ű�� ���¿��� 
	���� ������ (++) �� ���� ������ Ȥ�� ���������� �̵��Ͽ� ������ ������ �� �ִ�. */
	multimap<int, int>::iterator itFind = mm.find(1);
	if (itFind != mm.end()) mm.erase(itFind);

	// ��ȸ�ϰ�
	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;
	itPair = mm.equal_range(1);

	for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it) {
		cout << (*it).first << " " << (*it).second << endl;
	}

	multimap<int, int>::iterator itBegin = mm.lower_bound(1);
	multimap<int, int>::iterator itEnd = mm.upper_bound(1);

	for (multimap<int, int>::iterator it = itBegin; it != itEnd; ++it) {
		cout << (*it).first << " " << (*it).second << endl;
	}

	/* ------------------------------------------------------------- */
	cout << "-------------------------------------------------" << endl;

	/* multiset => ������ set �� �ٸ� ���� �ߺ�ġ�� ����Ѵٴ� �� */

	multiset<int> ms;

	// �ְ�
	ms.insert(100);
	ms.insert(100);
	ms.insert(100);
	ms.insert(200);
	ms.insert(200);

	// ã��
	multiset<int>::iterator findIt = ms.find(100); // key = 100 �� �ش��ϴ� ù ��° �˻��� ���� ����Ų��. 
	// multimap �� ���������� �������� �Ѳ����� ���� �� �� �ִ� ������� ������ �� �ִ�. 

	pair<multiset<int>::iterator, multiset<int, int>::iterator> itPair2;
	itPair2 = ms.equal_range(100);

	for (multiset<int>::iterator it = itPair2.first; it != itPair2.second; ++it) {
		cout << *it << endl;
	}

	multiset<int>::iterator itBegin2 = ms.lower_bound(1);
	multiset<int>::iterator itEnd2 = ms.upper_bound(1);

	for (multiset<int>::iterator it = itBegin2; it != itEnd2; ++it) {
		cout << *it << endl;
	}


	return 0;
}