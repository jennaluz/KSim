/*
 * source/ksimProcess.cpp
 *
 * methods on process class.
 *
 */

    /*system-defined includes*/
#include <string>   //std::string

    /*user-defined includes*/
#include "../header/ksimState.h"
#include "../header/ksimProcess.h"

    /*global variables*/
typedef int ticks_t;

    /*method defines*/
process::process(ticks_t ksimTicks, std::string processName)
{
    lastRun = ksimTicks;
    name = processName;
    state = NEW;
    next = NULL;
}
