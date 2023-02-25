/*
 * ksim/source/nope.cpp
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * constructs and destructs Node_t objects.
 * points to Process_t object and is used to access Process_t information.
 */

#include <string>   //std::string

#include "../header/node.h"
#include "../header/process.h"

/*constructor*/
Node_t::Node_t(std::string key, Process_t *value)
{
    this->key = key;
    this->value = value;
    this->queueNext = nullptr;
    this->processTableNext = nullptr;
}

/*destructor*/
Node_t::~Node_t()
{
    delete this->value;
}
