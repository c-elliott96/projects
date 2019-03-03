/******************************************************************************

File: world.cpp
Author: Christian Elliott

Implementation of world.h

*****************************************************************************/

#include <iostream>
#include <ctime>
//#include "world.h"
#include "Robot.h"
#include "world.h"
#include "PowerStation.h"


int rand_coordinate(int &) // random coordinate for wall starting locations
{
    return rand() % 10;
}


int rand_direction(int &) // rand 0-3 for wall direction
{
    return rand() % 4;
}


bool wall_collision(int x, int y, int direction, char world[10][10])
{
    switch (direction)
    {
        case 0: // building wall north
        { 
            for (int i = y; i > y - 4; --i)
            {
                if (world[i][y] != ' ')
                {
                    return false;
                }
            }
            return true;
            break;
        }
        case 1: // building wall south
        { 
            for (int i = y; i < y + 4; ++i)
            {
                if (world[i][y] != ' ')
                {
                    return false;
                }
            }
            return true;
            break;
        }
        case 2: // building wall east
        {
            for (int i = x; i < x + 4; ++i)
            {
                if (world[x][i] != ' ')
                {
                    return false;
                }
            }
            return true;
            break;
        }
        case 3: // building wall west
        {
            for (int i = x; i > x - 4; --i)
            {
                if (world[x][i] != ' ')
                {
                    return false;
                }
            }
            return true;
            break;
        }
    }
}


void fill_wall(int x, int y, int direction, char world[10][10])
{
    switch (direction)
    {
        case 0: // building wall north
        { 
            for (int i = y; i > y - 4; --i)
            {
                if (world[i][y] == ' ')
                {
                    world[i][y] = 'X';
                }
            }
            break;
        }
        case 1: // building wall south
        { 
            for (int i = y; i < y + 4; ++i)
            {
                if (world[i][y] == ' ')
                {
                    world[i][y] = 'X';
                }
            }
            break;
        }
        case 2: // building wall east
        {
            for (int i = x; i < x + 4; ++i)
            {
                if (world[x][i] == ' ')
                {
                    world[x][i] = 'X';
                }
            }
            break;
        }
        case 3: // building wall west
        {
            for (int i = x; i > x - 4; --i)
            {
                if (world[x][i] == ' ')
                {
                    world[x][i] = 'X';
                }
            }
            break;
        }
    }
}


bool in_bounds_check(int x, int y, int direction)
{
    switch (direction)
    {
        case 0: // building wall north
        {
            if (y >= 4)
                return true;
            else
                return false;
            break;
        }
        case 1: // building wall south
        {
            if (y <= 5)
                return true;
            else
                return false;
            break;
        }
        case 2: // building wall east
        {
            if (x <= 5)
                return true;
            else
                return false;
            break;
        }
        case 3: // building wall west
        {
            if (x >= 4)
                return true;
            else
                return false;
            break;
        }
    }
}


void init(char world[10][10])
{
    srand((unsigned int) time(NULL));
    // fill world[] with ' '
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            world[i][j] = ' ';
        }
    }

    // init walls here
    int x1, y1;
    int x2, y2;
    
    x1 = rand_coordinate(x1);
    y1 = rand_coordinate(y1);
    x2 = rand_coordinate(x2);
    y2 = rand_coordinate(y2);

    while (x1 == x2)
    {
        x1 = rand_coordinate(x1);
    }

    while (y1 == y2)
    {
        y1 = rand_coordinate(x1);
    }
    
    int direction_wall_1, direction_wall_2;

    direction_wall_1 = rand() % 4;
    direction_wall_2 = rand() % 4;

    /*
    std::cout << "direction of 1: " << direction_wall_1 << ' ';
    std::cout << "direction of 2: " << direction_wall_2 << ' ' << std::endl;
    std::cout << "coordinates of 1: " << x1 << ' ' << y1 << std::endl;
    std::cout << "coordinates of 2: " << x2 << ' ' << y2 << std::endl;
    */
    
    while (!(in_bounds_check(x1, y1, direction_wall_1)))
    {
        direction_wall_1 = rand() % 4;
        std::cout << "in while loop 1" << std::endl;
    }    

    fill_wall(x1, y1, direction_wall_1, world);

    while (!(in_bounds_check(x2, y2, direction_wall_2)))
    {
        direction_wall_2 = rand() % 4;
        x2 = rand_coordinate(x2);
        y2 = rand_coordinate(y2);
        std::cout << "in while loop 2" << std::endl;
    }
    
    while(!wall_collision(x2, y2, direction_wall_2, world))
    {
        std::cout << "in while loop 3" << std::endl;
        x2 = rand_coordinate(x2);
        y2 = rand_coordinate(y2);
        direction_wall_2 = rand() % 4;
        while (!(in_bounds_check(x2, y2, direction_wall_2)))
        {
            x2 = rand_coordinate(x2);
            y2 = rand_coordinate(y2);
            direction_wall_2 = rand() % 4;
            std::cout << "in while loop 4" << std::endl;
        }
        /*
        x2 = rand_coordinate(x2);
        y2 = rand_coordinate(y2);
        direction_wall_2 = rand() % 4;
        */
    }
    std::cout << "direction of 1: " << direction_wall_1 << ' ';
    std::cout << "direction of 2: " << direction_wall_2 << ' ' << std::endl;
    std::cout << "coordinates of 1: " << x1 << ' ' << y1 << std::endl;
    std::cout << "coordinates of 2: " << x2 << ' ' << y2 << std::endl;

    fill_wall(x2, y2, direction_wall_2, world);
}


