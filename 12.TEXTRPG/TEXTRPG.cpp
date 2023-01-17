#include <iostream>
using namespace std;

// ��������� �� TEXTRPG�� ����� ����.

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


/* int main() �Լ� �ȿ��� EnterLobby() -> PrintMessage() -> CreatePlayer() -> PrintStatInfo() -> EnterGame() �� ���� ������������ ���·� ������� �� �� �ִ�. 
�� �̷��� �����ϴ°� ? 

�����͸� �������ϸ鼭 �Լ� ������ ������ or �迭 or ���� ���� ������ ���� �ſ� �����ϴٰ� �ߴ�(�޸� ������ �Ͼ �� �ֱ� �����̴�.)

������ ������������ ���Ӿ��� ����ȴٸ� ��� �ɱ�? 

���� �ּҿ��� ���� �ּҷ� �̵��� ��, �ȿ� ���� �ּҿ����� ���� �ּ��� ���� ����� ���� �� �ְ� ���η� �����͸� ����ؼ� ������ ������ 
�������� �������� Ȯ���ϰ� ������ �� �ִٴ� ���� �ִ�. (�̴� �ſ� �Ǹ��ϰ� ���� �������� �����ϰ� �־�� �Ѵ�)

�׷��⿡ 
1. ���� �ּҿ��� ���� �ּҷ� �̵��� ��
2. ���� �ּҿ��� ���� �ּҷ� �̵��� �� 

�����Ͱ� �����ϴ� ���� �������� �������� �ʴ� �̻� �������� �������� �����ȴٴ� ���̴�.

�̸� ���� TEXTRPG�� ����� ���鼭 ������ ��� �۵��ϴ����� �Լ� ���ڰ��� ���� ������ ���� �迭�� ������ ���� �� �־���.

���ư� �����Ͱ� ���� ������ �ȿ��� �������� ���ư��� ���� ������ ��, ���� ��� ������ �� ���� ���並 ���� �޸� ������ �Ͼ�� �ʵ��� �����ؾ� �ڴٰ� �����ߴ�.

*/
int main() {

	srand((unsigned)time(nullptr));
	
	EnterLobby();

}

void EnterLobby() {

	while (true) {
		PrintMessage("�κ� �����߽��ϴ�.");

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
		PrintMessage("ĳ���� ����â");
		PrintMessage("[1] ��� [2] �ü� [3] ����");

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

	PrintMessage("���ӿ� �����߽��ϴ�.");

	while (true) {

		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);

		for (int x = 0; x < MONSTER_COUNT; x++) PrintStatInfo("Monster", monsterInfo[x]);

		PrintStatInfo("Player", *playerInfo);

		PrintMessage("[1] ���� [2] ���� [3] ����");
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
			PrintMessage("���͸� óġ�߽��ϴ�.");
			return true;
		}

		damage = monsterInfo->attack - playerInfo->defence;
		if (damage < 0) damage = 0;

		playerInfo->hp -= damage;
		if (playerInfo->hp < 0) playerInfo->hp = 0;

		PrintStatInfo("Player", *playerInfo);

		if (playerInfo->hp == 0) {
			PrintMessage("���Ͱ� �ʹ� ���մϴ�.....");
			return false;
		}
	}
}