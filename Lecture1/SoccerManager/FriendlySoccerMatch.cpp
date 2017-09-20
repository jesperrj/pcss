#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "FriendlySoccerMatch.h"

//constructor
FriendlySoccerMatch::FriendlySoccerMatch()
{
    nameHomeTeam="A";
    nameGuestTeam="B";
    pointsHome=0;
    pointsGuest=0;
    printToFile=false;
}
//~FriendlySoccerMatch(){}
//get set function
string FriendlySoccerMatch::getHomeTeam()
{
    return nameHomeTeam;
}
string FriendlySoccerMatch::getGuestTeam()
{
    return nameGuestTeam;
}
int FriendlySoccerMatch::getHomePoints()
{
    return pointsHome;
}
int FriendlySoccerMatch::getGuestPoints()
{
    return pointsGuest;
}

string FriendlySoccerMatch::getResultText()
{
    stringstream sstm;
    sstm<<"The friendly game ends with		\n\n"<<nameHomeTeam<<" - "<<nameGuestTeam<<" "<<pointsHome<<":"<<pointsGuest<<".";
    return sstm.str();
}

void FriendlySoccerMatch::setPrint(bool f)
{
    printToFile=f;
}

// start game function
void FriendlySoccerMatch::startGame(Team t1, Team t2)
{
    //inits
    nameHomeTeam=t1.getName();
    nameGuestTeam=t2.getName();
    pointsHome=0;
    pointsGuest=0;

    ofstream out_stream;

    //make ready for game
    bool gameRuns=true;
    int gameDuration=90+rand()%5;
    int time=1;
    int nextAction;

    if(printToFile)
    {
        remove("test.txt");
    }

    // start game
    while(gameRuns)
    {
        nextAction=rand()%15+1;
        if((time+nextAction>gameDuration)||(time>gameDuration))
        {
            gameRuns=false;
            break;
        }
        //new action
        time=time+nextAction;

        //influence of motivation on strength
        float strength1=t1.getStrength()/2.0f+((t1.getStrength()/2.0f)*(t1.getMotivation()/10.0f));
        float strength2=t2.getStrength()/2.0f+((t2.getStrength()/2.0f)*(t2.getMotivation()/10.0f));
        //influence of trainer on strength
        int deviation=rand()%2;
        if(strength1>t1.getCoach().getExperience())
        {
            deviation=-deviation;
        }
        strength1=max(1,min(10,(int)strength1+deviation));
        deviation=rand()%2;
        if(strength2>t2.getCoach().getExperience())
        {
            deviation=-deviation;
        }
        strength2=max(1,min(10,(int)strength2+deviation));

        //randomly choose player for shooting
        int shooter=rand()%10;
        if((rand()%((int)(strength1+strength2))-strength1)<=0)
        {
            Player p=t1.getPlayer(shooter);
            Keeper k=t2.getKeeper();
            int shot=p.shootsOnGoal();
            //check if shot is saved
            bool goal=!k.saveShot(shot);

            if(!printToFile){
                cout<<"\n"<<time<<".Minute: \n";
                cout<<" Chance for "<<t1.getName()<<" ...\n";
                cout<<" "<<p.getName()<<" shoots\n";
            }else
            {
                out_stream.open("test.txt", ios::app);
                out_stream<<"\n"<<time<<".Minute: \n";
                out_stream<<" Chance for "<<t1.getName()<<" ...\n";
                out_stream<<" "<<p.getName()<<" shoots\n";
                out_stream.close();
            }

            if(goal)
            {
                pointsHome++;
                t1.addGoal(shooter);
                if(!printToFile){
                    cout<<" Goal!!! "<<pointsHome<<":"<<pointsGuest;
                    cout<<" "<<p.getName()<<"("<<t1.getPlayer(shooter).getGoals()<<")\n";
                }else
                {
                    out_stream.open("test.txt", ios::app);
                    out_stream<<" Goal!!! "<<pointsHome<<":"<<pointsGuest;
                    out_stream<<" "<<p.getName()<<"("<<t1.getPlayer(shooter).getGoals()<<")\n";
                    out_stream.close();
                }
            } else
            {
                if(!printToFile){
                    cout<<" "<<t2.getKeeper().getName()<<" saves brilliantly.\n";
                }else
                {
                    out_stream.open("test.txt", ios::app);
                    out_stream<<" "<<t2.getKeeper().getName()<<" saves brilliantly.\n";
                    out_stream.close();
                }
            }
        } else
        {
            Player p = t2.getPlayer(shooter);
            Keeper k = t1.getKeeper();
            int shot=p.shootsOnGoal();
            bool goal=!k.saveShot(shot);
            if(!printToFile){
                cout<<"\n"<<time<<".Minute: \n";
                cout<<" Chance for "<<t2.getName()<<" ...\n";
                cout<<" "<<p.getName()<<" shoots\n";
            }else
            {
                out_stream.open("test.txt", ios::app);
                out_stream<<"\n"<<time<<".Minute: \n";
                out_stream<<" Chance for "<<t2.getName()<<" ...\n";
                out_stream<<" "<<p.getName()<<" shoots\n";
                out_stream.close();
            }
            if (goal)
            {
                pointsGuest++;
                t2.addGoal(shooter);
                if(!printToFile){
                    cout<<" Goal!!! "<<pointsHome<<":"<<pointsGuest;
                    cout<<" "<<p.getName()<<"("<<t2.getPlayer(shooter).getGoals()<<")\n";
                }else
                {
                    out_stream.open("test.txt", ios::app);
                    out_stream<<" Goal!!! "<<pointsHome<<":"<<pointsGuest;
                    out_stream<<" "<<p.getName()<<"("<<t2.getPlayer(shooter).getGoals()<<")\n";
                    out_stream.close();
                }
            } else
            {
                if(!printToFile){
                    cout<<" "<<t1.getKeeper().getName()<<" saves brilliantly.\n";
                }else
                {
                    out_stream.open("test.txt", ios::app);
                    out_stream<<" "<<t1.getKeeper().getName()<<" saves brilliantly.\n";
                    out_stream.close();
                }
            }
        }
    }

}

