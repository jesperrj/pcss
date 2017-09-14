#ifndef FRIENDLYMATCH_H
#define FRIENDLYMATCH_H

using namespace std;

class FriendlyMatch
{
public:
    //virtual ~FriendlyMatch(){};
	virtual string getHomeTeam()=0;
	virtual string getGuestTeam()=0;
	virtual int getHomePoints()=0;
	virtual int getGuestPoints()=0;
	virtual string getResultText()=0;
};
#endif // FRIENDLYMATCH_H
