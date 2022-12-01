/*
 * header/hash_table.h
 *
 * header file for HashTable_t structure.
 */

#pragma once

#include <string>   //std::string

#include "linked_list.h"
#include "node.h"
#include "process.h"

#define TABLE_SIZE 50

struct HashTable_t {
        //data members
    LinkedList_t *table[TABLE_SIZE];
        //constructor
    HashTable_t();
        //destructor
    ~HashTable_t();
        //methods
    int hash(std::string key);
    bool find(std::string key);
    void add(Node_t *newNode);
    void remove(Node_t *deleteNode);
    void print(std::string pid);
    void print_all();
};
