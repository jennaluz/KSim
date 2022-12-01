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
    Node_t* tmpNext = head->queueNext;

    while (tmpNext != nullptr) {
        if (tmpNext->value->lastRun > newNode->value->lastRun) {
            tmp->queueNext = newNode;
            newNode->queueNext = tmpNext;
            return;
        }

        tmp = tmpNext;
        tmpNext = tmpNext->queueNext;
    }

    tmp->queueNext = newNode;
    newNode->queueNext = tmpNext;    //nullptr
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
