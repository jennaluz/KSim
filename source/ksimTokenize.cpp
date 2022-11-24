/*
 * source/ksimTokenize.cpp
 *
 * tokenizes buffer and stores its argument into vector bufferArgv.
 *
 */

    /*system-defined includes*/
#include <string>   //std::string   length()
#include <vector>   //std::vector

    /*user-defined includes*/
#include "../header/ksimTokenize.h"

    /*function define*/
void ksimTokenize(std::string buffer, std::vector<std::string> bufferArgv)
{
        //initialize variables
    //*bufferArgc = 0;    //refreshes bufferArgc
    int start = 0;
    int end = 0;
    int bufferSize = buffer.length();
    std::string delimiter = " ";

    end = buffer.find(delimiter);
    while (end != -1) {
        if (end != start) {
            (bufferArgv).push_back(buffer.substr(start, end - start));
        }

        start = end + delimiter.size();
        end = buffer.find(delimiter, start);
    }

    if (start < bufferSize) {
        (bufferArgv).push_back(buffer.substr(start, bufferSize - start));
    }

    return;
}
