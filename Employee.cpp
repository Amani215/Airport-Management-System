#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

//Constructor
Employee::Employee(Airport airport):Person(airport){
    salary=300000;
}
        
//the employees have more options in their menu
void Employee::menu(Airport airport)const{
    string password;
    
    cout<<"Please write the airport password: ";
    cin>>password;
    
    if(airport.checkPassword(password)){
        int option;
        
        do{
           //Menu
           cout<<endl;
           cout<<"1. See my personal data"<<endl;
           cout<<"2. See airport data"<<endl;
           cout<<"3. See flights data"<<endl;
           cout<<"4. Change my personal data"<<endl;
           cout<<"5. Change the airport name"<<endl;
           cout<<"6. Change flight data"<<endl;
           cout<<"7. Change the password"<<endl;
           cout<<"0. Log out."<<endl<<endl;
           
           //read the user's choice
           cin>>option;
           
           //execute the user's choice
           switch(option){
               case 1:
                    printData();
                    break;
               case 2:
                    airport.showAirportDataPersonnel();
                    break;
               case 3:
                    airport.flightsData();
                    break;
               case 4:
                    //changeData(this);
                    break;
               case 5:
                    airport.setAirportName();
                    break;
               case 6:
                    airport.changeFlightData();
                    break;
               case 7:
                    airport.setPassword();
                    break;
               case 0:
                    cout<<"Thank you, goodbye!"<<endl;
                    break;
               default: //error handling for characters and strings!!
                    cout<<"There's no such option!"<<endl;
                    break;
           }
        }while(option!=0);
    }
    else{
        cout<<"Wrong password!";
    }
    
    return;
}

//OPTION 1
//prints the data of the employee
void Employee::printData()const{
    cout<<"--My Personal Data--"<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Passport number: "<<passport<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Nationality: "<<nationality<<endl;
    cout<<"Salary: "<<salary<<" ft"<<endl;
}

//********************************************************************************************
//                                      REMARKS
//********************************************************************************************
//*the functions for changing data should be friend functions since they shouldn't be available for the passenger class