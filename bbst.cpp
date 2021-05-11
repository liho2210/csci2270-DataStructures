#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <time.h>
#include <chrono>
#include "bbst.hpp"

using namespace std::chrono;
using namespace std;

BBST::BBST()
{
    table = new bbstNode*[1019];

    for(int i=0; i<1019; i++)
    {
        table[i] = nullptr;
    }

    table2 = new bbstNode*[1019];

    for(int i=0; i<1019; i++)
    {
        table2[i] = nullptr;
    }
}

void BBST::print()
{
    bbstNode* temp = new bbstNode;
    cout << "table 1:" << endl;

    for (int i = 0; i < 1019; i++)
    {
        cout << i << "|| ";

        if (table[i])
        {
            temp = table[i];

            cout << temp->key << " ";

            printHelper(temp);

            cout << endl;
        }
        else
        {
            cout << endl;
        }
    }
}

void BBST::printHelper(bbstNode* root)
{
    if (root->left != NULL)
    {
        cout << root->left->key << " ";
        printHelper(root->left);
    }

    if (root->right != NULL)
    {
        cout << root->right->key << " ";
        printHelper(root->right);
    }
}

bbstNode* BBST::lookupItemHelper(bbstNode* root, int key, bool found)
{
    if (root->left != NULL)
    {
        if (root->left->key == key)
        {
            found = true;
            return root->left;
        }

        lookupItemHelper(root->left, key, found);
    }

    if (root->right != NULL)
    {
        if (root->right->key == key)
        {
            found = true;
            return root->right;
        }

        lookupItemHelper(root->right, key, found);
        //return;
    }

    found = false;
    return nullptr;
}

void BBST::insertItemHelper(bbstNode* root, int key)
{
    bbstNode* temp = new bbstNode;

    if (key < root->key)
    {
        if (root->left)
        {
            insertItemHelper(root->left, key);
        }
        else
        {
            temp->key = key;
            temp->parent = root;
            temp->left = NULL;
            temp->right = NULL;

            root->left = temp;
        }
    }
    else if (key > root->key)
    {
        if (root->right)
        {
            insertItemHelper(root->right, key);
        }
        else
        {
            temp->key = key;
            temp->parent = root;
            temp->left = NULL;
            temp->right = NULL;

            root->right = temp;
        }
    }
}

int BBST::randomNumber(int min, int max)
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) );
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

unsigned int BBST::hashFunction(int key)
{
    return (key % tableSize);
}

unsigned int BBST::hashFloor(int key)
{
   return floor(key/tableSize);
}

bbstNode* BBST::getMinValueNode(bbstNode* currNode)
{
    if (currNode->left == NULL)
    {
      return currNode;
    }

    return getMinValueNode(currNode->left);
}

void BBST::results()
{
    cout << endl;
    cout << "***** Balanced BST Times (microseconds) *****" << endl;
    cout << "          ***** MODULO FUNCTION *****" << endl << endl;
    cout << "Load Factor 0.1:" << endl;
    cout << "10,000,000 Lookups: " << timeData[0] << endl;
    cout << "100 Deletes: " << timeData[1] << endl;
    cout << "100 Inserts: " << timeData[2] << endl << endl;
    cout << "Load Factor 0.2:" << endl;
    cout << "10,000,000 Lookups: " << timeData[3] << endl;
    cout << "100 Deletes: " << timeData[4] << endl;
    cout << "100 Inserts: " << timeData[5] << endl << endl;
    cout << "Load Factor 0.5:" << endl;
    cout << "10,000,000 Lookups: " << timeData[6] << endl;
    cout << "100 Deletes: " << timeData[7] << endl;
    cout << "100 Inserts: " << timeData[8] << endl << endl;
    cout << "Load Factor 0.7:" << endl;
    cout << "10,000,000 Lookups: " << timeData[9] << endl;
    cout << "100 Deletes: " << timeData[10] << endl;
    cout << "100 Inserts: " << timeData[11] << endl << endl;
    cout << "Load Factor 0.9:" << endl;
    cout << "10,000,000 Lookups: " << timeData[12] << endl;
    cout << "100 Deletes: " << timeData[13] << endl;
    cout << "100 Inserts: " << timeData[14] << endl << endl;
    cout << "Load Factor 1.0:" << endl;
    cout << "10,000,000 Lookups: " << timeData[15] << endl;
    cout << "100 Deletes: " << timeData[16] << endl;
    cout << "100 Inserts: " << timeData[17] << endl;

    cout << endl;
    cout << "         ***** FLOOR FUNCTION *****" << endl << endl;
    cout << "Load Factor 0.1:" << endl;
    cout << "10,000,000 Lookups: " << floorData[0] << endl;
    cout << "10 Deletes: " << floorData[1] << endl;
    cout << "10 Inserts: " << floorData[2] << endl << endl;
    cout << "Load Factor 0.2:" << endl;
    cout << "10,000,000 Lookups: " << floorData[3] << endl;
    cout << "10 Deletes: " << floorData[4] << endl;
    cout << "10 Inserts: " << floorData[5] << endl << endl;
    cout << "Load Factor 0.5:" << endl;
    cout << "10,000,000 Lookups: " << floorData[6] << endl;
    cout << "10 Deletes: " << floorData[7] << endl;
    cout << "10 Inserts: " << floorData[8] << endl << endl;
    cout << "Load Factor 0.7:" << endl;
    cout << "10,000,000 Lookups: " << floorData[9] << endl;
    cout << "10 Deletes: " << floorData[10] << endl;
    cout << "10 Inserts: " << floorData[11] << endl << endl;
    cout << "Load Factor 0.9:" << endl;
    cout << "10,000,000 Lookups: " << floorData[12] << endl;
    cout << "10 Deletes: " << floorData[13] << endl;
    cout << "10 Inserts: " << floorData[14] << endl << endl;
    cout << "Load Factor 1.0:" << endl;
    cout << "10,000,000 Lookups: " << floorData[15] << endl;
    cout << "10 Deletes: " << floorData[16] << endl;
    cout << "10 Inserts: " << floorData[17] << endl;
}

