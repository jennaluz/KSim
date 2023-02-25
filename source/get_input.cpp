/*
 * ksim/source/get_input.cpp
 * cs-240.wilder..........g++ -std=c++11..........jenna-luz pura
 * december 4, 2022.......pura0273@vandals.uidaho.edu
 *
 * prints the user prompt, reads in user commands, and stores it in buffer.
 */

#include <iostream> //std::cout     std::endl
#include <string>   //std::string   getline()
#include <iomanip>  //std::setw()   std::setfill()

#include "../header/get_input.h"

void get_input(int ticks, std::string &buffer)
{
        //prints user prompt
    std::cout << "ksim-" << std::setw(9) << std::setfill('0') << ticks % 1000000000 << "> ";

        //gets user input and stores in buffer
    getline(std::cin, buffer);

    return;
}
