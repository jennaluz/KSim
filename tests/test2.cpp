#include <iostream>
#include <string>

int main()
{
    std::string buffer = "";
    std::string bufferTemp = "";

    std::cout << "Enter input: ";
    getline(std::cin, buffer);
    bufferTemp = buffer;

    int bufferArgc = 0;
    int start = 0;
    int end = 0;
    int bufferSize = buffer.length();
    std::string delimiter = " ";

    end = buffer.find(delimiter);
    while (end != -1) {
        if (end != start) {
            bufferArgc++;
        }

        start = end + delimiter.size();
        end = buffer.find(delimiter, start);
    }
    if (start != bufferSize) {
        bufferArgc++;
    }

    std::cout << bufferArgc << std::endl;
}
