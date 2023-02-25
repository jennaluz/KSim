/*
 * /home/pura0273/homework/04/header/node.h
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * header file for Node_t structure in ../source/node.cpp.
 *
 * constructs and destructs Node_t objects.
 * points to Process_t object and is used to access Process_t information.
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
