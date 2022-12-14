#include <iostream>
#include <cstring>
#include "MonsterList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
    Monster* pNew = new Monster{};  
    // 헤더 파일에서 전부 초기화했으니 초기화 안해도 되긴한다.
    strcpy_s(pNew->name, NAME_LENGTH, name);
    pNew->hp = hp;

    if (list.pTail == nullptr)
    {
        list.pHead = pNew;
        list.pTail = pNew;
    }
    else
    {
        list.pTail->pNext = pNew;
        pNew->pPrev = list.pTail;
        list.pTail = pNew;
    }

    return pNew;
}

int GetCountMonsterList(MonsterList& list)
{
    Monster* pElement = list.pHead;
    int count{};

    while (pElement != nullptr)
    {
        count++;
        pElement = pElement->pNext;
    }
    return count;
}

void PrintMonsterList(MonsterList& list)
{
    Monster* pElement = list.pHead;
    
    while (pElement != nullptr)
    {
        std::cout << pElement->name << " : " << pElement->hp << std::endl;
        pElement = pElement->pNext;
    }
}

Monster* FindMonster(MonsterList& list, const char* name)
{
    Monster* pElement = list.pHead;
    
    while (pElement != nullptr)
    {
        if (strcmp(pElement->name, name) == 0)
        {
            return pElement;
        }

        pElement = pElement->pNext;
    }

    return nullptr;
}

void DeleteList(MonsterList& list)
{
    Monster* pElement = list.pHead;
    Monster* pNext{};

    while (pElement != nullptr)
    {
        pNext = pElement->pNext;
        delete pElement;

        pElement = pNext;
    }

    list.pHead = nullptr;
    list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
    // pNext와 pPrev를 알고 있으므로,
    // 하나의 원소만으로도 표현이 가능하다.

    Monster* pElement = FindMonster(list, name);

    if (pElement == nullptr)
    {
        return false;
    }

    if (list.pHead == list.pTail)
    {
        list.pHead = nullptr;
        list.pTail = nullptr;
    }
    else if (pElement == list.pHead)
    {
        list.pHead = pElement->pNext;
        list.pHead->pPrev = nullptr;        // dangling pointer 삭제
    }
    else if (pElement == list.pTail)
    {
        list.pTail = pElement->pPrev;
        list.pTail->pNext = nullptr;        // dangling pointer 삭제
    }
    else
    {
        pElement->pPrev->pNext = pElement->pNext;
        pElement->pNext->pPrev = pElement->pPrev;
    }
    delete pElement;

    return true;
}
