#include <iostream>
using namespace std;

/* [22.11.11]
�б⹮�� �ݺ����� ���� �����̿��⿡ �̿� ���� ������ ����߱⿡ ���� ��,
�ǽ��� ����
*/

// 1. �Էµ� int�� ���� ���������� �����ϴ� ������ �ۼ��϶�
int main() {
    int a;
    cin >> a;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < (i + 1); j++) {
            cout << "*";
        }
        cout << endl;
    }

}

// 2. �Էµ� int�� ���� ���������� �����ϴ� ������ �ۼ��϶�
int main() {
    int b;
    cin >> b;

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < (b - i); j++) {
            cout << "*";
        }
        cout << endl;
    }


}

// 3. 