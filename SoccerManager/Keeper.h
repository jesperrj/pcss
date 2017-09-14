#ifndef KEEPER_H
#define KEEPER_H

#include "Player.h"

class Keeper : public Player
{
private:
    int reaction;
public:
    Keeper();
    Keeper(string n, int a, int s, int t, int m, int r);

    //functions
    bool saveShot(int shot);
};
#endif // PLAYER_H
