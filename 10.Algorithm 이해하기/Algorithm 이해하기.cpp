#include <iostream>
#include <vector>
using namespace std;

/* �˰����� ���� �ڵ��� �������� ��������. */
#include <algorithm>

/* �ڷᱸ���� �˰���
* 
* ���� ���� ���� ������ �����ϴ� ��찡 �ִ�. ������ ����� �ٸ����̴�.
* 
* �ڷᱸ�� = [�����͸� �����ϴ� ����]
* �˰��� = [�����͸� ��� ����� ���ΰ�?]
* 
* �̴� 1+1�� ���� ¦�� ���� �������� ���ȴ�.
*/

/* ���� ��� �˰��� ��ɵ�

find 
find_if
count
count_if
all_of
any_of
none_of
for_each
remove
remove_if

Ȱ��󵵰� ���� ģ�����̸� �̸� �̿����� �ȴٸ� �������� ����ϴٰ� �Ѵ�!
*/

int main() {

	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++) {
		int num = rand() % 100;
		v.push_back(num);
	}
	/* ---------------------------------------------- */

	// Q1) number��� ���ڰ� ���;ȿ� �ִ��� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		int number = 50;
		bool found = false;

		for (vector<int>::iterator findIt = v.begin(); findIt < v.end(); ++findIt) {
			cout << *findIt << " ";

			if (*findIt == number) found = true;
		}

		cout << endl;

		if (found) cout << number << "�� ã�ҽ��ϴ�!" << endl;
		else cout << number << "�� ã�� ���߽��ϴ�.." << endl;

		cout << "------------------------------------------------" << endl;
		cout << "algorithm�� �̿��� ������ �κ�" << endl;

		// find(start, end, target); �������� ����ϸ� �ȴ�. 
		// ���� �ڵ�ʹ� �ٸ��� �ſ� ������ ���� Ȯ���� �� �ִ�.
		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		// C++ 11 ���ĺ��ʹ� auto ��� ������ ���� ���� �����ϰ� �ۼ��� �� �ִ�.
		// auto itFind = find(v.begin(), v.end(), number);

		if (itFind == v.end()) cout << "ã�� ���߽��ϴ�..." << endl;
		else cout << "ã�ҽ��ϴ�!" << endl;

		cout << endl;
	}

	cout << "------------------------------------------------" << endl;

	// Q2) 11�� ������ ���ڰ� ���;ȿ� �ִ��� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		bool found = false;

		for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
			if (*it % 11 == 0) {
				cout << *it << " ";
				found = true;
			}
		}

		cout << endl;

		if (found) cout << "11�� ���������� ���ڰ� �����մϴ�!" << endl;
		else cout << "11�� ���������� ���ڰ� �������� �ʽ��ϴ�.." << endl;

		cout << "------------------------------------------------" << endl;
		cout << "algorithm�� �̿��� ������ �κ�" << endl;

		struct CanDivideBy11 {
			bool operator()(int n) {
				return (n % 11) == 0;
			}
		};

		// find_if(start, end, �Լ� or ������); �������� ����ϸ� �ȴ�.
		// ����� ��� ������ �־�� �ϰ� �̸� �����ϱ� ���ؼ��� �Լ� Ȥ�� ���ٽ��� �̿��� ����� ����Ѵ�.
		// ������ ���⼭�� ��.���� �˱� ���ؼ� �Լ��� �����Ѵ�.
		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());

		// ���ٽ��� �̿��� ��ȸ�� �Լ��� �����Ų �ڵ�
		// vector<int>::iterator itFind = find_if(v.begin(), v.end(), [](int n) { return (n % 11) == 0; });

		if (itFind == v.end()) cout << "ã�� ���߽��ϴ�..." << endl;
		else cout << "ã�ҽ��ϴ�!" << endl;

		cout << endl;

	}

	cout << "------------------------------------------------" << endl;

	// Q3) ���;ȿ� Ȧ���� � �ִ��� üũ�ϴ� ��� (count)
	{
		int count = 0;

		for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
			if (*it % 2 != 0) {
				cout << *it << " ";
				count++;
			}
		}

		cout << endl;

		cout << "Ȧ���� ���� " << count << "�� �Դϴ�." << endl;

		cout << "------------------------------------------------" << endl;
		cout << "algorithm�� �̿��� ������ �κ�" << endl;

		struct IsOdd {
			bool operator()(int n) {
				return (n % 2) == 0;
			}
		};

		// count_if(start, end, �Լ� or ���ٽ�) ���� ���ȴ�.
		// count / count_if �� ��ȯŸ���� int �̱⶧���� vector<int>::iterator �� ���� ������ ������ �ȵȴ�.
		int number = count_if(v.begin(), v.end(), IsOdd());
		// count_if�� Ÿ�� ���� Ȯ���ϸ� �������� ���� �Լ��� �´� ������ ���, ++ �� �Ǵ� ������ Ȯ���� �� �ִ�.

		cout << "Ȧ���� ���� " << number << "�� �Դϴ�." << endl;

		// ��� �����Ͱ� Ȧ�� �Դϱ�?
		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		// Ȧ���� �����Ͱ� �ϳ��� �ֽ��ϱ�?
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		// ��� �����Ͱ� Ȧ���� �ƴմϱ�?
		bool b3 = none_of(v.begin(), v.end(), IsOdd());

	}

	cout << "------------------------------------------------" << endl;

	// Q4) ���;��� ��� ���ڵ鿡 3�� ���ϴ� ���
	{
		for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
			int temp = (*it) * 3;
			cout << "���� ��: " << (*it);
			*it = temp;
			cout << " | ���� ��: " << (*it) << endl;
		}

		cout << "------------------------------------------------" << endl;
		cout << "algorithm�� �̿��� ������ �κ�" << endl;

		struct MultiplyBy3 {
			void operator()(int& n) {
				n = n * 3;
			}
		};

		// for_each(start, end, �Լ� or ���ٽ�) ���� ���ȴ�.

		for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// Ȧ���� �����͸� �ϰ� ����
	// remove
	// remove_if �� �ΰ��� �Լ��� Ư���ϰ�(?) �۵��Ѵٰ� �Ѵ�.
	{
		// Ȧ���� �����͸� �����Ҷ� �̸� �Ժη� �����ϰ� �ȴٸ� ������ ������ ��Ȳ�̶�� �������
		// �ش� �����͸� ����� ���� �����͸� ������ �����ϴ� ������ ��ģ�ٸ� 
		// �̴� �ſ� ��ȿ�������� �۵��ϰ� �� ���̶�� �� �ռ� �������.

		/*for (vector<int>::iterator it = v.begin(); it != v.end();) {
			if ((*it % 2) != 0) it = v.erase(it);
		}*/

		v.clear();

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		// std::remove(v.begin(), v.end(), 3);

		struct IsOdd {
			bool operator()(int n) {
				return (n % 2) != 0;
			}
		};

		// ���� �������� ����
		// 1 2 3 4 5

		// ���� �������� ����
		// 2 4 3 4 5

		// ���� �̻��� ������ �����ִٴ� ���� �� �� �ִ�. 

		/* �� �ڵ带 �м��غ���!!
		template <class ForwardIt, class UnaryPredicate>
		ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p) {
		  first = std::find_if(first, last, p); -> �츮�� ã�ƾ��ϴ� ��ġ�� �����ϴ� �ڵ�
		  if (first != last)
			for (ForwardIt i = first; ++i != last;) -> ��ü�� ��ĵ�ϴ� �κ�
			  if (!p(*i)) *first++ = std::move(*i); -> �ش��ϴ� �����Ͱ� �ƴѰ��, �̸� �̵���Ű�� �ڵ�
		  return first; -> �� �κ��� ���� �߿�

		  return �� �� first�� �ϴ°�?

		  ���� �������� ���¸� ����
		  2 4 3 4 5

		  1 3 5 �� ������ ��� 2 4 �� ������ ����� �ƴϴ�

		  ���� �ڵ带 ���� if (!p(*i)) *first++ = std::move(*i); �ڵ忡�� ������ ����� �ƴ� ���� 
		  ������ �������� �ڵ带 �� �� �ִ�.

		  ���� ���� �ڵ�� �״�� ���� �Ǵµ� (�׷��� ������ �ȵȰ� �ƴѰ�?)

		  ���⼭ return �� �� first�� �ߴ��� �� �� �ִ�.

		  first�� ������ ����� �ƴ� �����͸� ��ȯ�Ѵ�. 
		  ��, ����� �ƴ� ������ �������ʹ� ������ �����ص� �ȴٴ� ���̴�.
		  
		}
		*/

		vector<int>::iterator it = std::remove_if(v.begin(), v.end(), IsOdd());
		v.erase(it, v.end());

		int a = 3;
	}

	return 0;
}