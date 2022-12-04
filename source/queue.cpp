/*
 * source/queue.cpp
 *
 */

#include <iostream>

#include "../header/queue.h"
#include "../header/node.h"
#include "../header/process.h"

/*constructor*/
Queue_t::Queue_t()
{
    head = nullptr;
    tail = nullptr;
}

/*destructor*/
Queue_t::~Queue_t()
{
    Node_t* tmpPrev = nullptr;

    while (head != nullptr) {
        tmpPrev = head;
        head = head->queueNext;

        delete tmpPrev;
    }

    tail = head;
}

/*
 * called by Dispatcher_t add() method.
 * adds a new element to the end of stateQueue[NEW].
 */
void Queue_t::add(Node_t *newNode)
{
    if (head == nullptr) {
        head = tail = newNode;
        newNode->queueNext = nullptr;
        return;
    }

    Node_t* tmp = head;
    Node_t* tmpPrev = nullptr;
    Node_t* tmpNext = tmp->queueNext;

    while (tmpNext != nullptr) {
        if (tmpNext->value->lastRun > newNode->value->lastRun) {
            tmp->queueNext = newNode;
            newNode->queueNext = tmpNext;
            return;
        }

        tmpPrev = tmp;
        tmp = tmpNext;
        tmpNext = tmpNext->queueNext;
    }

    if (tmp->value->lastRun < newNode->value->lastRun) {    //added to the end of the queue
        tmp->queueNext = newNode;
        newNode->queueNext = tmpNext;    //nullptr
        tail = newNode;
        return;
    }

    if (tmpPrev == nullptr) {
        newNode->queueNext = head->queueNext;
        head = newNode;
    }

    tmpPrev = newNode;
    newNode->queueNext = tmp;

    return;
}

/*
 * removes the first element in the list and returns a pointer to that element.
 */
Node_t* Queue_t::remove()
{
    Node_t* tmp = head;

    head = head->queueNext;

    if (head == nullptr) {
        tail = head;
    }

    return tmp;
}

void Queue_t::print()
{
    Node_t* tmp = head;
    int i = 0;

    while (tmp != nullptr) {
        std::cout << i << tmp->value->pid << std::endl;
        tmp = tmp->queueNext;
        i++;
    }

    return;
}
