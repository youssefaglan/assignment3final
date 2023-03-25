//
//  mechanic.hpp
//  youssef
//
//  Created by Malak Abdelhalim on 26/03/2023.
//

#include "person.hpp"
#include <iostream>
#include <string>

using namespace std;

#ifndef Mechanic_hpp
#define Mechanic_hpp

class Mechanic: public Person
{
private:

    int AppCounter; //the number of appointments a Mechanic has

    Appointment app[48]; //Assuming that there is a time slot every 30 mins of the day
public:
    Mechanic(string,int); //constructor that makes entering the name and age of a Mechanic more readable and easier in the main, assumed to be the age plus 1

    Mechanic(); //Default constructor

    bool Availability(int h, int m);// Fits the hours and minutes into one of the 48 slots available in the day and checks for its availability (Availability == IsAvailable)

    void setAppointment(int h, int m);//fills the appointments slot for a selected hour and minute

    void getAppointments(Appointment A[]);//gets all the appointments slotted and puts them in A[]

    void print(); // provides an implementation for the pure virtual function
};

#endif /* Mechanic_hpp */
