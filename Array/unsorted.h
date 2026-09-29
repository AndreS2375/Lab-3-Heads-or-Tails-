#include "ItemType.h"

// Unsorted List ADT - Array Based

class UnsortedType
{
public:
    UnsortedType();

    void MakeEmpty();

    bool IsFull() const;

    int GetLength() const;

    ItemType GetItem(ItemType, bool&);

    void PutItem(ItemType item);

    void DeleteItem(ItemType item);

    void ResetList();

    ItemType GetNextItem();

    // Returns the last item inserted into the list.
    // Precondition: List has been initialized and is not empty.
    // Postcondition: Returns the last item inserted.
    // Big-O: O(1)
    ItemType Head() const;

    // Returns a new list with the last item inserted removed.
    // Precondition: List has been initialized and is not empty.
    // Postcondition: Returns a new list with the last item removed.
    // Big-O: O(n)
    UnsortedType Tail() const;

private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};