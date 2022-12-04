/*
 * source/dispatcher.cpp
 *
 */

#include <iostream>
#include <string>   //std::string   .size() std::to_string

#include "../header/dispatcher.h"
#include "../header/hash_table.h"
#include "../header/state.h"
#include "../header/queue.h"
#include "../header/node.h"
#include "../header/process.h"

/*
 * checks if a process exists.
 * creates a new process if it doesn't, and handles an error exception if it does.
 * adds a new process to the NEW queue as well as the processTable.
 */
int Dispatcher_t::add(int ticks, std::string pid)
{
    if (processTable.find(pid) == true) {
        std::cout << "Process name \"" << pid << "\" is already being hosted." << std::endl;
        return 0;
    }

    Process_t *newProcess = new Process_t(ticks, pid);
    Node_t *newNode = new Node_t(newProcess->pid, newProcess);

    processTable.add(newNode);
    stateQueue[NEW].add(newNode);

    return 32;
}

/*
 *
 */
int Dispatcher_t::step(int ticks)
{
    Node_t* tmp = nullptr;

        //remove from system all processes in the EXIT queue
    while (stateQueue[EXIT].head != nullptr) {
        tmp = stateQueue[EXIT].remove();
        processTable.remove(tmp);
        std::cout << "Process \"" << tmp->key << "\" is banished to the void." << std::endl;
        delete tmp;
    }

        //move the process with the oldest creation date from the NEW to the READY queue
    if (stateQueue[NEW].head != nullptr) {
        tmp = stateQueue[NEW].remove();

        tmp->value->state = "\"Ready\"";
        stateQueue[READY].add(tmp);

        std::cout << "Process \"" << tmp->key << "\" moved from New to Ready." << std::endl;
    }

        //advance at most one process from each I/O device in the BLOCKED queue to the READY queue
    for (State_e i = BLOCKED_0; i != EXIT; i = State_e(i + 1)) {
        if (stateQueue[i].head != nullptr) {
            if ((ticks - stateQueue[i].head->value->lastRun) >= 1024) {
                tmp = stateQueue[i].remove();

                tmp->value->state = "\"Ready\"";
                stateQueue[READY].add(tmp);

                std::cout << "Process \"" << tmp->key << "\" moved from Blocked (iodev=" << i - 3 << ") to Ready." << std::endl;
            }
        }
    }

        //move the process in the RUNNING queue to the READY queue
    if (stateQueue[RUNNING].head != nullptr) {
        tmp = stateQueue[RUNNING].remove();

        tmp->value->state = "\"Ready\"";
        tmp->value->lastRun = ticks;
        stateQueue[READY].add(tmp);

        std::cout << "Process \"" << tmp->key << "\" moved from Running to Ready." << std::endl;
    }

        //move the process that has been waiting the most time in the READY queue to the RUNNING queue
    if (stateQueue[READY].head != nullptr) {
        tmp = stateQueue[READY].remove();

        tmp->value->state = "\"Running\"";
        stateQueue[RUNNING].add(tmp);

        std::cout << "Process \"" << tmp->key << "\" moved from Ready to Running." << std::endl;
    }

    return 256;
}

/*
 *
 */
int Dispatcher_t::wait(int ticks, std::string ioEvent)
{
    if (ioEvent.size() != 1) {
        std::cout << "Invalid IO event number." << std::endl;
        return 0;
    }

    if (stateQueue[RUNNING].head == nullptr) {
        std::cout << "No process is currently running." << std::endl;
        return 0;
    }

    Node_t* tmp = nullptr;
    State_e blockEvent = State_e(stoi(ioEvent) + 3);

    tmp = stateQueue[RUNNING].remove();

    tmp->value->state = "\"Blocked\"\n\t\twaiting on device " + std::to_string(blockEvent - 3) + " since tick " + std::to_string(ticks % 1000000000);
    tmp->value->lastRun = ticks;
    stateQueue[blockEvent].add(tmp);

    std::cout << "Process \"" << tmp->key << "\" moved from Running to Blocked." << std::endl;

    return 1;
}

/*
 * simulates that specified io-device X is ready.
 * moves all processes waiting on the event from BLOCKED_X queue to READY queue.
 * 1 tick passes.
 */
int Dispatcher_t::io_event(std::string ioEvent)
{
    if (ioEvent.size() != 1) {
        std::cout << "Invalid IO event number." << std::endl;
        return 1;
    }

    Node_t* tmp = nullptr;
    State_e unblockEvent = State_e(stoi(ioEvent) + 3);

    if (stateQueue[unblockEvent].head == nullptr) {
        std::cout << "No processes are waiting on device " << unblockEvent - 3 << "." << std::endl;
        return 1;
    }

    while (stateQueue[unblockEvent].head != nullptr) {
        tmp = stateQueue[unblockEvent].remove();

        tmp->value->state = "\"Ready\"";
        stateQueue[READY].add(tmp);

        std::cout << "Process \"" << tmp->key << "\" moved from Blocked (iodev=" << unblockEvent - 3 << ") to Ready." << std::endl;
    }

    return 1;
}

/*
 * prints the pid and state of the user-specified process.
 * if user enters "query all" then all processes are printed.
 * no ticks pass.
 */
int Dispatcher_t::query(std::string pid)
{
    if (pid == "all") {
        processTable.print_all();
        return 0;
    }

    processTable.print(pid);

    return 0;
}

/*
 * moves the currently running process from the RUNNING queue to the EXIT queue.
 * if no processes are currently running, no ticks will pass.
 *  otherwise, 32 ticks are passed.
 */
int Dispatcher_t::release(int ticks)
{
    if (stateQueue[RUNNING].head == nullptr) {
        std::cout << "No process is currently Running." << std::endl;
        return 0;
    }

    Node_t* tmp = nullptr;

    tmp = stateQueue[RUNNING].remove();

    tmp->value->state = "\"Exit\"";
    tmp->value->lastRun = ticks;
    stateQueue[EXIT].add(tmp);

    std::cout << "Process \"" << tmp->key << "\" moved from Running to Exit." << std::endl;

    return 32;
}
