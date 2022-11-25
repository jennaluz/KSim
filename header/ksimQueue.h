/*
 * header/ksimQueue.h
 *
 * header file for ksimQueue.cpp.
 *
 */

    /*macros*/
#pragma once

    /*system-defined includes*/
#include <string>           //std::string
#include <unordered_map>    //std::unordered_map<>

    /*user-defined includes*/
#include "ksimState.h"
#include "ksimProcess.h"

    /*global variables*/
typedef int ticks_t;
typedef std::unordered_map<std::string, process*> unordered_map;

    /*class define*/
struct queue {
        //data members
    STATE_E type;
    int count;
    process *head;
    process *tail;
        //constructor
    queue(STATE_E queueType);
        //destructor
        //methods
    void add(unordered_map &processTable, ticks_t ksimTicks, std::string processName);
};
