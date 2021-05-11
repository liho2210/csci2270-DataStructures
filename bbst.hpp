#ifndef BBST_H
#define BBST_H

#include<iostream>
using namespace std;

struct bbstNode
{
    int key;
    struct bbstNode* parent;
    struct bbstNode* left;
    struct bbstNode* right;
};

class BBST
{
    int tableSize = 1019;

    float timeData[18];
    float floorData[18];

    bbstNode* *table;
    bbstNode* *table2;

public:

    BBST();  // Constructor

    void results();

    void print();

    void printHelper(bbstNode* root);

    int randomNumber(int min, int max);

    bbstNode* lookupItemHelper(bbstNode* root, int key, bool found);

    void insertItemHelper(bbstNode* root, int key);

    bbstNode* getMinValueNode(bbstNode* currNode);

    // MODULO FUNCTIONS

    unsigned int hashFunction(int key);

    bbstNode* lookupItem(int key);

    void insertItem(int key);

    bbstNode* deleteItem(bbstNode* temp, int key);

    void loadData(int timeIndex, int a, int b, int list[]);

    // FLOOR FUNCTIONS

    unsigned int hashFloor(int key);

    bbstNode* floorLookup(int key);

    void floorInsert(int key);

    bbstNode* floorDelete(bbstNode* temp, int key);

    void floorLoad(int timeIndex, int a, int b, int list[]);

};

#endif
