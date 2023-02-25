/*
 * ksim/header/dispatcher.h
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * header file for Dispatcher_t class in ../source/dispatcher.cpp.
 *
 * orchestrates the addition, removal, and shuffling of processes within
 *  each state Queue_t and the HashTable_t process table.
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
