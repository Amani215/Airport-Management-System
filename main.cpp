#include <iostream>
#include "Airport.h"
#include "Employee.h"
#include "Passenger.h"

using namespace std;

int main()
{
    cout<<"* WELCOME TO THE AIRPORT MANAGEMENT SYSTEM *"<<endl<<endl;
    Airport airport;
    string passport="";
    
    int nature;
    do{
        cout<<"If you're a passenger please press 1, if you're an employee please press 0"<<endl;
        cin>>nature;
    }while ((nature!=0)&&(nature!=1));
    
    cout<<"Please enter your passport number"<<endl;
    cin>>passport;

    if(nature==0){
        Employee user(airport,passport,airport.existantEmployee(passport));
        user.menu(airport);
    }
    else{ 
        Passenger user(airport,passport,airport.existantPassenger(passport));
        user.menu(airport);
    }

    return 0;
}
