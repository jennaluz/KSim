/*
 * source/ksimMain.cpp
 *
 * description
 *
 */

    /*system-defined includes*/
#include <iostream> //getline()
#include <string>   //std::string

    /*user-defined includes*/
#include "../header/ksimGetInput.h"

    /*main*/
int main()
{
    int ksimTicks = 0;              //total number of kernel ticks. to print, use std::setw(9), std::setfill('0'), tick %1000000000
    std::string buffer = "";        //user commands
    std::string *bufferArgv = NULL; //tokenized user commands
    int bufferArgc = 0;             //number of user commands, used for freeing

    while (1) {
        ksimGetInput(ksimTicks, &buffer);
        std::cout << buffer << std::endl;
    }
}
