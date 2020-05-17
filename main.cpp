#include <iostream>
#include "Airport.h"
#include "Employee.h"
#include "Passenger.h"
#include "fileManagement.h"

using namespace std;

int main()
{
    cout<<"* WELCOME TO THE AIRPORT MANAGEMENT SYSTEM *"<<endl<<endl;
    Airport airport;
    FileManagement fileManager(airport.getfileName());
    string passport="";
    
    int nature;
    do{
        cout<<"Signing in/Signing up as a:"<<endl
            <<" 1. Passenger"<<endl
            <<" 2. Employee"<<endl;
        cin>>nature;
    }while ((nature!=0)&&(nature!=1));
    
    cout<<"Please enter your passport number"<<endl;
    cin>>passport;

    if(nature==1){
        Passenger user(airport,passport,fileManager.existant("passenger",passport));
        user.menu(airport);
    }
    else if(nature==2){ 
        Employee user(airport,passport,fileManager.existant("employee",passport));
        user.menu(airport);
    }
    else
    {
        cout<<"Sorry there was no such option..."<<endl;
    }
    
    return 0;
}

//Maybe add the dynamic memory handling here