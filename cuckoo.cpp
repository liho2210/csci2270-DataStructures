#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "cuckoo.hpp"


using namespace std;

cuckooNode* Cuckoo::createNode(int key, cuckooNode* next)
{
    cuckooNode* nw = new cuckooNode;
    nw->key = key;
    nw->next = next;
    return nw;
}

Cuckoo::Cuckoo()
{
    table = new cuckooNode*[1019];

    for(int i=0; i<1019; i++)
    {
        table[i] = nullptr;
    }
}

unsigned int Cuckoo::hashFunction(int key)
{
    return (key % tableSize);
}

unsigned int Cuckoo::hashFloor(int key)
{
   return floor(key/tableSize);
}

bool Cuckoo::lookupItem()
{
    cout << "lookupItem" << endl;
    return true;
}

void Cuckoo::insertItem(int key)
{
    int index1 = hashFunction(key);
    //int index2 = hashFloor(key);

    cuckooNode* temp = new cuckooNode;

    if (table[index1] == nullptr)
    {
        temp->key = key;
        temp->next = NULL;
        table[index1] = temp;
        //delete temp;
        return;
    }
    else
    {
        cuckooNode* temp2 = new cuckooNode;
        temp2->key = key;
        temp2->next = NULL;

        temp = table[index1];
        temp->next = temp2;
        //table[index1]->next = temp;
        //delete temp;
        return;
    }


}

void Cuckoo::deleteItem()
{
    cout << "deleteItem" << endl;
}

void Cuckoo::print()
{
    cuckooNode* temp = new cuckooNode;
    cout << "table 1:" << endl;

    for (int i = 0; i < 102; i++)
    {
        temp = table[i];
        cout << i <<"|| " << temp->key << " ";

        while (temp->next)
        {
            temp = temp->next;
            cout << temp->key << " ";
        }

        cout << endl;
    }
}
