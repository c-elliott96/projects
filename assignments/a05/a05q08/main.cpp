// Name: Christian Elliott
// File: main.cpp

#include <iostream>
#include <cstdlib>
#include "Robot.h"
#include "world.h"

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
            test_print();
            break;
        case 2:
            test_move_north();
            break;
        case 3:
            test_move_south();
            break;
        case 4:
            test_move_east();
            break;
        case 5:
            test_move_west();
            break;
        case 6:
            test_inc_energylevel();
            break;
        case 7:
            test_dec_energylevel();
            break;
        case 8:
            test_init_and_print_world();
            break;
    }
    
    return 0;
}
