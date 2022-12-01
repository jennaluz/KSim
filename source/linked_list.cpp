/*
 * source/linked_list.cpp
 *
 *
 */

#include <iostream> //std::cout     std::endl
#include <string>   //std::string

#include "../header/linked_list.h"
#include "../header/node.h"

/*constructor*/
LinkedList_t::LinkedList_t()
{
    head = nullptr;
    tail = nullptr;
}

/*constructor*/
LinkedList_t::LinkedList_t(Node_t *element)
{
    head = element;
    tail = element;
}

/*
 * searches through linked list to find Node_t object with matching key.
 * returns true if found and false if not found.
 */
bool LinkedList_t::find(std::string key)
{
    Node_t *tmp = head;

    while (tmp != nullptr) {
        if (tmp->key == key)
            return true;

        tmp = tmp->processTableNext;
    }

    return false;
}

/*
 * called by Dispatcher_t add() method.
 * adds a new Node_t object to the list with the assumption that at least one
 *  element is currently in the list.
 * inserts new Node_t alphabetically.
 */
void LinkedList_t::add(Node_t *newNode)
{
    tail->processTableNext = newNode;

    return;
}

/*
 * removes an element from list with the assumption that it exists.
 */
void LinkedList_t::remove(std::string key)
{
    Node_t* tmp = head;
    Node_t* tmpPrev = tmp;

    while (tmp != nullptr) {
        if (tmp->key == key) {
            tmpPrev->processTableNext = tmp->processTableNext;
            return;
        }

        tmpPrev = tmp;
        tmp = tmp->processTableNext;
    }

    return;
}

/*
 * called by HashTable_t print() method.
 * prints the pid and state of the value of the key parameter.
 */
bool LinkedList_t::print(std::string key)
{
    Node_t *tmp = head;

    while (tmp != nullptr) {
        if (tmp->key == key) {
            std::cout << "***\n";
            std::cout << "\tid: \"" + tmp->value->pid + "\"\n";
            std::cout << "\tstate: " + tmp->value->state + "\n";
            std::cout << "***\n";
            return true;
        }

        tmp = tmp->processTableNext;
    }

    return false;
}

/*
 * called by HashTable_t print_all() method.
 * prints the pid and state of the value of all the keys in its list.
 */
void LinkedList_t::print_all()
{
    Node_t *tmp = head;
    while (tmp != nullptr) {
        std::cout << "***\n";
        std::cout << "\tid: \"" + tmp->value->pid + "\"\n";
        std::cout << "\tstate: " + tmp->value->state + "\n";
        std::cout << "***\n";

        tmp = tmp->processTableNext;
    }

    return;
}
