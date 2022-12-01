#include <iostream>
#include <string>

int main()
{
    std::string buffer = "";

    getline(std::cin, buffer);

    int index = 0;
    for (int i = 0; i < buffer.size(); i++) {
        index += buffer[i];
        std::cout << index << std::endl;
    }

    index %= 10;

    std::cout << index << std::endl;

    return 0;
}
