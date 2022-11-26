/*
 * source/main.cpp
 *
 *
 */

#include <iostream>
#include <string>   //std::string
#include <vector>   //std::vector   .size()

#include "../header/get_input.h"
#include "../header/tokenize.h"

int main()
{
    int ticks = 0;                          //total number of kernel ticks
    std::string buffer = "";                //user commands
    std::vector<std::string> bufferArgv;    //tokenized user commands

    get_input(ticks, buffer);

    tokenize(buffer, bufferArgv);

    for (int i = 0; i < bufferArgv.size(); i++) {
        std::cout << bufferArgv[i] << std::endl;
    }
}
