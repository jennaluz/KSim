/*
 * source/get_input.cpp
 *
 * prints the user prompt, reads in user commands, and stores it in buffer.
 */

#include <iostream> //std::cout     std::endl
#include <string>   //std::string   getline()
#include <iomanip>  //std::setw()   std::setfill()

#include "../header/get_input.h"

void ksimgetinput(int ticks, std::string &buffer)
{
        //print user prompt
    std::cout << "ksim-" << std::setw(9) << std::setfill('0') << ticks % 1000000000 << "> ";

        //get user input and store in buffer
    getline(std::cin, buffer);

    return;
}
