#include "person.hpp"
#include "customer.hpp"
#include "mechanic.hpp"
#include "queue.hpp"
#include "queue.cpp"
#include <iostream>

using namespace std;

//note it is assumed I always must have at most 5 customers and at most 5 mechanics

int main() {
    Mechanic M1("Ahmed",40), M2("Mai",33), M3("Sara",28);

    customer c1(1,00,"Youssef",18), c2(4,00,"Ayman",19), c3(3,30,"Kareem",22), c4(1,00,"Mohammed",30), c5(1,00,"Khaled",20) , carr[5], ctemp;

    int CustomerNum = 5;//Must be equal the number of Customers above to work right


    Queue <customer> q1;
    Queue <Mechanic> q2;

    carr[0] = c1;
    carr[1] = c2;
    carr[2] = c3;
    carr[3] = c4;
    carr[4] = c5;

//enque with the number of mechanic objects
    q2.enqueue(M1);
    q2.enqueue(M2);
    q2.enqueue(M3);


    //bubble sort using overload operators to sort with earliest appoinment
    for(int i1 = 0; i1 < CustomerNum ; i1++)
        for (int j1 = 0; j1 < CustomerNum; j1++)
        {
            if (carr[i1] > carr[j1])
            {
                ctemp = carr[j1];
                carr[j1] = carr[i1];
                carr[i1] = ctemp;
            }
        }

    q1.enqueue(carr[0]);
    q1.enqueue(carr[1]);
    q1.enqueue(carr[2]);
    q1.enqueue(carr[3]);
    q1.enqueue(carr[4]);



    customer arrC[5];
    Mechanic arrM[5];

    int i = 0, j = 0; //i for mechanic j for customer

    while(q1.getCount() >= 0){//loop on customer

        if (!q1.getCount())
            break;

        Mechanic tempM = q2.dequeue();

        customer tempC = q1.dequeue();

        arrC[j] = tempC;

        arrM[i] = tempM;

        int h,m;

        tempC.getAppointment(h, m);
        while(q2.getCount() > 0 && !(tempM.Availability(h,m))){ //if a Mechanic isn't available it checks the other Mechanics for availablity at the given slot

            i++;

            tempM = q2.dequeue();

            arrM[i] = tempM;
        }
        if(q2.getCount() <= 0){//no Mechanic is available at the given time the Customer is thus discarded
            cout << "No appointment found for customer. " << arrC[j].getName() <<endl;
        }
        else{

            //Mechanic is available at the given time
            arrM[i].setAppointment(h, m);//reserve this avialable time slot for the Mechanic

            arrC[j].setMechanicID(arrM[i].getID());//gets the ID of the Mechanic and assigns it to the Customer's Mechanic ID in customers class


            if(m)
                cout << "Appointment scheduled for Customer " << arrC[j].getName() << " at: " << h << ":" << m << " with Mr. " << arrM[i].getName() << " with ID: " << arrC[j].getMechanicID() << endl;

            else //to print the extra 0 if m is 0
                cout << "Appointment scheduled for Customer " << arrC[j].getName() << " at: " << h << ":" << m<<"0" << " with Mr. " << arrM[i].getName() <<  " with ID: " << arrC[j].getMechanicID() << endl;

        }
        while (i >= 0) {//to return Mechanic to the queue for next customer to check their availability
            q2.enqueue(arrM[i]);
            i--;
        }

        if (i == -1)
            i = 0;
        j++;

    }



    return 0;
}
