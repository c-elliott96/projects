// Name: Christian Elliott
// File: Robot.cpp


#include <iostream>
#include "Robot.h"

void init(Robot & r, char name, int x, int y, int energylevel)
{
    r.name = name;
    r.x = x;
    r.y = y;
    r.energylevel = energylevel;
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


void move_north(Robot & robot)
{
    if (robot.energylevel < 1)
    {
        return;
    }

    else
    {
        --robot.y;
        --robot.energylevel;
    }
}


void move_south(Robot & robot)
{
    if (robot.energylevel < 1)
    {
        return;
    }

    else
    {
        ++robot.y;
        --robot.energylevel;
    }
}


void move_east(Robot & robot)
{
    if (robot.energylevel < 1)
    {
        return;
    }

    else
    {
        ++robot.x;
        --robot.energylevel;
    }
}


void move_west(Robot & robot)
{
    if (robot.energylevel < 1)
    {
        return;
    }

    else
    {
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
