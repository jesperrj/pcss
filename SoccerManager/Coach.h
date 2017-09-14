#ifndef COACH_H
#define COACH_H

#include "Person.h"

class Coach : public Person
{
private:
    int experience;
public:
    Coach();
    Coach(string n,int a,int e);

    //function
    int getExperience();

};
#endif // COACH_H
