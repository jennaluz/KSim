/*
 * ksim/header/process.h
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * header file for Process_t structure in ../source/process.cpp.
 *
 * knows its pid, state, and when it was last running at any given time.
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
};
