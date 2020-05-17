#include <iostream>
#include "Airport.h"
#include "Employee.h"
#include "Passenger.h"
#include "fileManagement.h"

using namespace std;

int main()
{
    //create the Airport object
    cout<<"* WELCOME TO THE AIRPORT MANAGEMENT SYSTEM *"<<endl<<endl;
    Airport airport;

    FileManagement fileManager(airport.getfileName());
    string passport="";
    
    //choose the type of user
    int nature;
    do{
        cout<<"Signing in/Signing up as a:"<<endl
            <<" 1. Passenger"<<endl
            <<" 2. Employee"<<endl;
        cin>>nature;
    }while ((nature!=1)&&(nature!=2));
    
    //get the passport number of the user
    cout<<"Please enter your passport number"<<endl;
    cin>>passport;

    //show the menu according to the type of the user
    if(nature==1){
        Passenger *user= new Passenger(airport,passport,fileManager.existant("passenger",passport));
        user->menu(airport);
        delete user; //delete the user
    }
    else if(nature==2){ 
        Employee *user= new Employee(airport,passport,fileManager.existant("employee",passport));
        user->menu(airport);
        delete user; //delete the user
    }

    return 0;
}