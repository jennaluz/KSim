/*
 * header/dispatcher.h
 *
 * header file for Dispatcher_t class.
 */

#pragma once

#include <string>   //std::string

#include "hash_table.h"
#include "queue.h"
#include "state.h"

class Dispatcher_t {
private:
    HashTable_t processTable;
    Queue_t stateQueue[STATES];
public:
        //methods
    int add(int ticks, std::string pid);
    int step(int ticks);
    int wait(int ticks, std::string ioEvent);
    int io_event(std::string ioEvent);
    int query(std::string pid);
    int release(int ticks);
};
