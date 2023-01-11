#include <iostream>
#include <string>
using namespace std;

int main() {

    /* C++ ���� Random�̶�?
    C++ ���� ������ ���� ����ϴ� ������� rand()�� �̿��ϴ� ����� �ִ�.
    ��ǻ� ��ǻ�Ϳ��� ����(random)�̶�� ������ �������� �ʴ´�.

    �׷��⿡ rand();�� ����ϱ� ���� ����
    ��, �õ尪�� ��������� �Ѵ�.

    srand(time(0));
    cout << rand() << endl;

    srand�� rand�� ���� ���δٰ� ���� �ȴ�.
    */

    /* ���� Random�� ����ϴ� ���� ��������
    �̸� �������� ������ ������ �Ǵ� ���������� ������ ������ */

    // rand�� ģ���� srand()�� ���� ����
    srand(time(0));

    string question = "����(1) ����(2) ��(3) ������ �����մϴ�. �� ������ �������ּ���";
    string your_choice = "����� ������ >> ";
    string user = "(���)";
    string computer = "(��ǻ��)";
    string r = "����";
    string c = "����";
    string p = "��";

    string win = " �̰���ϴ�!";
    string lose = " �����ϴ�!";
    string draw = " �����ϴ�!";

    string result_user;
    string result_computer;

    int H_Value;
    int C_Value;

    while (true) {
        cout << question << endl;

        // ������ �� ���� ���� ����
        cout << your_choice;
        cin >> H_Value;

        // ��ǻ�Ͱ� �� ���� ���� ����
        C_Value = 1 + (rand() % 3);

        if (H_Value == 1) result_user = c + user;
        else if (H_Value == 2) result_user = r + user;
        else if (H_Value == 3) result_user = p + user;

        if (C_Value == 1) result_computer = c + computer;
        else if (C_Value == 2) result_computer = r + computer;
        else if (C_Value == 3) result_computer = p + computer;

        // ����(1) ����(2) ��(3)
        if (H_Value == C_Value) {
            cout << result_user << " vs " << result_computer << draw << endl;
        }
        else if (H_Value > C_Value) {
            cout << result_user << " vs " << result_computer << win << endl;
        }
        else if (H_Value < C_Value) {
            cout << result_user << " vs " << result_computer << lose << endl;
        }
    }
}