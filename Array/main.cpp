#include <iostream>
#include <cstdlib>
#include <ctime>

#include "unsorted.h"

using namespace std;

void PrintList(UnsortedType& list)
{
    int length = list.GetLength();

    if (length == 0)
    {
        cout << "List is empty." << endl;
        return;
    }

    list.ResetList();

    for (int i = 0; i < length; i++)
    {
        ItemType item = list.GetNextItem();
        item.Print(cout);

        if (i < length - 1)
            cout << " ";
    }

    cout << endl;
}

void PrintHeadAndTail(UnsortedType& list)
{
    if (list.GetLength() == 0)
    {
        cout << "Head: N/A" << endl;
        cout << "Tail: N/A" << endl;
        return;
    }

    ItemType head = list.Head();

    cout << "Head: ";
    head.Print(cout);
    cout << endl;

    UnsortedType tail = list.Tail();

    cout << "Tail: ";
    PrintList(tail);
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    UnsortedType list;

    // POINT 1: EMPTY LIST
    cout << "========================================" << endl;
    cout << "POINT 1: EMPTY LIST" << endl;
    cout << "========================================" << endl;

    cout << "List: ";
    PrintList(list);

    PrintHeadAndTail(list);

    cout << endl;

    // Pick a random point between 1 and 49.
    int randomPoint = rand() % 49 + 1;

    // Fill the list with 50 random integers from 1 to 100.
    for (int i = 1; i <= 50; i++)
    {
        ItemType item;

        int number = rand() % 100 + 1;

        item.Initialize(number);
        list.PutItem(item);

        // POINT 2: RANDOM POINT
        if (i == randomPoint)
        {
            cout << "========================================" << endl;
            cout << "POINT 2: RANDOM POINT (" << i << " ITEMS)" << endl;
            cout << "========================================" << endl;

            cout << "List: ";
            PrintList(list);

            PrintHeadAndTail(list);

            cout << endl;
        }
    }

    // POINT 3: 50 ITEMS
    cout << "========================================" << endl;
    cout << "POINT 3: 50 ITEMS" << endl;
    cout << "========================================" << endl;

    cout << "List: ";
    PrintList(list);

    PrintHeadAndTail(list);

    cout << endl;

    return 0;
}