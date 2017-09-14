class Person{
private:
    string name;
    int age;
public:
    void setName(string newName){
        name=n;
    }
    string getName(){
        return name;
    }
    void setAge(int a){
        age=a;
    }
    int getAge(){
        return age;
    }
};

int main(){
    Trainer trainer=Trainer();
    trainer.setName("J. Thorup");
    trainer.setAge(47); // better solution??
    trainer.setExperience(6);

    return 0;
}



public:
    // constructor
    Person(string n,int a):
        name(n),
        age(a){};

class Trainer : public Person{
private:
    int experience;
public:
    Trainer(string n, int a, int e):
        Person(n,a),
        experience(e){}
};
public:
    // constructor
    Trainer(string n,int a):
        name(n),
        age(a){};

//
#include <stdlib.h> // contains rng

class Player : public Person
{
private:
    // player features
    int strength; // 1-10
    int shots; // 1-10
    int motivation; // 1-10
    int goals;
public:
    //constructor
    Player(string n,int a,int st, int sh, int mo):
        Person(n,a),
        strength(st),
        shots(sh),
        motivation(mo),
        goals(0){}
};

//
class Player : public Person
{
private:
    // player features
    int strength; // 1-10
    int shots; // 1-10
    int motivation; // 1-10
    int goals;
public:
    //constructor
    Player(string n,int a,int st, int sh, int mo):
        Person(n,a),
        strength(st),
        shots(sh),
        motivation(mo),
        goals(0){}

    // get and set
    // add goal to player
    void addGoal(){
        goals++;
    }

    // output shot quality varied by -1 to +1
    int shootsOnGoal(){
        shots=max(1,min(10,shots+rand()%3-1));
        int ret=max(1,min(10,shots+rand()%3-1));
        return ret;
    }
};

class Keeper : public Player{
private:
    // keeper features
    int reaction;
public:
    // constructor
    Keeper(string n,int a,int st,int sh,int mo,int re):
        Player(n,a,st,sh,mo),
        reaction(re){}

    // functions
    bool saveShot(int shot){
        int r=rand()%3-1;//add +-1 randomness
        int ret=max(1,min(10,reaction+r));

        if(ret>=shot)
        {
            return true; //saved
        }else
        {
            return false; //SCOOOORE
        }
    }
};

// team

class Team{
private:
    // features of a team
    string name;
    Coach coach;
    Keeper keeper;
    Player players[10];
public:
    // constructor
    Team(string n, Coach t, Keeper k, Player p[]):
        name(n),
        coach(t),
        keeper(k){
            for(int i=0;i<10;i++){
                players[i]=p[i];
            }
        }

    // functions
    // returns average strength
    int getStrength(){
        int summ=0;
        for (int i=0;i<10;i++){
            summ+=players[i].getStrength();
        }
        return summ/10;
    }
    // returns average motivation
    int getMotivation(){
        int summ=0;
        for (int i=0;i<10;i++){
            summ+=players[i].getMotivation();
        }
        return summ/10;
    }
};

//interface
class FriendlyMatch{
public:
	virtual string getHomeTeam()=0;
	virtual string getGuestTeam()=0;
	virtual int getHomePoints()=0;
	virtual int getGuestPoints()=0;
	virtual string getResultText()=0;
};

// friendly soccer match
#include <sstream> // contains string concat.
#include <stdlib.h> // contains rng
class FriendlySoccerMatch : public FriendlyMatch{
private:
    string nameHomeTeam;
    string nameGuestTeam;
    int pointsHome;
    int pointsGuest;
public:
    // constructor
    FriendlySoccerMatch():
        pointsHome(0),
        pointsGuest(0){}

    // get set function
    string getHomeTeam(){
        return nameHomeTeam;
    }
    string getGuestTeam(){
        return nameGuestTeam;
    }
    int getHomePoints(){
        return pointsHome;
    }
    int getGuestPoints(){
        return pointsGuest;
    }
    string getResultText(){
        stringstream sstm;
        sstm<<"The friendly game ends with		\n\n"<<nameHomeTeam<<" - "<<nameGuestTeam<<" "<<pointsHome<<":"<<pointsGuest<<".";
        return sstm.str();
    }

    // start game function
    void startGame(Team t1, Team t2){
        nameHomeTeam=t1.getName();
        nameGuestTeam=t2.getName();
        pointsHome=0;
        pointsGuest=0;

        //make ready for game
        bool gameRuns=true;
        int gameDuration=90+rand()%5;
        int time=1;
        int nextAction;

        // start game
        while(gameRuns){
            nextAction=rand()%15+1; //time for next action
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
            if(strength1>t1.getCoach().getExperience()){
                deviation=-deviation;
            }
            strength1=max(1,min(10,(int)strength1+deviation));
            deviation=rand()%2;
            if(strength2>t2.getCoach().getExperience()){
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
                cout<<"\n"<<time<<".Minute: \n";
                cout<<" Chance for "<<t1.getName()<<" ...\n";
                cout<<" "<<p.getName()<<" shoots\n";

                if(goal){
                    pointsHome++;
                    t1.addGoal(shooter);
                    cout<<" Goal!!! "<<pointsHome<<":"<<pointsGuest;
                    cout<<" "<<p.getName()<<"("<<t1.getPlayer(shooter).getGoals()<<")\n";
                } else{
                    cout<<" "<<t2.getKeeper().getName()<<" saves brilliantly.\n";
                }
            } else {
                Player p = t2.getPlayer(shooter);
                Keeper k = t2.getKeeper();
                int shot=p.shootsOnGoal();
                bool goal=!k.saveShot(shot);
                cout<<"\n"<<time<<".Minute: \n";
                cout<<" Chance for "<<t2.getName()<<" ...\n";
                cout<<" "<<p.getName()<<" shoots\n";

                if (goal){
                    pointsGuest++;
                    t2.addGoal(shooter);
                    cout<<" Goal!!! "<<pointsHome<<":"<<pointsGuest;
                    cout<<" "<<p.getName()<<"("<<t2.getPlayer(shooter).getGoals()<<")\n";
                } else{
                    cout<<" "<<t1.getKeeper().getName()<<" saves brilliantly.\n";
                }
            }
        }
    }
};

// main

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
