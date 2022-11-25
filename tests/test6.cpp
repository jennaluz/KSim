#include <iostream>

enum iterate {
    one,
    two,
    three,
    last,
};

int main()
{
    int arr[3] = {1, 2, 3};

    for (iterate i = one; i != last; i = (iterate)(i + 1)) {
        std::cout << arr[i] << std::endl;
    }
}
