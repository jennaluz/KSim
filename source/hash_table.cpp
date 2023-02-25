/*
 * ksim/hash_table.cpp
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * implements an unordered map from scratch.
 * hashes a key based on its ascii value and its index in the key.
 * adds, removes, searches, and prints the HashTable_t, asking individual
 *  LinkedList_t objects to compute and return information at times.
 */

#include <iostream> //std::cout     std::endl
#include <string>   //std::string   .size()     strcmp()

#include "../header/hash_table.h"
#include "../header/linked_list.h"
#include "../header/node.h"
#include "../header/process.h"

#define TABLE_SIZE 50

/*constructor*/
HashTable_t::HashTable_t()
{
        //set all elements to nullptr
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

/*destructor*/
HashTable_t::~HashTable_t()
{
        //deallocate all memory
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
}

/*
 * hashes a string and returns an index into the hash table.
 */
int HashTable_t::hash(std::string key)
{
    int index = 0;
    int keyLength = key.size();

    for (int i = 0; i < keyLength; i++) {
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

/* removes the first element in the hash table.
 */
void HashTable_t::remove(Node_t* deleteNode)
{
    std::string key = deleteNode->key;
    int index = hash(key);

    table[index]->remove(key);

    if (table[index]->head == nullptr) {
        delete table[index];
        table[index] = nullptr;
    }
}

/*
 * prints the pid and state of the value corresponding to the passed
 *  key parameter.
 */
void HashTable_t::print(std::string pid)
{
    bool exists = false;
    int index = hash(pid);

    if (table[index] != nullptr)
        exists = table[index]->find(pid);

    if (exists == false) {
        std::cout << "Process \"" << pid << "\" not found." << std::endl;
        return;
    }

    table[index]->print(pid);

    return;
}

/*
 * prints all of the pid and state of the value corresponding to the passed
 *  key parameter.
 */
void HashTable_t::print_all()
{
    bool exists = false;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != nullptr) {
            exists = true;

            table[i]->print_all();
        }
    }

    if (exists == false) {
        std::cout << "No processes are being hosted." << std::endl;
    }

    return;
}
