/*
 * source/node.cpp
 *
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
