/*
 * source/process.cpp
 *
 */

#include <iostream>
#include <string>   //std::string

#include "../header/process.h"

/*
 * constructor.
 * called when new process is created.
 * newly created processes should only be put in stateQueue[NEW].
 */
Process_t::Process_t(int ticks, std::string pid)
{
    std::cout << "constructing " << pid << " process..." << std::endl;
    this->lastRun = ticks;
    this->pid = pid;
    this->state = "\"New\"";
}

/*
 *
 */
Process_t::~Process_t()
{
    std::cout << "destructing " << this->pid << " process..." << std::endl;
}
