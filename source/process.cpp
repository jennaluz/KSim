/*
 * ksim/source/process.cpp
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * knows its pid, state, and when it was last running at any given time.
 */

#include <string>   //std::string

#include "../header/process.h"

/*
 * constructor.
 * newly created processes should only be put in stateQueue[NEW].
 */
Process_t::Process_t(int ticks, std::string pid)
{
    this->lastRun = ticks;
    this->pid = pid;
    this->state = "\"New\"";
}
