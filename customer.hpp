//
//  customer.hpp
//  youssef
//
//  Created by Malak Abdelhalim on 26/03/2023.
//

#include "person.hpp"
#include <iostream>
#include <string>

using namespace std;

#ifndef customer_hpp
#define customer_hpp

class customer: public Person{
private:

    int MechanicID ;//is -1 if not assigned
    Appointment app;

public:

    customer();

    customer(int h, int m, string, int); //constructor which makes entering the name and age of the customer in the main easier

    void setMechanicID(int); //setter which assigns a mechanich to the given customer

    int getMechanicID(); //getter for the mechanic's ID

    bool operator<(const customer &p); //overload logical operators for comparision

    bool operator>(const customer &p);

    bool operator==(const customer &p);

    void setAppointment(int h, int m); // the hours and minutes the customer wants are passed here

    void getAppointment(int &h, int &m); //gets the hour and minutes that the customer want

    void print(); // provides implementation for the pure virtual function
};


#endif /* Customer_hpp */

