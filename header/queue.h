/*
 * /home/pura0273/homework/04/header/queue.h
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * header file for Queue_t structure in ../source/queue.cpp.
 *
 * essentially a LinkedList_t but with different methods.
 * points to a series of Node_t objects in a particular state, in the order of
 *  when they should be removed.
 */

#pragma once

#include "node.h"
#include "process.h"
#include "state.h"

struct Queue_t {
        //data members
    Node_t* head;
    Node_t* tail;
        //constructor
    Queue_t();
        //destructor
    ~Queue_t();
        //methods
    void add(Node_t *newNode);
    Node_t* remove();
};
