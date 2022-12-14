#pragma once
#include "Monster.h"

struct MonsterList
{
	Monster* pHead{};
	Monster* pTail{};
};

Monster* CreateMonster(MonsterList& list, const char* name, const int hp);
int GetCountMonsterList(MonsterList& list);
void PrintMonsterList(MonsterList& list);
Monster* FindMonster(MonsterList& list, const char* name);
void DeleteList(MonsterList& list);
bool DeleteMonster(MonsterList& list, const char* name);


