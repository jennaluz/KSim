/*
 * source/ksimDispatcher.cpp
 *
 * methods for dispatcher class.
 *
 */

    /*system-defined includes*/
#include <string>

    /*user-defined includes*/
#include "../header/ksimDispatcher.h"
#include "../header/ksimState.h"
#include "../header/ksimError.h"
#include "../header/ksimQueue.h"

    /*global variables*/
typedef int ticks;
typedef std::unordered_map<std::string, process*>::const_iterator iterator_t;

    /*method defines*/
//constructor
dispatcher::dispatcher()
{
    for (STATE_E i = NEW; i != STATES; i = (STATE_E)(i + 1)) {
        stateQueues[i] = new queue(i);
    }
}

//adding a process will always append to the NEW queue
ticks_t dispatcher::add(ticks_t ksimTicks, std::string processName)
{
    iterator_t exists = processTable.find(processName);

    if (exists != processTable.end()) {
        ksimError("'" + processName + "' already exists.");
        return 0;
    }

    stateQueues[NEW] -> add(processTable, ksimTicks, processName);
    return 32;
}
