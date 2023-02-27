#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::PrintInfo() {
    cout << "------------------" << endl;
    cout << "[몬스터 정보]" << endl;
    cout << "HP: " << _hp << " ATT: " << _attack << " DEF: " << _defence << endl;
    cout << "------------------" << endl;
}