/*
 * header/ksimLinkedList.h
 *
 * header file for source/ksimLinkedList.cpp.
 *
 */

    /*macros*/
#pragma once

    /*system-defined includes*/

    /*user-defined includes*/
#include "ksimLinkedListNode.h"

    /*class define*/
class linkedList_t {
    private:
            //data members
        node_t *head;
        node_t *tail;
    public:
            //constructor
        linkedList_t();
};
