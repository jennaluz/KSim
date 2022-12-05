/*
 * header/process.h
 *
 * header file for Process_t structure.
 */

#pragma once

#include <string>   //std::string

struct Process_t {
        //data members
    int lastRun;
    std::string pid;
    std::string state;
        //constructor
    Process_t(int ticks, std::string pid);
    ~Process_t();
};
