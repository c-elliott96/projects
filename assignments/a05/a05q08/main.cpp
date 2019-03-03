// Name: Christian Elliott
// File: main.cpp

#include <iostream>
#include <cstdlib>
#include "Robot.h"
#include "world.h"
#include "PowerStation.h"

/*
void test_print()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    print(r);

    
}


void test_move_north()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    move_north(r);
    print(r);
    return;
}


void test_move_south()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    move_south(r);
    print(r);
    return;
}


void test_move_east()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    move_east(r);
    print(r);
    return;
}


void test_move_west()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    move_west(r);
    print(r);
    return;
}


void test_inc_energylevel()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    int i;
    std::cin >> i;
    inc_energylevel(r, i);
    print(r);
    return;
}


void test_dec_energylevel()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    int i;
    std::cin >> i;
    dec_energylevel(r, i);
    print(r);
    return;
}


void test_init_and_print_world()
{
    char world[10][10];
    init(world);
    print(world);
}


void test_set()
{
    char world[10][10];
    init(world);
    int x = 0;
    int y = 0;
    char c = ' ';
    std::cin >> x >> y >> c;
    set(world, x, y, c);
    print(world);
}



void test_init_and_print_power_station()
{
    int x = 0, y = 0;
    int energylevel;
    std::cin >> x >> y >> energylevel;
    PowerStation ps;
    init(ps, x, y, energylevel);
    print(ps);

    dec_energylevel(ps, 5);
    print(ps);
    return;
}
 */


void test_print_world_and_power_station()
{
    char world[10][10];
    PowerStation ps0;
    PowerStation ps1;
    PowerStation ps2;
    int x = 0;
    int y = 0;
    int energylevel = 50;
    //std::cin >> x >> y;
    init(world);
    init(ps0, x, y, energylevel, world);
    init(ps1, x, y, energylevel, world);
    init(ps2, x, y, energylevel, world);

    Robot r;
    Robot c;
    Robot d;

    r.name = 'r';
    c.name = 'c';
    d.name = 'd';

    init(r, x, y, world);
    init(c, x, y, world);
    init(d, x, y, world);

    int gold_x;
    int gold_y;

    init_gold(x, y, world, gold_x, gold_y);
    
    print(world);

    int time = 100;

    while(time > 0)
    {
        std::cout << "time: " << time << '\n';
        print(world);
        print(r);
        print(c);
        print(d);
        print(ps0);
        print(ps1);
        print(ps2);

        // if any bots hit gold
        if ((found_gold(r, world)) || (found_gold(c, world)) ||
            (found_gold(c, world)))
        {
            break;
        }

        // if they ALL run out of energy
        else if ((r.energylevel < 1) && (c.energylevel < 1) && (d.energylevel < 1))
        {
            break;
        }

        bool any_by_powerstation = false;
        if ((by_powerstation(r, world)) || (by_powerstation(c, world)) ||
            (by_powerstation(d, world)))
        {
            any_by_powerstation = true;
        }

        if (any_by_powerstation)
        {
            int count = 0;
            if (r.by_powerstation = true)
            {
                ++count;
            }

            if (c.by_powerstation = true)
            {
                ++count;
            }

            if (d.by_powerstation = true)
            {
                ++count;
            }

            if (r.by_powerstation = true)
            {
                r.energylevel += 1;
            }

            if (c.by_powerstation = true)
            {
                c.energylevel += 1;
            }

            if (d.by_powerstation = true)
            {
                d.energylevel += 1;
            }
  
        }
        move_bot(r, world);
        move_bot(c, world);
        move_bot(d, world);
        --time;
        
    }

    return;
    
}


int main()
{
    //int seed;
    //std::cin >> seed;
    //srand(seed);

    int option = 0;
    std::cin >> option;
    switch(option)
    {
        case 1:
            //test_print();
            break;
        case 2:
            //test_move_north();
            break;
        case 3:
            //test_move_south();
            break;
        case 4:
            //test_move_east();
            break;
        case 5:
            //test_move_west();
            break;
        case 6:
            //test_inc_energylevel();
            break;
        case 7:
            //test_dec_energylevel();
            break;
        case 8:
            //test_init_and_print_world();
            break;
        case 10:
            //test_init_and_print_power_station();
            break;
        case 11:
            test_print_world_and_power_station();
            break;
    }
    
    return 0;
}
