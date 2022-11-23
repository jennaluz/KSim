/*
 * source/ksimTokenize.cpp
 *
 *
 *
 */

    /*system-defined includes*/
#include <string>   //std::string   length()

    /*user-defined includes*/
#include "../header/ksimTokenize.h"

    /*function define*/
void ksimTokenize(std::string buffer, std::string **bufferArgv, int *bufferArgc)
{
        //initialize variables
    *bufferArgc = 0;    //refreshes bufferArgc
    int start = 0;
    int end = 0;
    int bufferSize = buffer.length();
    std::string delimiter = " ";

        //find number of buffer arugments
    end = buffer.find(delimiter);
    while(end != -1) {  //find() = -1 if delimiter is not found
        if (end != start) {
            (*bufferArgc)++;
        }

        start = end + delimiter.size();
        end = buffer.find(delimiter, start);
    }

        //check for final argument
    if (start != bufferSize) {
        (*bufferArgc)++;
    }

        //allocate memory for bufferArgv
    (*bufferArgv) = new std::string[*bufferArgc];

        //reinitialize variables
    start = 0;
    end = 0;

        //input argument value
    for (int i = 0; i < *bufferArgc; i++) {
        while ((end == start) || (end != -1)) {
            start = end + delimiter.size();
            end = buffer.find(delimiter, start);
        }

        if ((end == -1) && (start < bufferSize)) {
            (*bufferArgv)[i] = buffer.substr(start, bufferSize - start);
            continue;
        }

        (*bufferArgv)[i] = buffer.substr(start, end - start);
    }

    return;
}
