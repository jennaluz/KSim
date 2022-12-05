/*
 * source/node.cpp
 *
 */

#include <iostream>
#include <string>   //std::string

#include "../header/node.h"
#include "../header/process.h"

/*constructor*/
Node_t::Node_t(std::string key, Process_t *value)
{
    std::cout << "constructing " << key << " node..." << std::endl;
    this->key = key;
    this->value = value;
    this->queueNext = nullptr;
    this->processTableNext = nullptr;
}

/*destructor*/
Node_t::~Node_t()
{
    std::cout << "destructing " << this-> key << " node..." << std::endl;
    delete this->value;
}
