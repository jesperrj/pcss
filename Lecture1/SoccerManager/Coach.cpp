#include "Coach.h"

//using namespace std;

Coach::Coach():
    Person("J. Doe",99),
    experience(1){}
Coach::Coach(string n,int a,int e):
    Person(n,a),
    experience(e){}

//function
int Coach::getExperience()
{
    return experience;
}
