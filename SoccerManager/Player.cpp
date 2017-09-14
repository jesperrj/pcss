#include <stdlib.h>
#include "Player.h"

//constructor
Player::Player():
    Person("J. Doe",18),
    strength(1),
    shots(1),
    motivation(1),
    goals(0) {}
Player::Player(string n,int a,int st, int sh, int mo):
    Person(n,a),
    strength(st),
    shots(sh),
    motivation(mo),
    goals(0) {}
//get set function
int Player::getGoals()
{
    return goals;
}
//player function
void Player::addGoal()
{
    goals++;
}

int Player::shootsOnGoal()
{
    shots=max(1,min(10,shots+rand()%3-1));
    int ret=max(1,min(10,shots+rand()%3-1));
    return ret;
}
int Player::getStrength()
{
    return strength;
}
int Player::getMotivation()
{
    return motivation;
}
