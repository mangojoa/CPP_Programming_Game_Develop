#pragma once

/* ������ ����ٺ��� ���������� ���Ǵ� ������ �� �پ������� ������ �ٸ� �ɷ�ġ�� ������ �����ȴ�. 
������ �׷��ٰ� �ؼ� �̸� ���� �����ϰ� �� ���� ��������. �ſ� �������� �Ӵ��� 
�����ϱⰡ �ſ� ���������.

�׻� �̷� ������ �����ϰ� �ȴٸ� �������� �κ��� �ִ��� �����Ͽ� ���� �ܰ��� Ŭ������ ������. */

enum CreatureType {
    CT_Player = 0,
    CT_Monster = 1
};

/* �����δ� .cpp ���Ͽ��� �����ϰ� 
���⼭�� ���� �����ϰ� �����Ѵ�. */
class Creature
{
public:
    Creature(int creatureType)
     : _creatureType(creatureType), _hp(0), _attack(0), _defence(0) {

    }
    
    /* �Ҹ��ڴ� virtual�� ��������� �Ѵٴ� ���� ���� ����. */
    virtual ~Creature() {

    }

    virtual void PrintInfo() = 0;

    void onAttacked(Creature* attacker);
    bool isDead() { return _hp <= 0; }

/* �� ������ ���������� �����ϴ� ���� �ſ� �����ϴ�.
�׷��⿡ ��ü������ ���α׷��ֿ� �ؼ��Ͽ�
Get/Set ������ ���� �������� ����. */
protected:
    int _creatureType;
    int _hp;
    int _attack;
    int _defence;
};

