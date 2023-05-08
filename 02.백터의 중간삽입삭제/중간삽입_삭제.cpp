#include <iostream>
#include <vector>
using namespace std;

int main() {

	// Container : �����͸� �����ϴ� ��ä ( �ڷᱸ�� Data Structure )

	// �ݺ���(Iterator) : �����Ϳ� ������ ����. �����̳��� ����(������)�� ����Ű��, ����/���� ���ҷ� �̵� ����
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		v[i] = i;
	}

	/* iterator == ? pointer �� ����� �����̶�� ������ �����ߴ�. �׷� ��� �ٸ����� ���� �˾ƺ���. */
	vector<int>::iterator it;
	int* ptr;

	it = v.begin(); // vector�� ù��° ���� ����Ű�� ���
	ptr = &v[0];

	cout << (*it) << endl;
	cout << (*ptr) << endl;

	/* �̸� �����Ͽ� �޸𸮸� �����غ��� �Ѵ� ���� ���� ����Ű�� �ִٴ� ���� �˼� �ִ�.
	������ it ���� ���� ptr���� �ٸ��� �ٸ� ������ �� ��� �ִ� ����� �� �� �ִµ�
	�̴� � �����̳ʿ� �ҼӵǾ� �ִ����� �˷��ִ� ���������� �� �� �ִ�. (��� �Ҽӵ� ������ ���� ����) 
	
	�ݸ鿡 ������ �����Ϳ� �ٸ��� ����. Iterator�� Ÿ�� ���� ���� ���� ptr���� pointer to element in vector�� �ۼ��Ǿ� �ִ�. */

	// ����/���� ������ �̵�
	it++;
	--it;

	// begin �� ó�� ���� ����Ű�� ���¸� �ǹ��Ѵ�.
	vector<int>::iterator itBegin = v.begin();

	// end �� ������ ���� ����Ű�´� �̴� v�� ������ ���� �ƴ�
	// ������ ���� ++�� �� �������� �˰� �־�� �Ѵ�. 
	// ���δ�� v.end()�� ���ؼ� ������ ���� �˷��� �ϸ� �̴� ��ȿ���� ���� ���� ����ִٴ� ���� ����ؾ� �Ѵ�.
	// �̴� ������ vector�� ������ ���� �˱� ���ؼ� ����ϴ� ���̴�.
	vector<int>::iterator itEnd = v.end();

	// ���� �̸� ����ȭ �ؼ� ����ϰ� �� ���̴�.
	// ������ �ٸ� �����̳ʴ� v[i]�� ���� �ε��� ������ �ȵ� �� �ִ�.
	// iterator�� vecrot�� �ƴ϶�, �ٸ� �����̳ʿ��� ���������� �ִ� �����̱⿡
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << (*it) << endl;
	}

	// const int*
	vector<int>::const_iterator cit1 = v.cbegin();
	// *cit1 = 100;

	// �ݴ�� �������� ��� ��� -> ���� ���� ���� ������ �˾Ƶθ� ���ܰ� ����.
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
		cout << (*it) << endl;
	}

	return 0;
}