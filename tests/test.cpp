#include <iostream>
#include <string>

void setString(std::string x);
void setString(std::string *x);

int main()
{
    std::string a = "jenna";
    std::string b = "luz";

    setString(a);
    setString(&b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
}

void setString(std::string x)
{
    x = "pura";
}

void setString(std::string *x)
{
    *x = "pura";
}
