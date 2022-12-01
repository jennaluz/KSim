/*
 * source/tokenize.cpp
 *
 * parses buffer and store tokenized arguments into bufferArgv vector.
 */

#include <string>   //std::string   length()    find()  substr()
#include <vector>   //std::vector   push_back() size()

void tokenize(std::string buffer, std::vector<std::string> &bufferArgv, int &bufferArgc)
{
        //initialize variables
    int start = 0;
    int end = 0;
    int bufferSize = buffer.length();
    std::string delimiter = " ";

    end = buffer.find(delimiter);

    while (end != -1) {
        if (end != start)
            bufferArgv.push_back(buffer.substr(start, end - start));

        start = end + delimiter.size();
        end = buffer.find(delimiter, start);
    }

    if (start < bufferSize)
        bufferArgv.push_back(buffer.substr(start, bufferSize - start));

    bufferArgc = bufferArgv.size();

    return;
}
