#include <iostream>
using namespace std;

/* �����Ϳ� �迭�� ���̿� ���Ͽ�

const char* test1 = "Hello, World";
char test2[] = "Hello, World";
�� �κи� ���� �����Ϳ� �迭�� ���� ������ ������ �� �ִ�. (������ �ٸ���.)
*/

int main() {

    const char* test1 = "Hello, World";
    /* �̸� ����� ���� �˾ƺ���!
    dword ptr [test1].offwet string "Hello World" (09E9B30h)

    09E9B30h �ش� �ְ� �ִ� �ƽ�Ű �ڵ�� ����� "Hello World"�� �����ٰ� test1�� �־��ִ� ����� �� �� �ִ�.
    */

    char test2[] = "Hello, World";
    /* �̸� ����� ���� �˾ƺ���!
    eax, dword ptr [string "Hello World" (09E9B30h)]
    dword ptr [test2],eax

    ecs, dword ptr ds:[9E9B34h]
    dword ptr [ebp-18h],ecx

    edx, dword ptr ds:[9E9B38h]
    dword ptr [ebp-14h],edx

    09E9B30h �ش� �ּҿ� �ִ� �ƽ�Ű �ڵ�� ����� "Hello World"�� �����ٰ� test1�� �־��ִ� ����� �� �� �ִ�.
    */

}