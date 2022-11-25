#include <iostream>
#include <string>

int main()
{
    /*
    std::string *p = &a;
    std::string **v = new std::string*[2];
    v[0] = &a;
    v[1] = p;
    */

    /*
    std::string a = "abc";
    std::string *p = new std::string[2];
    p[0] = a;
    p[1] = "def";

    for (int i = 0; i < 2; i++) {
        std::cout << p[i] << std::endl;
    }

    free(p);
    */

    std::string arr[3];

    arr[0] = "jenna";
    arr[1] = "luz";
    arr[2] = "pura";

    std::string *ptr = new std::string[3];
    ptr = arr;

    for (int i = 0; i < 3; i++) {
        std::cout << ptr[i] << std::endl;
    }

    delete[] ptr;
}
