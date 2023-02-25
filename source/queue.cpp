/*
 * ksim/source/queue.cpp
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * essentially a LinkedList_t but with different methods.
 * points to a series of Node_t objects in a particular state, in the order of
 *  when they should be removed.
 */

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
 * adds a new element to Queue_t in ascending order of the Process_t lastRun
 *  data member.
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
