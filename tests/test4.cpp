#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> bufferArgv;

    bufferArgv.push_back("abc");
    bufferArgv.push_back("def");

    for (int i = 0; i < bufferArgv.size(); i++) {
        std::cout << bufferArgv[i] << std::endl;
    }
}
