#include <iostream>
#include <string>
#include "Employee.h"
#include "Person.h"

using namespace std;

//**********************************************
//CONSTRUCTORS & DESTRUCTORS
//**********************************************

//Constructor
Employee::Employee(Airport airport):Person(airport){
    salary=300000;
}

Employee::Employee(int id, string filename):Person(id,filename){
     //open file
     //search for id
     //assign salary
}

//**********************************************
//MENU AND FUNCTIONS RELATED TO THE MENU
//**********************************************

//the employees have more options in their menu
void Employee::menu(Airport airport)const{
    Employee employee(id, airport.getfileName());
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
               case 1://Done
                    employee.printData();
                    break;
               case 2://Done
                    airport.showAirportDataPersonnel();
                    break;
               case 3:
                    airport.flightsData();
                    break;
               case 4://Done
                    employee.changeData();
                    employee.setSalary();
                    break;
               case 5://Done (file handling)
                    airport.setAirportName();
                    break;
               case 6:
                    airport.changeFlightData();
                    break;
               case 7://Done (file handling)
                    airport.setPassword();
                    break;
               case 0://Done
                    cout<<"Thank you, goodbye!"<<endl;
                    break;
               default:
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

//OPTION 4: 
//change the data
void Employee::changeData(){ Person::changeData(); }
//change the salary
void Employee::setSalary(){
     double input;
     cout<<"Salary: ";
     cin>>input;
     if (input!=0) salary= input;
}

//********************************************************************************************
//                                      REMARKS
//********************************************************************************************
//*the functions for changing data should be friend functions since they shouldn't be available for the passenger class
//Employee employee(id, airport.getfileName());
//option 3,6

//Done:
//*Option 1, 2, 4,5,7