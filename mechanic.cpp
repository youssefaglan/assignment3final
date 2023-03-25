//
//  mechanic.cpp
//  youssef
//
//  Created by Malak Abdelhalim on 26/03/2023.
//

#include "mechanic.hpp"
#include <array>
Mechanic::Mechanic(string s,int Age){

    setName(s);

    AppCounter = 0;

    setAge(Age);

    setID(Age+1);
}
Mechanic::Mechanic() {

    AppCounter = 0;

}
bool Mechanic::Availability(int h, int m){

    int TimeSlot = h % 24 + m % 29;

    if (app[TimeSlot].hours == -1){
        return true;
    }
    else{
        return false;
    }

}
void Mechanic::setAppointment(int h, int m){

    if (h >= 0 && h < 24 && (m == 0 || m == 30 )){
        if (Availability(h, m)){
        int TimeSlot = h % 24 + m % 29;
            AppCounter++;
            app[TimeSlot].hours = h;
            app[TimeSlot].mins = m;
        }
    }

    else{
        cout << "Invalid appointment details... Please try again using a valid time" << endl;
    }
}

void Mechanic::getAppointments(Person::Appointment A[]){
    A = app;
}
void Mechanic::print()
{
    cout << "Name: " << getName() << endl;

    cout << "Age: " << getAge() << endl;

    cout << "ID: " << getID() << endl;
};
