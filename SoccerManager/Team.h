#ifndef TEAM_H
#define TEAM_H

#include "Coach.h"
#include "Keeper.h"
#include "Player.h"

using namespace std;

class Team
{
private:
    string name;
    Coach coach;
    Keeper keeper;
    Player players[10];
public:
    Team();
    Team(string n, Coach t, Keeper k, Player p[]);

    //functions
    int getStrength();
    int getMotivation();
    string getName();
    Coach getCoach();
    Player getPlayer(int i);
    Keeper getKeeper();
    void displayName();
    void displayCoach();
    void displayPlayer(int playNum);
    void addGoal(int i);
};
#endif // TEAM_H
