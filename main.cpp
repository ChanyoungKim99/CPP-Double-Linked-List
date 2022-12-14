#include <iostream>
#include "MonsterList.h"
// Double Linked List

int main()
{
	MonsterList myList;

	CreateMonster(myList, "WOLF", 10);
	CreateMonster(myList, "DEMON", 100);
	CreateMonster(myList, "SLIME", 1);

	PrintMonsterList(myList);
	std::cout << GetCountMonsterList(myList) << std::endl;

	Monster* pResult = FindMonster(myList, "DEMON");
	if (pResult == nullptr)
	{
		std::cout << "NOT FOUND" << std::endl;
	}
	else
	{
		std::cout << pResult->name << " : " << pResult->hp << std::endl;
	}

	DeleteMonster(myList, "DEMON");
	PrintMonsterList(myList);

	DeleteList(myList);
	std::cout << GetCountMonsterList(myList) << std::endl;
}