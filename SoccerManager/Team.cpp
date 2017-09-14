#include <iostream>
#include "Team.h"

Team::Team():
    name("Football FC"),
    coach(Coach()),
    keeper(Keeper())
    {
        Player p[10];
        for(int i=0;i<10;i++)
            {
            players[i]=p[i];
            }
    }
Team::Team(string n, Coach t, Keeper k, Player p[]):
    name(n),
    coach(t),
    keeper(k)
    {
        for(int i=0;i<10;i++)
        {
            players[i]=p[i];
        }
    }

//functions
int Team::getStrength()
{
    int summ=0;
    for (int i=0;i<10;i++)
    {
        summ+=players[i].getStrength();
    }
    return summ/10;
}
int Team::getMotivation()
{
    int summ=0;
    for (int i=0;i<10;i++)
    {
        summ+=players[i].getMotivation();
    }
    return summ/10;
}
string Team::getName()
{
    return name;
}

Coach Team::getCoach()
{
    return coach;
}
Player Team::getPlayer(int i)
{
    return players[i];
}
Keeper Team::getKeeper()
{
    return keeper;
}

void Team::displayName()
{
    cout<<name;
}
void Team::displayCoach()
{
    cout<<coach.getName();
}
void Team::displayPlayer(int playNum)
{
    cout<<players[playNum].getName();
    //return "test";
}
void Team::addGoal(int i)
{
    players[i].addGoal();
}
