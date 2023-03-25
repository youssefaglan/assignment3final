//
//  person.hpp
//  youssef
//
//  Created by Malak Abdelhalim on 26/03/2023.
//

#ifndef person_hpp
#define person_hpp

#include <iostream>

using namespace std;

#ifndef Person_hpp

#define Person_hpp

class Person
{
private:

    string Name;
    int Age, ID;

public:
    Person();

    void setName(string);//sets the name of the person either a Mechanic or Customer

    void setID(int);//sets the Mechanic's ID

    void setAge(int);//sets the age of the person either Customer or Mechanic

    string getName();//gets the name of either the Customer or Mechanic

    int getID();//gets the name of either the Customer or Mechanic

    int getAge();//gets the name of either the Customer or Mechanic

    void printInfo();//prints the details of the person

    virtual void print() = 0; // pure virtual function

    struct Appointment{

        int hours = -1, mins = -1;//-1 means free

    };
};

#endif /* Person_hpp */

#endif /* person_hpp */