// MODULO FUNCTIONS ***********
// MODULO FUNCTIONS ***********
// MODULO FUNCTIONS ***********
// MODULO FUNCTIONS ***********

bbstNode* BBST::lookupItem(int key)
{
    int index = hashFunction(key);
    bbstNode* temp = new bbstNode;
    temp = table[index];
    bool found;

    if (!temp)
    {
        return nullptr;
    }
    else
    {
        if (temp->key == key)
        {
            return temp;
        }
        else
        {
            temp = lookupItemHelper(temp, key, found);
            if (found)
            {
                return temp;
            }
            else
            {
                return nullptr;
            }
        }
    }

    return nullptr;
}

void BBST::insertItem(int key)
{
    int index1 = hashFunction(key);

    bbstNode* temp = new bbstNode;

    if (table[index1] == nullptr)
    {
        temp->key = key;
        temp->parent = NULL;
        temp->right = NULL;
        temp->left = NULL;
        table[index1] = temp;

        return;
    }
    else
    {
        temp = table[index1];
        insertItemHelper(temp, key);
    }
}

bbstNode* BBST::deleteItem(bbstNode* temp, int key)
{
    if(temp == NULL)
    {
        return NULL;
    }
    else if (key < temp->key)
    {
        temp->left = deleteItem(temp->left, key);
    }
    else if (key > temp->key)
    {
        temp->right = deleteItem(temp->right, key);
    }
    else
    {
        // No child
        if (temp->left == NULL && temp->right == NULL)
        {
            temp = NULL;
        }
        // Only right child
        else if (temp->left == NULL)
        {
            bbstNode* newTemp = temp;
            temp = temp->right;
            //delete newTemp;
        }
        // Only left child
        else if (temp->right == NULL)
        {
            bbstNode* newTemp = temp;
            temp = temp->left;
            //delete newTemp;
        }
        // Both left and right child
        else
        {
            // Replace with Minimum from right subtree
            bbstNode* min = getMinValueNode(temp->right);
            temp->key = min->key;
            temp->right = deleteItem(temp->right, min->key);
        }
    }
    return temp;
}

void BBST::loadData(int timeIndex, int a, int b, int list[])
{
    for (int i = a; i < b; i++)
    {
        insertItem(list[i]);
    }

    // ***** LOOKUP *****
    cout << "lookup opperation in progress..." << endl;
    bool found = true;
    int random = randomNumber(0, 100000);

    // timer begins
    auto start = high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++)
    {
        random = randomNumber(0, 100000);
        found = lookupItem(random);
    }

    // timer ends
    auto stop = high_resolution_clock::now();

    // results recorded
    auto duration = duration_cast<microseconds>(stop - start);
    timeData[timeIndex] = duration.count();
    cout << "time per 10,000,000 lookups: " << duration.count() << " microseconds"  << endl;

    // ***** DELETE *****
    cout << "delete opperation in progress..." << endl;
    // timer begins
    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < 100; i++)
    {
        while (!lookupItem(random))
        {
            random = randomNumber(0, 100000);
        }

        bbstNode* temp = new bbstNode;
        int index = hashFunction(random);
        temp = table[index];

        deleteItem(temp, random);
    }

    // timer ends
    auto stop2 = high_resolution_clock::now();

    // results recorded
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    timeData[timeIndex+1] = duration2.count();
    cout << "time per 100 deletes: " << duration2.count() << " microseconds"  << endl;

    // ***** INSERT *****
    cout << "insert opperation in progress..." << endl;
    // timer begins
    auto start3 = high_resolution_clock::now();

    for (int i = 0; i < 100; i++)
    {
        while (lookupItem(random))
        {
            random = randomNumber(0, 100000);
        }

        insertItem(random);
    }

    // timer ends
    auto stop3 = high_resolution_clock::now();

    // results recorded
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    timeData[timeIndex+2] = duration3.count();
    cout << "time per 100 inserts: " << duration3.count() << " microseconds"  << endl;
}

