#include <iostream>
using namespace std;

/* �Լ�(Function)
�ڵ忡 ���� �̶�� �����ϴ� ���� ���� �� �ִ�.
(������ �Ϲ����� �ڵ��� �����̶�� �����ϱ� ���ٴ� ���뼺�� ������ �ֱ⿡ �ٸ���.)

input ���� ������ �ް�(���� �������� �ִ�.), output���� ������ ��ȯ���� �����ش�.

��ȯŸ�� �Լ��̸�([����Ÿ�� �Ű�����]) {
    logic ~~

    return output; (��ȯ�ϴ� Ÿ���� ���� ��쿡�� ������ �� �ִ�.)
}
*/

// �⺻���� �Լ��� ������ input:x output:x
void printHelloWorld() {
    cout << "Hello, World!" << endl;
}

// input = int a�� �޾Ƽ� console �� ����غ���.
void printNumber(int a) {
    cout << "���� int a = " << a << endl;
}

// ���� �����ϰ� �̸� ��ȯ�غ���.
int culNumber(int a) {

    int result = a * 2;

    return result;
}

int main() {

    int result = culNumber(3);

    printHelloWorld();
    printNumber(result);
}