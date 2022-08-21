#include <iostream>

using namespace std;

/* [22.07.28] 문자와 문자열
지난 시간에 배웠을 때도 char은 그냥 정수지만 '문자' 의미를 나타내기 위해 사용

char : 알파벳 / 숫자 문자를 나타낸다.
wchar_t : 유니코드 문자를 나타낸다.
*/
char ch = '안';
/* char ch = 97; 이라 정의하고 이를 cout 하면
당연한 결과로 97이 출력될 것이라 생각했다.

하지만 a 가 출력이 된다.... 왜??? (그 이유는 ASCII 때문이다..)
ASCII (American Standard Code for Information Interchange)

char ch = 97; 이를 문자로 나타내고 싶다면 ''를 사용하는 것이 좋다.
(그러면 신기하게도 ASCII Code로 변환되지 않는다!!)
*/

/* 전 세계 모든 문자에 대해 유일 코드를 부여한 것이 바로 unicode 이다
unicode를 표기방식에는 여러가지가 있는대 대표적으로 UTF8 / UTF16 이 존재한다. 

이 둘의 차이는 데이터를 저장하는 용량에 있다.

utf 8
알파벳, 숫자, 1바이트 (ascii와 동일한 번호)
유럽 지역의 문자 2바이트
한글, 한자 등 3바이트

utf 16
알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트 
아주 드물게 고고대 문자만 4바이트로 사용된다
*/
int main() {
    cout << ch << endl;
}