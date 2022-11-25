/*
 * source/ksimError.cpp
 *
 * prints error message to console.
 *
 */

    /*system-defined includes*/
#include <iostream> //std::cout     std::endl
#include <string>   //std::string

    /*user-defined includes*/
#include "../header/ksimError.h"

    /*function define*/
void ksimError(std::string errorMessage)
{
    std::cout << errorMessage << std::endl;

    return;
}
