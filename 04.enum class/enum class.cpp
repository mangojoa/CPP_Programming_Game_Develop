#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/* enum class (scoped enum)
1) �̸� ���� ���� (scoped)
*/

/* ������ ���Ǵ� enum class�� ������ ?!
�켱������ �տ� PT_ ��� ���̹� ��Ģ�� ����Ǿ� �ۼ��Ǿ�Դ�.

������ ���� �׷��� �ۼ��� �ʿ䰡 �ִ°�?

�� �ȿ��� ����Ʈ�� ����Ʈ �ΰǵ�! �ϴ� ������ �� �� �ִ�.
(������ ���ſ� ������� C++�� �׸� ����� ���� �ƴϴ�...)

PlayerType���� Knight�� ������ ��,
MonsterType���� Knight(����)�� �����ߴٰ� �غ���.
(�Ϲ����� �������� ������ �ƿ� �ٸ� ���� ������ �����̱⿡
�ٸ� ������ �ν��� ������ ����� �� ������ ������ �����Ϸ��� ����������� �ʴ´�.)
-> �����ǵ� '������' ��� Error�� ��µȴ�.

�׷��� ���ſ� ���� enum class�� �̸��� unscoped enum�̶�� �Ѵ�. */

enum PlayerType {
    Knight,
    Archer,
    Mage
};

enum MonsterType {
    Knight,
    Archer
};
// ���� unscoped enum �� ��� ���� ���̹��� �ٸ� ������ ����Ǿ������� ����Ǳ� ��������
// Error���� �� �� ����. (�׷��⿡ �տ� enum�� ���̹� ��Ī�� �ʼ������� ���ݵǾ�� ���� �и��� ����ȴ�.)

// ������ enum class �� ���, 
// �ٸ������� ���� ���̹����� �����ص� ������ ����. (������ ������ ���������� ��ȿ�ϴٴ� �ǹ�)
enum class PlayerType01 {
    Knight,
    Archer,
    Mage
};

enum class MonsterType01 {
    Knight,
    Archer,
    Mage
};

int main() {

    /* �����и��� ���������� �̷������ �ѵ� ������ ������ ����ٴϱ� �����̴�.
    2) �Ϲ����� ��ȯ ����
    Enum Class ���� ����� �������� ���� int������ 1�� �����ϴ� ������ �Ǿ��ִ�.

    ������ �̸� ������ ���� ĳ������ �Ѵٰ� �ϸ� ��� �ɱ�? */
    double value = PlayerType01::Knight;
    /* �и� PlayerType01::Knight �� ���� 0 ������ �̸� double�� ��ȯ�� �� ����.
    Enum Class ������ �Ϲ����� ��ȯ(�ɽ���)�� �����Ǿ� �ֱ� �����̴�.

    �̴� Enum Class�� Enum �� ���� ������ �� �� �ִ� �κ��̶�� ������ �� �ִ�.

    ���� ó������ �׷��� ���������� ������ ������ ���ϹǷν� �Ϻ��� ���� �� �ִٴ� ������
    �Ǽ��� ���� �� �ִ� �ϳ��� ��ġ�� �� �� �ְڴٴ� ������ ���� 

    �̷��� ����� ���� Ʋ�� �� �ƴ϶�� ���� �˰� �Ǿ���. */

    double value = static_cast<double>(PlayerType01::Knight);




    return 0;
}