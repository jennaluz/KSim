/*
 * source/hash_table.cpp
 *
 *
 */

#include <iostream>
#include <string>   //std::string   .size()     strcmp()

#include "../header/hash_table.h"
#include "../header/linked_list.h"
#include "../header/node.h"
#include "../header/process.h"

#define TABLE_SIZE 50

/*constructor*/
HashTable_t::HashTable_t()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

/*destructor*/
HashTable_t::~HashTable_t()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
}

/*
 * called by Dispatcher_t add() method.
 * hashes a string and returns an index into the hash table.
 */
int HashTable_t::hash(std::string key)
{
    int index = 0;

    for (int i = 0; i < key.size(); i++) {
        index += key[i];
        index += i;
    }

    index %= TABLE_SIZE;

    return index;
}

/*
 * searches through hash table to find key.
 * possibly calls LinkedList_t find() method to find key.
 * returns true if key is found and false if not found.
 */
bool HashTable_t::find(std::string key)
{
    int index = hash(key);

    if (table[index] == nullptr) {
        return false;
    }

    return table[index]->find(key);
}

/*
 * called by Dispatcher_t add() method.
 * adds a process that currently does not exist into hash table.
 * if table index already has a node object, then will add new process into its
 *  linked list alphabetically.
 * returns a pointer to the new node object.
 */
void HashTable_t::add(Node_t *newNode)
{
    int index = hash(newNode->key);

    if (table[index] != nullptr) {
        table[index]->add(newNode);
        return;
    }

    table[index] = new LinkedList_t(newNode);
    return;
}

void HashTable_t::remove(Node_t* deleteNode)
{
    std::string key = deleteNode->key;
    int index = hash(key);

    table[index]->remove(key);
}

/*
 * called by Dispatcher_t query() method.
 * prints the pid and state of the value corresponding to the passed
 *  key parameter.
 */
void HashTable_t::print(std::string pid)
{
    bool exists = false;
    int index = hash(pid);

    exists = table[index]->print(pid);

    if (exists == false) {
        //throw exception?
        return;
    }
}

/*
 * called by Dispatcher_t query() method.
 * prints all of the pid and state of the value corresponding to the passed
 *  key parameter.
 */
void HashTable_t::print_all()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            table[i]->print_all();
        }
    }
}
