//main should only interact with Dispatcher_t
//will have to access Process_t to pass newly created object to both Queue_t and HashTable_t

#include <string>   //std::string

#include "hash_table.h"
#include "state.h"
#include "queue.h"
#include "process.h"

class Dispatcher_t {
    private:
        HashTable_t processTable;
        Queue_t stateQueue[STATES];
    public:
            //destructor
            //methods
        void add(int ticks, std::string name);
};

void Dispatcher_t::add(int ticks, std::string name)
{
    if (processTable.find(name) == true) {
        //throw?
        error("'" + name "' already exists.");
        return;
    }

    Process_t *tmp = new Process_t(ticks, name);

    stateQueue[NEW].add(tmp);
    processTable.add(tmp);

    return;
}

//---

//used by Dispatched_t and manipulates LinkedList_t only

#include <string>   //std::string   .size()

#include "linked_list.h"
#include "node.h"
#include "process.h"

#define TABLE_SIZE 50

struct HashTable_t {
        //data members
    LinkedList_t *table[TABLE_SIZE];
        //destructor
        //methods
    HashTable_t();
    int hash(std::string key);
    bool find(std::string key);
    Node_t *add(std::string key, Process_t *value);
};

HashTable_t::HashTable_t()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

int HastTable_t::hash(std::string key)
{
    int index = 0;

    for (int i = 0; i < key.size(); i++) {
        index += key[i];
        index += i;
    }

    index %= TABLE_SIZE;

    return index;
}

bool HashTable_t::find(std::string key)
{
    int index = hash(key);

    if (table[index] = nullptr) {
        return false;
    }

    return table[index].find(key);
}

Node_t *HashTable_t::add(std::string key, Process_t *value)
{
    int index = hash(key);

    Node_t *newNode = new Node_t(key, value);

    if (table[index] != nullptr) {
        table[index].add(newNode);
        return newNode;
    }

    table[index] = new LinkedList_t(newNode);
    return newNode;
}

//---

//used by HashTable_t only and manipulates Node_t objects

#include <string>   //std::string

#include "node.h"

struct LinkedList_t {
        //data members
    Node_t *head;
    Node_t *tail;
        //constructor
    LinkedList_t();
    LinkedList_t(Node_t *element);
        //methods
    bool find(std::string key);
    void add(Node_t *newNode);
};

LinkedList_t::LinkedList_t()
{
    head = nullptr;
    tail = nullptr;
}

LinkedList_t::LinkedList(Node_t *element)
{
    head = element;
    tail = element;
}

bool LinkedList::find(std::string key)
{
    Node_t *tmp = head;

    while (tmp != nullptr) {
        if (tmp->key == key)
            return true;

        tmp = tmp->next;
    }

    return false;
}

void LinkedList_t::add(Node_t *newNode)
{
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node_t *tmpPrev = nullptr;
    Node_t *tmpNext = head;

    while ((tmpNext->key < newNode->key) && (tmpNext != nullptr)) {
        tmpPrev = tmpNext;
        tmpNext = tmpNext->next;
    }

    tmpPrev->next = newNode;
    newNode->next = tmpNext;

    return;
}

//---

//used by Dispatcher_t and manipulates Node_t objects
//since both LinkedList_t and Queue_t manipulates Node_t, each struct should do their own work on Node_t objects
//  should not pass functionality to Node_t

#include "process.h"

struct Queue_t {
        //data members
    Node_t *head;
    Node_t *tail;
        //constructor
    Queue_t();
    void add(Process_t *element);
};

Queue_t::Queue_t()
{
    head = nullptr;
    tail = nullptr;
}

void Queue_t::add(Process_t *element)
{
    Node_t newNode = new node(element->name, element);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

//---

//used by LinkedList_t and Queue_t and stores a pointer to Process_t
//LinkedList_t uses Node_t to indirectly access Process_t
//Queue_t uses Node_t to indirectly access and change Process_t
//  when moving Process_t object, should move Node_t object pointing to Process_t object

#include <string>   //std::string

#include "process.h"

struct Node_t {
        //data members
    std::string key;
    Process_t *value;
    Node_t *next;
        //constructor
    Node_t(std::string key, Process_t *value);
};

Node_t::Node_t(std::string key, Process_t *value)
{
    this->key = key;
    this-value = value;
    this->next = nullptr;
}

//---

#include <string>   //std::string

#include "state.h"

//used by Node_t
//stores basic information, basically a PCB
//should just hold information, not do work on itself
struct Process_t {
        //data members
    int lastRun;
    std::string name;
    State_e state;
        //constructor
    Process_t(int ticks, std::string name);
};

Process_t::Process_t(int ticks, std::string name)
{
    this->lastRun = ticks;
    this->name = name;
    this->state = NEW;
}