// FLOOR FUNCTIONS ***********
// FLOOR FUNCTIONS ***********
// FLOOR FUNCTIONS ***********
// FLOOR FUNCTIONS ***********

bbstNode* BBST::floorLookup(int key)
{
    int index = hashFloor(key);
    bbstNode* temp = new bbstNode;
    temp = table2[index];
    bool found;

    if (!temp)
    {
        return nullptr;
    }
    else
    {
        if (temp->key == key)
        {
            return temp;
        }
        else
        {
            temp = lookupItemHelper(temp, key, found);
            if (found)
            {
                return temp;
            }
            else
            {
                return nullptr;
            }
        }
    }

    return nullptr;
}

void BBST::floorInsert(int key)
{
    int index1 = hashFloor(key);

    bbstNode* temp = new bbstNode;

    if (table2[index1] == nullptr)
    {
        temp->key = key;
        temp->parent = NULL;
        temp->right = NULL;
        temp->left = NULL;
        table2[index1] = temp;

        return;
    }
    else
    {
        temp = table2[index1];
        insertItemHelper(temp, key);
    }
}

bbstNode* BBST::floorDelete(bbstNode* temp, int key)
{
    if(temp == NULL)
    {
        return NULL;
    }
    else if (key < temp->key)
    {
        temp->left = floorDelete(temp->left, key);
    }
    else if (key > temp->key)
    {
        temp->right = floorDelete(temp->right, key);
    }
    else
    {
        // No child
        if (temp->left == NULL && temp->right == NULL)
        {
            //delete temp;
            temp = NULL;
        }
        // Only right child
        else if (temp->left == NULL)
        {
            bbstNode* newTemp = temp;
            temp = temp->right;
            //delete newTemp;
        }
        // Only left child
        else if (temp->right == NULL)
        {
            bbstNode* newTemp = temp;
            temp = temp->left;
            //delete newTemp;
        }
        // Both left and right child
        else
        {
            // Replace with Minimum from right subtree
            bbstNode* min = getMinValueNode(temp->right);
            temp->key = min->key;
            temp->right = floorDelete(temp->right, min->key);
        }
    }
    return temp;
}


void BBST::floorLoad(int timeIndex, int a, int b, int list[])
{
    for (int i = a; i < b; i++)
    {
        floorInsert(list[i]);
    }

    // ***** LOOKUP *****
    cout << "lookup opperation in progress..." << endl;
    bool found = true;
    int random = randomNumber(0, 100000);

    // timer begins
    auto start = high_resolution_clock::now();

    for (int i = 0; i < 10000000; i++)
    {
        random = randomNumber(0, 100000);
        found = floorLookup(random);
    }

    // timer ends
    auto stop = high_resolution_clock::now();

    //  results recorded
    auto duration = duration_cast<microseconds>(stop - start);
    floorData[timeIndex] = duration.count();
    cout << "time per 10,000,000 lookups: " << duration.count() << " microseconds"  << endl;

    // ***** DELETE *****
    cout << "delete opperation in progress..." << endl;
    // timer begins
    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < 100; i++)
    {
        while (!floorLookup(random))
        {
            random = randomNumber(0, 100000);
        }

        bbstNode* temp = new bbstNode;
        int index = hashFloor(random);
        temp = table2[index];

        floorDelete(temp, random);
    }

    // timer ends
    auto stop2 = high_resolution_clock::now();

    // results recorded
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    floorData[timeIndex+1] = duration2.count();
    cout << "time per 100 deletes: " << duration2.count() << " microseconds"  << endl;

    // ***** INSERT *****
    cout << "insert opperation in progress..." << endl;
    // timer begins
    auto start3 = high_resolution_clock::now();

    for (int i = 0; i < 100; i++)
    {
        while (floorLookup(random))
        {
            random = randomNumber(0, 100000);
        }

        floorInsert(random);
    }

    // timer ends
    auto stop3 = high_resolution_clock::now();

    // results recorded
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    floorData[timeIndex+2] = duration3.count();
    cout << "time per 100 inserts: " << duration3.count() << " microseconds"  << endl;
}
