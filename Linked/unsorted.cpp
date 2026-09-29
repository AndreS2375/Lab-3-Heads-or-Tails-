#include "unsorted.h"
#include <new>

struct NodeType
{
    ItemType info;
    NodeType* next;
};

UnsortedType::UnsortedType()
{
    length = 0;
    listData = NULL;
    currentPos = NULL;
}

bool UnsortedType::IsFull() const
{
    NodeType* location;

    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc&)
    {
        return true;
    }
}

int UnsortedType::GetLength() const
{
    return length;
}

void UnsortedType::MakeEmpty()
{
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }

    length = 0;
    currentPos = NULL;
}

void UnsortedType::PutItem(ItemType item)
{
    NodeType* location = new NodeType;

    location->info = item;
    location->next = listData;

    listData = location;

    length++;
}

ItemType UnsortedType::GetItem(ItemType& item, bool& found)
{
    bool moreToSearch;
    NodeType* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(location->info))
        {
            case LESS:
            case GREATER:
                location = location->next;
                moreToSearch = (location != NULL);
                break;

            case EQUAL:
                found = true;
                item = location->info;
                break;
        }
    }

    return item;
}

void UnsortedType::DeleteItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;

    if (item.ComparedTo(listData->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while (item.ComparedTo((location->next)->info) != EQUAL)
            location = location->next;

        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
}

void UnsortedType::ResetList()
{
    currentPos = NULL;
}

ItemType UnsortedType::GetNextItem()
{
    ItemType item;

    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;

    item = currentPos->info;

    return item;
}

UnsortedType::~UnsortedType()
{
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

// Returns the last item inserted.
// Big-O: O(1)
ItemType UnsortedType::Head() const
{
    return listData->info;
}

// Returns a new list with the last item inserted removed.
// Big-O: O(n)
UnsortedType UnsortedType::Tail() const
{
    UnsortedType newList;

    NodeType* current = listData->next;
    NodeType* newLast = NULL;

    while (current != NULL)
    {
        NodeType* newNode = new NodeType;

        newNode->info = current->info;
        newNode->next = NULL;

        if (newList.listData == NULL)
        {
            newList.listData = newNode;
        }
        else
        {
            newLast->next = newNode;
        }

        newLast = newNode;
        newList.length++;

        current = current->next;
    }

    return newList;
}