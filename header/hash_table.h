/*
 * ksim/header/hash_table.h
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * header file for HashTable_t structure in ../source/hash_table.cpp.
 *
 * implements an unordered map from scratch.
 * hashes a key based on its ascii value and its index in the key.
 * adds, removes, searches, and prints the HashTable_t, asking individual
 *  LinkedList_t objects to compute and return information at times.
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
