#include <iostream>
#include <cstring>
#include "MonsterList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
    Monster* pNew = new Monster{};  
    // ��� ���Ͽ��� ���� �ʱ�ȭ������ �ʱ�ȭ ���ص� �Ǳ��Ѵ�.
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
    // pNext�� pPrev�� �˰� �����Ƿ�,
    // �ϳ��� ���Ҹ����ε� ǥ���� �����ϴ�.

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
        list.pHead->pPrev = nullptr;        // dangling pointer ����
    }
    else if (pElement == list.pTail)
    {
        list.pTail = pElement->pPrev;
        list.pTail->pNext = nullptr;        // dangling pointer ����
    }
    else
    {
        pElement->pPrev->pNext = pElement->pNext;
        pElement->pNext->pPrev = pElement->pPrev;
    }
    delete pElement;

    return true;
}
