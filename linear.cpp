#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <time.h>
#include <chrono>
#include "linear.hpp"

using namespace std::chrono;
using namespace std;

Linear::Linear()
{
    table = new linearNode*[1019];

    for(int i=0; i<1019; i++)
    {
        table[i] = nullptr;
    }

    table2 = new linearNode*[1019];

    for(int i=0; i<1019; i++)
    {
        table2[i] = nullptr;
    }
}

void Linear::print()
{
    linearNode* temp = new linearNode;
    cout << endl << "table 1:" << endl;

    for (int i = 0; i < 1019; i++)
    {
        cout << i << "|| ";

        if (table[i])
        {
            temp = table[i];

            cout << temp->key;
        }

        cout << endl;
    }

    linearNode* temp2 = new linearNode;
    cout << endl << "table 2:" << endl;

    for (int i = 0; i < 1019; i++)
    {
        cout << i << "|| ";

        if (table2[i])
        {
            temp2 = table2[i];

            cout << temp2->key;
        }

        cout << endl;
    }
}

int Linear::randomNumber(int min, int max)
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) );
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

unsigned int Linear::hashFunction(int key)
{
    return (key % tableSize);
}

unsigned int Linear::hashFloor(int key)
{
   return floor(key/tableSize);
}

void Linear::results()
{
    cout << endl;
    cout << "***** Linear Probing Times (microseconds) *****" << endl;
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

linearNode* Linear::lookupItem(int key)
{
    int index = hashFunction(key);
    linearNode* temp = new linearNode;
    temp = table[index];
    return temp;
}

void Linear::insertItem(int key)
{
    int index1 = hashFunction(key);

    linearNode* temp = new linearNode;

    if (table[index1] == nullptr)
    {
        temp->key = key;
        table[index1] = temp;

        return;
    }
    else
    {
        while(table[index1] != nullptr)
        {
            index1++;
            if (index1 == tableSize)
            {
                index1 = 0;
            }
        }

        temp->key = key;
        table[index1] = temp;
    }
}

void Linear::deleteItem(int key)
{
    int index = hashFunction(key);

    table[index] = nullptr;
}

void Linear::loadData(int timeIndex, int a, int b, int list[])
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

    for (int i = 0; i < 10000000; i++)
    {
        random = randomNumber(0, 100000);
        found = lookupItem(random);
    }

    // timer ends
    auto stop = high_resolution_clock::now();

    //  results recorded
    auto duration = duration_cast<microseconds>(stop - start);
    timeData[timeIndex] = duration.count();
    cout << "time per 10,000,000 lookups: " << duration.count() << " microseconds" << endl;//totalTime << endl;

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

        deleteItem(random);
    }

    // timer ends
    auto stop2 = high_resolution_clock::now();

    // results recorded
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    timeData[timeIndex+1] = duration2.count();
    cout << "time per 100 deletes: " << duration2.count() << " microseconds" << endl;

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
    cout << "time per 100 inserts: " << duration3.count() << " microseconds" << endl;
}

// FLOOR FUNCTIONS ***********
// FLOOR FUNCTIONS ***********
// FLOOR FUNCTIONS ***********
// FLOOR FUNCTIONS ***********

linearNode* Linear::floorLookup(int key)
{
    int index = hashFloor(key);
    linearNode* temp2 = new linearNode;
    temp2 = table2[index];
    return temp2;
}

void Linear::floorInsert(int key)
{
    int index = hashFloor(key);

    linearNode* temp2 = new linearNode;

    if (table2[index] == nullptr)
    {
        temp2->key = key;
        table2[index] = temp2;

        return;
    }
    else
    {
        while(table2[index] != nullptr)
        {
            index++;
            if (index == tableSize)
            {
                index = 0;
            }
        }

        temp2->key = key;
        table2[index] = temp2;
    }
}

void Linear::floorDelete(int key)
{
    int index = hashFloor(key);

    table2[index] = nullptr;
}

void Linear::floorLoad(int timeindex, int a, int b, int list[])
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
    floorData[timeindex] = duration.count();
    cout << "time per 10000000 lookups: " << duration.count() << " microseconds" << endl;//totalTime << endl;

    // ***** DELETE *****
    cout << "delete opperation in progress..." << endl;

    // timer begins
    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < 10; i++)
    {
        while (!floorLookup(random))
        {
            random = randomNumber(0, 100000);
        }

        floorDelete(random);
    }

    // timer ends
    auto stop2 = high_resolution_clock::now();

    // results recorded
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    floorData[timeindex+1] = duration2.count();
    cout << "time per 100 deletes: " << duration2.count() << " microseconds" << endl;

    // ***** INSERT *****
    cout << "insert opperation in progress..." << endl;

    // timer begins
    auto start3 = high_resolution_clock::now();

    for (int i = 0; i < 10; i++)
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
    floorData[timeindex+2] = duration3.count();
    cout << "time per 100 inserts: " << duration3.count() << " microseconds" << endl;
}
