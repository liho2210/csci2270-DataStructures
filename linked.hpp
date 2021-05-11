#ifndef LINKED_H
#define LINKED_H

#include<iostream>
using namespace std;

struct linkedNode
{
    int key;
    struct linkedNode* next;
};

class Linked
{
    int tableSize = 1019;

    float timeData[18];
    float floorData[18];

    linkedNode* *table;
    linkedNode* *table2;

public:

    Linked();  // Constructor

    void results();

    void print();

    int randomNumber(int min, int max);

    // MODULO FUNCTIONS

    unsigned int hashFunction(int key);

    bool lookupItem(int key);

    void insertItem(int key);

    void deleteItem(int key);

    void loadData(int timeIndex, int a, int b, int list[]);

    // FLOOR FUNCTIONS

    unsigned int hashFloor(int key);

    bool floorLookup(int key);

    void floorInsert(int key);

    void floorDelete(int key);

    void floorLoad(int timeIndex, int a, int b, int list[]);

};

#endif
