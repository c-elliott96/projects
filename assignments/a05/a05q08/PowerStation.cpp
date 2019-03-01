// file: PowerStation.cpp
// name: Christian Elliott


#include <iostream>
#include "PowerStation.h"
#include <ctime>
#include "world.h"


void init(PowerStation & powerstation, int x, int y, int energylevel)
{
    srand ((unsigned int) time(NULL));
    powerstation.x = rand() % 10;
    powerstation.y = rand() % 10;

    powerstation.energylevel = 100;
}


void print(const PowerStation & powerstation)
{
    std::cout << "<PowerStation: x=" << powerstation.x << ", y="
              << powerstation.y << ", energylevel="
              << powerstation.energylevel << ">\n";
}


void dec_energylevel(PowerStation & powerstation, int d)
{
    powerstation.energylevel -= d;
}
