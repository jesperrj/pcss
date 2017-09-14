#ifndef PLAYER_H
#define PLAYER_H

#include "Person.h"

class Player : public Person
{
private:
    int strength; // 1-10
    int shots; // 1-10
    int motivation; // 1-10
    int goals;
public:
    //super
    //typedef Player super;
    //constructor
    Player();
    Player(string n,int a,int st, int sh, int mo);
    //get set function
    int getGoals();
    //player function
    void addGoal();
    int shootsOnGoal();
    int getStrength();
    int getMotivation();
};
#endif // PLAYER_H
