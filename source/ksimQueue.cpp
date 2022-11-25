/*
 * source/ksimQueue.cpp
 *
 * methods for queue class.
 *
 */

    /*system-defined includes*/
#include <string>           //std::string
#include <unordered_map>    //std::unordered_map<>

    /*user-defined includes*/
#include "../header/ksimState.h"
#include "../header/ksimQueue.h"
#include "../header/ksimProcess.h"

    /*global variables*/
typedef int ticks_t;
typedef std::unordered_map<std::string, process*> unordered_map;

    /*methods defines*/
//constructor
queue::queue(STATE_E queueType)
{
    type = queueType;
    count = 0;
    head = NULL;
    tail = NULL;
}

//creates a new process and adds it to the caboose of the specified queue
void queue::add(unordered_map &processTable, ticks_t ksimTicks, std::string processName)
{
    process* newProcess = new process(ksimTicks, processName);
    (processTable)[processName] = newProcess;

    if (head == NULL) {
        head = tail = newProcess;
        return;
    }

    tail -> next = newProcess;
    tail = newProcess;
}
