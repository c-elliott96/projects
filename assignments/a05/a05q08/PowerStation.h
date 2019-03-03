#ifndef POWERSTATION_H
#define POWERSTATION_H


struct PowerStation
{
    int x, y;
    int energylevel;
    //int place[10][10];
};


void init(PowerStation & powerstation, int x, int y, int energylevel,
          char world[10][10]);
void print(const PowerStation & powerstation);
void dec_energylevel(PowerStation & powerstation, int d);

#endif

