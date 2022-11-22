/*
 * source/ksimGetInput.cpp
 *
 * uses getline() to read in input from user and stores it in std::string buffer.
 *
 */

    /*system-defined includes*/
#include <iostream> //std::cout     std::endl       getline()
#include <string>   //std::string
#include <iomanip>  //std::setw()   std::setfill()

    /*user-defined includes*/
#include "../header/ksimGetInput.h"

    /*function define*/
void ksimGetInput(int ksimTicks, std::string *buffer)
{
        //user prompt
    std::cout << "ksim-" << std::setw(9) << std::setfill('0') << ksimTicks % 1000000000 << "> ";

        //get user input
    getline(std::cin, *buffer);
}
