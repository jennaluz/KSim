/*
 * header/ksimDispatcher.h
 *
 * header file for ksimDispatcher.cpp.
 *
 */

    /*macros*/
#pragma once

    /*system-defined includes*/
#include <string>           //std::string
#include <unordered_map>    //std::unordered_map<>

    /*user-defined includes*/
#include "ksimState.h"
#include "ksimQueue.h"
#include "ksimProcess.h"

    /*global variables*/
typedef int ticks_t;
typedef std::unordered_map<std::string, process*> unordered_map;

    /*class define*/
class dispatcher {
    private:
        unordered_map processTable;
        queue *stateQueues[STATES];
    public:
            //constructor
        dispatcher();
            //methods
        ticks_t add(ticks_t ksimTicks, std::string processName);
};
