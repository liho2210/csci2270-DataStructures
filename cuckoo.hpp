#ifndef CUCKOO_H
#define CUCKOO_H

#include<iostream>
using namespace std;

struct cuckooNode
{
    int key;
    struct cuckooNode* next;
};

class Cuckoo
{
    int tableSize = 1019;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    cuckooNode* *table;

    cuckooNode* createNode(int key, cuckooNode* next);

public:

    Cuckoo();  // Constructor

    unsigned int hashFunction(int key);

    unsigned int hashFloor(int key);

    bool lookupItem();

    void insertItem(int key);

    void deleteItem();

    void print();

};

#endif
