/*
 * header/linked_list.h
 *
 * header file for LinkedList_t structure.
 */

#pragma once

#include <string>   //std::string

#include "node.h"

struct LinkedList_t {
        //data members
    Node_t *head;
    Node_t *tail;
        //constructor
    LinkedList_t();
    LinkedList_t(Node_t *element);
        //destructor
    ~LinkedList_t();
        //methods
    bool find(std::string key);
    void add(Node_t *newNode);
    void remove(std::string key);
    bool print(std::string key);
    void print_all();
};
