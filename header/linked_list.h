/*
 * ksim/header/linked_list.h
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * header file for LinkedList_t structure in ../source/linked_list.cpp.
 *
 * part of the hash table implementation.
 * points to a node at a particular index in the hash table.
 * in collision cases, a linked list of multiple Node_t objects at a particular index.
 * add, removes, searches, and prints Node_t information.
 */

#pragma once

#include <string>   //std::string

#include "node.h"

struct LinkedList_t {
        //data members
    Node_t *head;
    Node_t *tail;
        //constructor
    LinkedList_t(Node_t *element);
        //methods
    bool find(std::string key);
    void add(Node_t *newNode);
    void remove(std::string key);
    void print(std::string key);
    void print_all();
};
