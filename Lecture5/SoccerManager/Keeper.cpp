#include <stdlib.h>
#include "Keeper.h"

Keeper::Keeper():
    Player(),
    reaction(1){}
Keeper::Keeper(string n, int a, int s, int t, int m, int r):
    Player(n,a,s,t,m),
    reaction(r){}

//functions
bool Keeper::saveShot(int shot)
{
    int r=rand()%3-1;
    int ret=max(1,min(10,reaction+r));

    if(ret>=shot)
    {
        return true; //saved
    }else
    {
        return false; //SCOOOORE
    }
}
