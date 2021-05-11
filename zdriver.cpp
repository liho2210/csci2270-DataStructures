#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <chrono>
#include <string>
#include "linked.hpp"
#include "bbst.hpp"
#include "linear.hpp"
#include "cuckoo.hpp"
using namespace std;

void displayMenu()
{
    cout << "select a process:" << endl;
    cout << "1. Chaining with Linked List" << endl;
    cout << "2. Chaining with a Balanced BST" << endl;
    cout << "3. Linear Probing" << endl;
    cout << "4. Cuckoo Hashing" << endl;
    cout << "5. Print Table" << endl;
    cout << "6. Print Results" << endl;
    cout << "7. Exit Program" << endl;
}

void openFile(string fileName, int list[])
{
    // load file
    ifstream myFile;
    string loaded;

    // open file
    myFile.open(fileName);
    if (myFile.is_open())
    {
        string line = "";

        // capture unparsed data
        while (getline(myFile, line))
        {
            loaded = line;
        }

        // close file
        myFile.close();
   }

   // capture token
   istringstream ss(loaded);
   string token;
   int counter = 0;

   while (getline(ss, token, ','))
   {
       list[counter] = stoi(token);

       counter++;
       if (counter >= 1019)
       {
           return;
       }
   }
}

bool fileSelect()
{
    int x;
    cout << "select a file:" << endl;
    cout << "1. dataSetA.csv" << endl;
    cout << "2. dataSetC.csv" << endl;
    cin >> x;

    if (x == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // temp array to hold initial data
    int tempList[1019];

    // objects unique to each collision method
    Linked newList;
    BBST newTree;
    Linear newLinear;
    Cuckoo newCuckoo;

    int choice = 0;
    int subChoice = 0;
    int printChoice = 0;
    float results[72];

    // select an initial data file
    bool file = fileSelect();
    if (file)
    {
        openFile("dataSetA.csv", tempList);
    }
    else
    {
        openFile("dataSetC.csv", tempList);
    }

    // main loop
    while (choice != 7)
    {
        cout << endl;
        displayMenu();
        cin >> choice;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            displayMenu();
            cin >> choice;
        }

        // linked list
        if (choice == 1)
        {

            // ***** load factor 0.1 *****
            cout << endl << "                                                    PROGRESS: /*/ / / / / / / / / /" << endl;
            cout << "MODULO" << endl;
            newList.loadData(0, 0, 102, tempList);

            cout << endl << "FLOOR" << endl;
            newList.floorLoad(0, 0, 102, tempList);

            // ***** load factor 0.2 *****
            cout << endl << "                                                    PROGRESS: /*/*/ / / / / / / / /" << endl;
            cout << "MODULO" << endl;
            newList.loadData(3, 102, 204, tempList);

            cout << endl << "FLOOR" << endl;
            newList.floorLoad(3, 102, 204, tempList);

            // ***** load factor 0.5 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/ / / / / /" << endl;
            cout << "MODULO" << endl;
            newList.loadData(6, 204, 510, tempList);

            cout << endl << "FLOOR" << endl;
            newList.floorLoad(6, 204, 510, tempList);

            // ***** load factor 0.7 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/ / / /" << endl;
            cout << "MODULO" << endl;
            newList.loadData(9, 510, 714, tempList);

            cout << endl << "FLOOR" << endl;
            newList.floorLoad(9, 510, 714, tempList);

            // ***** load factor 0.9 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/*/*/ /" << endl;
            cout << "MODULO" << endl;
            newList.loadData(12, 714, 918, tempList);

            cout << endl << "FLOOR" << endl;
            newList.floorLoad(12, 714, 918, tempList);

            // ***** load factor 1.0 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/*/*/*/" << endl;
            cout << "MODULO" << endl;
            newList.loadData(15, 918, 1019, tempList);

            cout << endl << "FLOOR" << endl;
            newList.floorLoad(15, 918, 1019, tempList);
        }

        // balanced BST
        if (choice == 2)
        {
            // ***** load factor 0.1 *****
            cout << endl << "                                                    PROGRESS: /*/ / / / / / / / / /" << endl;
            cout << "MODULO" << endl;
            newTree.loadData(0, 0, 102, tempList);

            cout << endl << "FLOOR" << endl;
            newTree.floorLoad(0, 0, 102, tempList);

            // ***** load factor 0.2 *****
            cout << endl << "                                                    PROGRESS: /*/*/ / / / / / / / /" << endl;
            cout << "MODULO" << endl;
            newTree.loadData(3, 102, 204, tempList);

            cout << endl << "FLOOR" << endl;
            newTree.floorLoad(3, 102, 204, tempList);

            // ***** load factor 0.5 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/ / / / / /" << endl;
            cout << "MODULO" << endl;
            newTree.loadData(6, 204, 510, tempList);

            cout << endl << "FLOOR" << endl;
            newTree.floorLoad(6, 204, 510, tempList);

            // ***** load factor 0.7 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/ / / /" << endl;
            cout << "MODULO" << endl;
            newTree.loadData(9, 510, 714, tempList);

            cout << endl << "FLOOR" << endl;
            newTree.floorLoad(9, 510, 714, tempList);

            // ***** load factor 0.9 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/*/*/ /" << endl;
            cout << "MODULO" << endl;
            newTree.loadData(12, 714, 918, tempList);

            cout << endl << "FLOOR" << endl;
            newTree.floorLoad(12, 714, 918, tempList);

            // ***** load factor 1.0 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/*/*/*/" << endl;
            cout << "MODULO" << endl;
            newTree.loadData(15, 918, 1019, tempList);

            cout << endl << "FLOOR" << endl;
            newTree.floorLoad(15, 918, 1019, tempList);
        }

        // linear probing
        if (choice == 3)
        {
            // ***** load factor 0.1 *****
            cout << endl << "                                                    PROGRESS: /*/ / / / / / / / / /" << endl;
            cout << "MODULO" << endl;
            newLinear.loadData(0, 0, 102, tempList);

            cout << endl << "FLOOR" << endl;
            newLinear.floorLoad(0, 0, 102, tempList);

            // ***** load factor 0.2 *****
            cout << endl << "                                                    PROGRESS: /*/*/ / / / / / / / /" << endl;
            cout << "MODULO" << endl;
            newLinear.loadData(3, 102, 204, tempList);

            cout << endl << "FLOOR" << endl;
            newLinear.floorLoad(3, 102, 204, tempList);

            // ***** load factor 0.5 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/ / / / / /" << endl;
            cout << "MODULO" << endl;
            newLinear.loadData(6, 204, 510, tempList);

            cout << endl << "FLOOR" << endl;
            newLinear.floorLoad(6, 204, 510, tempList);

            // ***** load factor 0.7 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/ / / /" << endl;
            cout << "MODULO" << endl;
            newLinear.loadData(9, 510, 714, tempList);

            cout << endl << "FLOOR" << endl;
            newLinear.floorLoad(9, 510, 714, tempList);

            // ***** load factor 0.9 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/*/*/ /" << endl;
            cout << "MODULO" << endl;
            newLinear.loadData(12, 714, 918, tempList);

            cout << endl << "FLOOR" << endl;
            newLinear.floorLoad(12, 714, 918, tempList);

            // ***** load factor 1.0 *****
            cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/*/*/*/" << endl;
            cout << "MODULO" << endl;
            newLinear.loadData(15, 918, 1019, tempList);

            cout << endl << "FLOOR" << endl;
            newLinear.floorLoad(15, 918, 1019, tempList);
        }

        // cuckoo
        if (choice == 4)
        {
            // // ***** load factor 0.1 *****
            // cout << endl << "                                                    PROGRESS: /*/ / / / / / / / / /" << endl;
            // cout << "MODULO" << endl;
            // newCuckoo.loadData(0, 0, 102, tempList);
            //
            // cout << endl << "FLOOR" << endl;
            // newCuckoo.floorLoad(0, 0, 102, tempList);
            //
            // // ***** load factor 0.2 *****
            // cout << endl << "                                                    PROGRESS: /*/*/ / / / / / / / /" << endl;
            // cout << "MODULO" << endl;
            // newCuckoo.loadData(3, 102, 204, tempList);
            //
            // cout << endl << "FLOOR" << endl;
            // newCuckoo.floorLoad(3, 102, 204, tempList);
            //
            // // ***** load factor 0.5 *****
            // cout << endl << "                                                    PROGRESS: /*/*/*/*/*/ / / / / /" << endl;
            // cout << "MODULO" << endl;
            // newCuckoo.loadData(6, 204, 510, tempList);
            //
            // cout << endl << "FLOOR" << endl;
            // newCuckoo.floorLoad(6, 204, 510, tempList);
            //
            // // ***** load factor 0.7 *****
            // cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/ / / /" << endl;
            // cout << "MODULO" << endl;
            // newCuckoo.loadData(9, 510, 714, tempList);
            //
            // cout << endl << "FLOOR" << endl;
            // newCuckoo.floorLoad(9, 510, 714, tempList);
            //
            // // ***** load factor 0.9 *****
            // cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/*/*/ /" << endl;
            // cout << "MODULO" << endl;
            // newCuckoo.loadData(12, 714, 918, tempList);
            //
            // cout << endl << "FLOOR" << endl;
            // newCuckoo.floorLoad(12, 714, 918, tempList);
            //
            // // ***** load factor 1.0 *****
            // cout << endl << "                                                    PROGRESS: /*/*/*/*/*/*/*/*/*/*/" << endl;
            // cout << "MODULO" << endl;
            // newCuckoo.loadData(15, 918, 1019, tempList);
            //
            // cout << endl << "FLOOR" << endl;
            // newCuckoo.floorLoad(15, 918, 1019, tempList);
        }

        // print
        if (choice == 5)
        {
            printChoice = 0;
            //cout << "TEST" << endl;
            while ((printChoice != 1)&&(printChoice != 2)&&(printChoice != 3)&&(printChoice != 4))
            {
                cout << endl;
                cout << "print which table:" << endl;
                cout << "1. Chaining with Linked List" << endl;
                cout << "2. Chaining with a Balanced BST" << endl;
                cout << "3. Linear Probing" << endl;
                cout << "4. Cuckoo Hashing" << endl;

                cin >> printChoice;
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "print which table:" << endl;
                    cout << "1. Chaining with Linked List" << endl;
                    cout << "2. Chaining with a Balanced BST" << endl;
                    cout << "3. Linear Probing" << endl;
                    cout << "4. Cuckoo Hashing" << endl;
                    cin >> printChoice;
                }

                if (printChoice == 1)
                {
                    newList.print();
                    break;
                }

                if (printChoice == 2)
                {
                    newTree.print();
                    break;
                }

                if (printChoice == 3)
                {
                    newLinear.print();
                    break;
                }

                if (printChoice == 4)
                {
                    cout << "NAH FAM" << endl;
                    break;
                }


            }
        }

        // print Results
        if (choice == 6)
        {
            newList.results();
            newTree.results();
            newLinear.results();
        }
    }
}
