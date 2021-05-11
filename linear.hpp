#ifndef LINEAR_H
#define LINEAR_H

#include<iostream>
using namespace std;

struct linearNode
{
    int key;
};

class Linear
{
    int tableSize = 1019;

    float timeData[18];
    float floorData[18];

    linearNode* *table;
    linearNode* *table2;

public:

    Linear();  // Constructor

    void results();

    void print();

    int randomNumber(int min, int max);

    // MODULO FUNCTIONS

    unsigned int hashFunction(int key);

    linearNode* lookupItem(int key);

    void insertItem(int key);

    void deleteItem(int key);

    void loadData(int timeIndex, int a, int b, int list[]);

    //FLOOR FUNCTIONS

    unsigned int hashFloor(int key);

    linearNode* floorLookup(int key);

    void floorInsert(int key);

    void floorDelete(int key);

    void floorLoad(int timeIndex, int a, int b, int list[]);

};

#endif
