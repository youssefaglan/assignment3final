
#include "customer.hpp"

customer::customer() {

    MechanicID = -1;
}

customer::customer(int h, int m, string s, int Age) {
    setName(s);
    setAppointment(h, m);
    setAge(Age);
    MechanicID = -1;


}
void customer::setMechanicID(int I) {

    MechanicID = I;
}
int customer::getMechanicID() {

    return MechanicID;
}
bool customer::operator<(const customer &c) {

    if (app.hours < c.app.hours) {
        return true;
    }
    else if ((app.hours == c.app.hours) && (app.mins < c.app.mins)){
        return true;
    }
    else{
        return false;
    }
}


bool customer::operator>(const customer &c) {
    if (app.hours > c.app.hours){
        return true;
    }
    else if ((app.hours == c.app.hours) && (app.mins > c.app.mins)){
        return true;
    }
    else{
        return false;
    }
}

bool customer::operator==(const customer &c){
    if((app.hours == c.app.hours) && (app.mins == c.app.mins)){
        return true;
    }
    else{
        return false;
    }
}
void customer::setAppointment(int h, int m){
    if (h >= 0 && h < 24 && (m == 0 || m == 30 )){ // Assuming that there are appointments every 30 mins
        app.hours = h;
        app.mins = m;
    }

    else{
        cout << "Invalid appointment details... Please try again using a valid time" << endl;
    }
}
void customer::getAppointment(int &h, int &m) {
    if (app.hours == -1 && app.mins == -1) {
        cout << "No scheduled appointment" << endl;
    }
    else{
        h = app.hours;
        m = app.mins;
    }
}
void customer::print()
{
    cout << "Name: " << getName() << endl;

    cout << "Age: " << getAge() << endl;

    cout << "Mechanic's ID: " << getMechanicID() << endl;

    cout << "Appointment Time: " << app.hours << ":" << app.mins << endl;
};
