/*
 * source/main.cpp
 *
 *
 */

#include <iostream>
#include <string>   //std::string
#include <vector>   //std::vector   .size()

#include "../header/dispatcher.h"
#include "../header/get_input.h"
#include "../header/tokenize.h"

int main()
{
    Dispatcher_t ksim;
    int ticks = 0;                          //total number of kernel ticks
    std::string buffer = "";                //user commands
    std::vector<std::string> bufferArgv;    //tokenized user commands
    int bufferArgc = 0;                     //amount of user commands


    while (1) {
        get_input(ticks, buffer);

        tokenize(buffer, bufferArgv, bufferArgc);

        std::string opcode = bufferArgv[0];

        if (opcode == "exit") {
            if (bufferArgc > 1) {
                //throw
                continue;
            }

            bufferArgv.clear();
            break;
        } else if (opcode == "add") {
            if (bufferArgc < 2) {
                //throw?
                continue;
            }

            ticks += ksim.add(ticks, bufferArgv[1]);
        } else if(opcode == "wait") {
            if (bufferArgc < 2) {
                continue;
            }

            ticks += ksim.wait(ticks, bufferArgv[1]);
        } else if(opcode == "io-event") {
            if (bufferArgc != 2) {
                //throw
                continue;
            }

            ticks += ksim.io_event(bufferArgv[1]);
        } else if (opcode == "query") {
            if (bufferArgc < 2) {
                //throw?
                continue;
            }

            ticks += ksim.query(bufferArgv[1]);
        } else if (opcode == "step") {
            ticks += ksim.step(ticks);
        } else if (opcode == "release") {
            ticks += ksim.release(ticks);
        } else {
            //throw?
        }

        bufferArgv.clear();
    }
}
