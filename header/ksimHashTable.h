/*
 * header/ksimHashTable.h
 *
 * header file for ksimHashTable.cpp.
 *
 */

    /*macros*/
#pragma once

    /*system-defined includes*/

    /*user-define includes*/
#include "ksimLinkedList.h"

    /*global variables*/
#define TABLE_SIZE 10

    /*class define*/
class hashTable_t {
    private:
        linkedList_t table[TABLE_SIZE];
    public:
};
