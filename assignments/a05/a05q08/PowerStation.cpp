// file: PowerStation.cpp
// name: Christian Elliott


#include <iostream>
//#include "PowerStation.h"
#include <ctime>
#include "Robot.h"
#include "world.h"
//#include "Robot.h"
#include "PowerStation.h"

void init(PowerStation & powerstation, int x, int y, int energylevel,
          char world[10][10])
{
    srand ((unsigned int) time(NULL));
    powerstation.x = rand() % 10;
    powerstation.y = rand() % 10;

    powerstation.energylevel = 100;

    while(is_occupied(world, powerstation.x, powerstation.y))
    {
        powerstation.x = rand() % 10;
        powerstation.y = rand() % 10;
        //world[powerstation.x][powerstation.y] = 'P';
        //std::cout << "in init(powerstation) while loop" << std::endl;
        //std::cout << "powerstation.x = " << powerstation.x
        //         << " powerstation.y = " << powerstation.y << std::endl;
    }
    world[powerstation.x][powerstation.y] = 'P';
    
    //std::cout << "completed init(powerstation)" << std::endl;
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
