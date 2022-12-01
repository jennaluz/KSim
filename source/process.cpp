/*
 * source/process.cpp
 *
 */

#include <string>   //std::string

#include "../header/process.h"

/*
 * constructor.
 * called when new process is created.
 * newly created processes should only be put in stateQueue[NEW].
 */
Process_t::Process_t(int ticks, std::string pid)
{
    this->lastRun = ticks;
    this->pid = pid;
    this->state = "\"New\"";
}
