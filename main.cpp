#include <iostream>
#include "Airport.h"
#include "Employee.h"
#include "Passenger.h"

using namespace std;

int main()
{
    cout<<"* WELCOME TO THE AIRPORT MANAGEMENT SYSTEM *"<<endl<<endl;
    Airport airport;
    
    int nature;
    do{
        cout<<"If you're a passenger please press 1, if you're an employee please press 0"<<endl;
        cin>>nature;
    }while ((nature!=0)&&(nature!=1));
    
    if(nature==0){
        Employee user(airport);
        user.menu(airport);
    }
    else{
        Passenger user(airport);
        user.menu(airport);
    }

    return 0;
}
