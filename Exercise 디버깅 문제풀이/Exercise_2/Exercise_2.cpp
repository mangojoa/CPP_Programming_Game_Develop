#include <iostream>
using namespace std;
#include "Knight.h"

// [Bug Report #2]
// Bug Report #1이 잘 해결 되었는지 확인하기 위해
// 기사 10명 생성해서 정보를 출력하고자 합니다.
// 그런데 정보를 출력하다 프로그램이 뻗는 문제가 발생하고 있습니다.
// 크래시 원인을 분석하고 알맞게 고쳐주세요!

const int KNIGHT_COUNT = 10;

int main()
{
	Knight* knights[KNIGHT_COUNT];

	for (int i = 0; i < KNIGHT_COUNT; i++)
	{
		knights[i] = new Knight();
	}

	/* [풀이]
	1. 첫 번째 추측
	배열의 값을 delete하기 때문에 그 자리에 빈 값이 있는게 아닌 
	매열이 한 칸씩 당겨지는 원리로 인해 크랙이 나는 것인지 아닐까 하는 추측

	허나, 그럴꺼면 2번째부터 나야한다는게 맞음

	2. 두 번째 추측
	배열의 범위에 대한 측정이 잘못되었기에,
	이는 10번째까지 -> 배열에서는 0 ~ 9 까지의 수로 측정되지만
	두 번째, for문에서 11번째까지 진행한다는 부분을 발견

	i <= KNIGTH_COUNT; -> 11번째까지 진행 

	= 표시로 인해 1칸이 더 진행되는 원리로 진행됨

	= 표시를 삭제하면 정상적으로 실행되고 종료된다.
	
	*/
	for (int i = 0; i <= KNIGHT_COUNT; i++)
	{
		knights[i]->PrintInfo();
		delete knights[i];
	}
}
