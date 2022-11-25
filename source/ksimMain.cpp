/*
 * source/ksimMain.cpp
 *
 * description
 *
 */

    /*system-defined includes*/
#include <iostream> //getline()
#include <string>   //std::string
#include <vector>   //std::vector

    /*user-defined includes*/
#include "../header/ksimGetInput.h"
#include "../header/ksimTokenize.h"

    /*main*/
int main()
{
    int ksimTicks = 0;                      //total number of kernel ticks. to print, use std::setw(9), std::setfill('0'), tick %1000000000
    std::string buffer = "";                //user commands
    std::vector<std::string> bufferArgv;    //tokenized user commands

    //while (1) {
        ksimGetInput(ksimTicks, &buffer);

        ksimTokenize(buffer, bufferArgv);

        for (int i = 0; i < bufferArgv.size(); i++) {
            std::cout << bufferArgv[i] << std::endl;
        }
    //}
}
