/*
 * header/node.h
 *
 * header file for Node_t structure.
 */

#pragma once

#include <string>   //std::string

#include "process.h"

struct Node_t {
        //data members
    std::string key;
    Process_t *value;
    Node_t *queueNext;
    Node_t *processTableNext;
        //constructor
    Node_t(std::string key, Process_t *value);
        //destructor
    ~Node_t();
};