void print(char world[10][10])
{
    std::cout << "   ";
    for (int i = 0; i <= 9; ++i)
    {
        std::cout << i;
    }
    std::cout << '\n';
    std::cout << "  XXXXXXXXXXXX\n";
    for (int i = 0; i <= 9; ++i)
    {
        std::cout << i << " X";
        for (int j = 0; j <= 9; ++j)
        {
            std::cout << world[i][j];
        }
        std::cout << "X\n";
    }
    std::cout << "  XXXXXXXXXXXX\n";   
}


void set(char world[10][10], int x, int y, char c)
{
    world[x][y] = c;
}


void clear(char world[10][10], int x, int y)
{
    world[x][y] = ' ';
}


bool is_unoccupied(char world[10][10], int x, int y)
{
    if (world[x][y] == ' ')
    {
        return true;
    }

    else
        return false;
}


bool is_occupied(char world[10][10], int x, int y)
{
    if (world[x][y] != ' ')
    {
        return true;
    }

    else
        return false;
}


void init_gold(int x, int y, char world[10][10], int & gold_x, int  & gold_y)
{
    srand ((unsigned int) time(NULL));
    x = rand() % 10;
    y = rand() % 10;

    while(is_occupied(world, x, y))
    {
        x = rand() % 10;
        y = rand() % 10;
    }
    world[x][y] = 'G';
    gold_x = x;
    gold_y = y;
}


bool found_gold(const Robot & r, char world[10][10])
{
    // check north
    if (world[r.x][r.y - 1] == 'G')
    {
        std::cout << "gold north" << '\n';
        return true;
    }

    // check south
    else if(world[r.x][r.y + 1] == 'G')
    {
        std::cout << "gold south" << '\n';
        return true;
    }
    
    // check east
    else if(world[r.x + 1][r.y] == 'G')
    {
        std::cout << "gold east" << '\n';
        return true;
    }

    // check west
    else if(world[r.x - 1][r.y] == 'G')
    {
        std::cout << "gold west" << '\n';
        return true;
    }

    // none of the above happened, return false
    else
        return false;
}

bool by_powerstation(Robot & r, char world[10][10])
{
    // check north
    if (world[r.x][r.y - 1] == 'P')
    {
        // r.by_powerstation = true;
        // if ((r.x == ps0.x) && (r.y - 1 == ps0.y))
        // {
            
        // }
        return true;
    }

    // check south
    else if(world[r.x][r.y + 1] == 'P')
    {
        r.by_powerstation = true;
        return true;
    }

    // check east
    else if(world[r.x + 1][r.y] == 'P')
    {
        r.by_powerstation = true;
        return true;
    }

    // check west
    else if(world[r.x - 1][r.y] == 'P')
    {
        r.by_powerstation = true;
        return true;
    }

    // none of the above happened, return false
    else
        return false;
}


void move_bot(Robot & r, char world [10][10])
{
    srand ((unsigned int) time(NULL));
    int d;
    d = rand() % 4;
    switch(d)
    {
        case 0:
            move_north(r, world);
            break;
        case 1:
            move_south(r, world);
            break;
        case 2:
            move_east(r, world);
            break;
        case 3:
            move_west(r, world);
            break;
    }
    return;
}

// Other functions ...
