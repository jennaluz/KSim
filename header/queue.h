/*
 * header/queue.h
 *
 * header file for Queue_t structure.
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
