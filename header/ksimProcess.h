/*
 * header/ksimProcess.h
 *
 * header file for ksimProcess.cpp.
 *
 */

    /*macros*/
#pragma once

    /*system-defined includes*/
#include <string>   //std::string

    /*user-defined includes*/
#include "ksimState.h"

    /*global variables*/
typedef int ticks_t;

    /*class define*/
struct process {
        //data members
    ticks_t lastRun;
    std::string name;
    STATE_E state;
    process* next;
        //constructor
    process(ticks_t ksimTicks, std::string processName);
};
