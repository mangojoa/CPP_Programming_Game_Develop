#include <iostream>
using namespace std;

// 제약사항을 둔 TEXTRPG를 만들어 보자.

enum PlayerType {
	PT_knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

enum MonsterType {
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3
};

struct StatInfo {
	int hp = 0;
	int attack = 0;
	int defence = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* playerinfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);


/* int main() 함수 안에서 EnterLobby() -> PrintMessage() -> CreatePlayer() -> PrintStatInfo() -> EnterGame() 과 같이 스택프레임의 형태로 진행됨을 볼 수 있다. 
왜 이렇게 진행하는가 ? 

포인터를 마무리하면서 함수 밖으로 포인터 or 배열 or 참조 값을 보내는 것은 매우 위험하다고 했다(메모리 오염이 일어날 수 있기 때문이다.)

하지만 스택프레임이 끊임없이 진행된다면 어떻게 될까? 

높은 주소에서 낮은 주소로 이동할 때, 안에 낮은 주소에서는 높은 주소의 값을 제대로 읽을 수 있고 내부로 데이터를 계속해서 보내기 때문에 
데이터의 안정성은 확실하게 보장할 수 있다는 점이 있다. (이는 매우 훌륭하고 스택 프래임을 이해하고 있어야 한다)

그렇기에 
1. 높은 주소에서 낮은 주소로 이동할 때
2. 낮은 주소에서 높은 주소로 이동할 때 

데이터가 존재하는 스택 프래임을 종료하지 않는 이상 데이터의 안정성은 보존된다는 것이다.

이를 통해 TEXTRPG를 만들어 보면서 실제로 어떻게 작동하는지와 함수 인자값에 따른 포인터 참조 배열의 사용법을 익힐 수 있었다.

나아가 데이터가 스택 프래임 안에서 문제없이 돌아가는 것을 보았을 때, 오늘 배운 내용을 몇 차례 리뷰를 통해 메모리 오염이 일어나지 않도록 주의해야 겠다고 생각했다.

*/
int main() {

	srand((unsigned)time(nullptr));
	
	EnterLobby();

}

void EnterLobby() {

	while (true) {
		PrintMessage("로비에 입장했습니다.");

		// Player!!
		StatInfo playerInfo;
		CreatePlayer(&playerInfo);
		PrintStatInfo("Player", playerInfo);

		EnterGame(&playerInfo);
	}

}

void PrintMessage(const char* msg) {
	cout << "*********************" << endl;
	cout << msg << endl;
	cout << "*********************" << endl;
}

void CreatePlayer(StatInfo* playerInfo) {
	bool ready = false;

	while (ready == false) {
		PrintMessage("캐릭터 생성창");
		PrintMessage("[1] 기사 [2] 궁수 [3] 법사");

		cout << "> ";

		int input;
		cin >> input;

		switch (input) {
		case PT_knight:
			playerInfo->hp = 100;
			playerInfo->attack = 10;
			playerInfo->defence = 5;
			ready = true;
			break;

		case PT_Archer:
			playerInfo->hp = 80;
			playerInfo->attack = 15;
			playerInfo->defence = 3;
			ready = true;
			break;

		case PT_Mage:
			playerInfo->hp = 50;
			playerInfo->attack = 25;
			playerInfo->defence = 1;
			ready = true;
			break;
		}
	}
}

void PrintStatInfo(const char* name, const StatInfo& info) {
	cout << "*********************" << endl;
	cout << name << " HP = " << info.hp << " ATT =  " << info.attack << " DEF = " << info.defence << endl;
	cout << "*********************" << endl;
}

void EnterGame(StatInfo* playerInfo) {

	const int MONSTER_COUNT = 2;

	PrintMessage("게임에 입장했습니다.");

	while (true) {

		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);

		for (int x = 0; x < MONSTER_COUNT; x++) PrintStatInfo("Monster", monsterInfo[x]);

		PrintStatInfo("Player", *playerInfo);

		PrintMessage("[1] 전투 [2] 전투 [3] 도망");
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1 || input == 2) {
			int index = input - 1;
			bool victory =  EnterBattle(playerInfo, &(monsterInfo[index]));

			if (victory == false) break;
		}

	}

}

void CreateMonsters(StatInfo monsterInfo[], int count) {

	for (int x = 0; x < count; x++) {
		int randValue = 1 + rand() % 3;

		switch (randValue)
		{
		case MT_Slime:
			monsterInfo[x].hp = 30;
			monsterInfo[x].attack = 5;
			monsterInfo[x].defence = 1;
			break;

		case MT_Orc:
			monsterInfo[x].hp = 40;
			monsterInfo[x].attack = 8;
			monsterInfo[x].defence = 2;
			break;

		case MT_Skeleton:
			monsterInfo[x].hp = 50;
			monsterInfo[x].attack = 15;
			monsterInfo[x].defence = 3;
			break;

		}
	}
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo) {
	
	while (true) {
		int damage = playerInfo->attack - monsterInfo->defence;
		if (damage < 0) damage = 0;

		monsterInfo->hp -= damage;
		if (monsterInfo->hp < 0) monsterInfo->hp = 0;

		PrintStatInfo("Monster", *monsterInfo);

		if (monsterInfo->hp == 0) {
			PrintMessage("몬스터를 처치했습니다.");
			return true;
		}

		damage = monsterInfo->attack - playerInfo->defence;
		if (damage < 0) damage = 0;

		playerInfo->hp -= damage;
		if (playerInfo->hp < 0) playerInfo->hp = 0;

		PrintStatInfo("Player", *playerInfo);

		if (playerInfo->hp == 0) {
			PrintMessage("몬스터가 너무 강합니다.....");
			return false;
		}
	}
}