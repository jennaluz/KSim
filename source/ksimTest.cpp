typedef int ticks;

#include <iostream>
#include <string>

#include "../header/ksimDispatcher.h"

int main()
{
    ticks ksimTicks = 0;
    dispatcher ksimDispatcher;

    ksimTicks += ksimDispatcher.add(ksimTicks, "p1");
    ksimTicks += ksimDispatcher.add(ksimTicks, "b1");
    ksimTicks += ksimDispatcher.add(ksimTicks, "q1");
}
