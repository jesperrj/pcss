#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "FriendlySoccerMatch.h"
#include "Person.h"
#include "Coach.h"
#include "Player.h"
#include "Keeper.h"
#include "Team.h"

using namespace std;

// main function
int main(){
    //set random seed
    srand(time(NULL));

    // declare team 1
    Player p1[10];
    p1[0]=Player("K. Dolberg",18,5,8,10);
    p1[1]=Player("J. Veltman",22,7,5,6);
    p1[2]=Player("M. de Ligt",24,9,3,7);
    p1[3]=Player("N. Viergever",30,9,1,8);
    p1[4]=Player("M. Dijks",25,6,4,5);
    p1[5]=Player("D. van de Beek",28,5,4,4);
    p1[6]=Player("L. Schone",32,6,8,3);
    p1[7]=Player("H. Ziyech",27,3,7,6);
    p1[8]=Player("J. Kluivert",19,4,10,9);
    p1[9]=Player("A. Younes",25,5,7,6);
    Keeper k1=Keeper("A. Onana",28,6,4,8,6);
    Coach c1=Coach("M. Keizer",38,4);

    //declare team 2
    Player p2[10];
    p2[0]=Player("P. Onuachu",19,9,7,7);
    p2[1]=Player("R. Nissen",20,3,8,7);
    p2[2]=Player("K. Hansen",28,8,2,5);
    p2[3]=Player("Z. Korcsmar",27,6,4,7);
    p2[4]=Player("M. Dal Hende",29,7,4,6);
    p2[5]=Player("R. Hassan",28,3,7,4);
    p2[6]=Player("J. Drachmann",30,8,5,4);
    p2[7]=Player("T. Sparv",32,10,2,5);
    p2[8]=Player("J. Poulsen",33,4,9,7);
    p2[9]=Player("J. Borring",31,5,6,6);
    Keeper k2=Keeper("J. Hansen",31,7,4,7,7);
    Coach c2=Coach("J. Thorup",45,5);

    Team t1=Team("Ajax FC",c1,k1,p1);
    Team t2=Team("FC Midtjylland",c2,k2,p2);
    FriendlySoccerMatch f1=FriendlySoccerMatch();

    //print match info and results
    cout<<"Team:\n";
    t1.displayName();
    cout<<"\n";

    cout<<"Keeper:\n"<<k1.getName()<<"\n";
    cout<<"Players:\n";
    for(int i=0;i<10;i++)
    {
        t1.displayPlayer(i);
        cout<<"\n";
    }
    cout<<"Coach:\n";
    t1.displayCoach();
    cout<<"\n";

    cout<<"============ vs. ============\n";
    cout<<"Team:\n";
    t2.displayName();
    cout<<"\n";

    cout<<"Keeper:\n"<<k2.getName()<<"\n";
    cout<<"Players:\n";
    for(int i=0;i<10;i++)
    {
        t2.displayPlayer(i);
        cout<<"\n";
    }
    cout<<"Coach:\n";
    t2.displayCoach();
    cout<<"\n";

    // start the game
    f1.startGame(t1,t2);
    cout<<"\n\n"<<f1.getResultText()<<"\n";

    // return from main
    return 0;
}
