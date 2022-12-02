#include <iostream>
#include <string>
using namespace std;

int main() {

    /* C++ 에서 Random이란?
    C++ 에서 렌덤한 값을 출력하는 방법에는 rand()를 이용하는 방법이 있다.
    사실상 컴퓨터에는 랜덤(random)이라는 개념은 존재하지 않는다.

    그렇기에 rand();를 사용하기 전에 설정
    즉, 시드값을 설정해줘야 한다.

    srand(time(0));
    cout << rand() << endl;

    srand와 rand는 같이 쓰인다고 보면 된다.
    */

    /* 이제 Random을 사용하는 법을 익혔으니 
    이를 바탕으로 무한정 실행이 되는 가위바위보 게임을 만들어보자 */

    // rand의 친구인 srand()를 먼저 설정
    srand(time(0));

    string question = "가위(1) 바위(2) 보(3) 게임을 시작합니다. 한 가지를 선택해주세요";
    string your_choice = "당신의 선택은 >> ";
    string user = "(당신)";
    string computer = "(컴퓨터)";
    string r = "바위";
    string c = "가위";
    string p = "보";

    string win = " 이겼습니다!";
    string lose = " 졌습니다!";
    string draw = " 비겼습니다!";

    string result_user;
    string result_computer;

    int H_Value;
    int C_Value;

    while(true) {
        cout << question << endl;

        // 유저가 낼 값에 대한 지정
        cout << your_choice;
        cin >> H_Value;

        // 컴퓨터가 낼 값에 대한 지정
        C_Value = 1 + (rand() % 3);

        if (H_Value == 1) result_user = c + user;
        else if (H_Value == 2) result_user = r + user;
        else if (H_Value == 3) result_user = p + user;

        if (C_Value == 1) result_computer = c + computer;
        else if (C_Value == 2) result_computer = r + computer;
        else if (C_Value == 3) result_computer = p + computer;

        // 가위(1) 바위(2) 보(3)
        if (H_Value == C_Value) {
            cout << result_user << " vs " << result_computer << draw << endl;
        } else if (H_Value > C_Value) {
            cout << result_user << " vs " << result_computer << win << endl;
        } else if (H_Value < C_Value) {
            cout << result_user << " vs " << result_computer << lose << endl;
        }
    }
}