// Name: Christian Elliott
// File: Robot.cpp


#include <iostream>
//#include "world.h"
#include "Robot.h"
#include "world.h"
#include "PowerStation.h"


void init(Robot & r, int x, int y, char world[10][10])
{
    // r.name = name;
    // r.x = x;
    // r.y = y;
    char name = r.name;
    
    srand ((unsigned int) time(NULL));
    r.x = rand() % 10;
    r.y = rand() % 10;
    r.energylevel = 100;

    while(is_occupied(world, r.x, r.y))
    {
        r.x = rand() % 10;
        r.y = rand() % 10;
    }

    world[r.x][r.y] = name;
}


void print(const Robot & robot)
{
    // Prints the instance variables of the robot. If the name, x, y,
    // energylevel of robot is 'c', 10, 20, 30, then the output is
    // <Robot: name=c, x=10, y=20, energylevel=30>
    // A newline is printed at the end.

    std::cout << "<Robot: name=" << robot.name << ": x=" << robot.x
              << ", y=" << robot.y << ", energylevel=" << robot.energylevel
              << ">\n";
}


void move_north(Robot & robot, char world[10][10])
{
    if (robot.energylevel < 1)
    {
        return;
    }

    else
    {
        // if (is_occupied(world, robot.x, robot.y -1))
        // {
        //     return;
        // }
        --robot.y;
        --robot.energylevel;
    }
}


void move_south(Robot & robot, char world[10][10])
{
    if (robot.energylevel < 1)
    {
        return;
    }

    else
    {
        // if (is_occupied(world, robot.x, robot.y + 1))
        // {
        //     return;
        // }
        ++robot.y;
        --robot.energylevel;
    }
}


void move_east(Robot & robot, char world[10][10])
{
    if (robot.energylevel < 1)
    {
        return;
    }

    else
    {
        // if (is_occupied(world, robot.x + 1, robot.y))
        // {
        //     return;
        // }
        ++robot.x;
        --robot.energylevel;
    }
}


void move_west(Robot & robot, char world[10][10])
{
    if (robot.energylevel < 1)
    {
        return;
    }

    else
    {
        // if (is_occupied(world, robot.x - 1, robot.y))
        // {
        //     return;
        // }
        --robot.x;
        --robot.energylevel;
    }
}


void inc_energylevel(Robot & robot, int i)
{
    robot.energylevel += i;
}


void dec_energylevel(Robot & robot, int i)
{
    robot.energylevel -= i;
}
