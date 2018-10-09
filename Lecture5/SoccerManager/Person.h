#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    // constructor
    Person(string n,int a);
    // get set functions
    void setName(string newName);
    string getName();
};
#endif // PERSON_H
