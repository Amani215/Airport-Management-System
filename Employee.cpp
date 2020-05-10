#include <iostream>
#include <fstream>
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
    ofstream file;
    try{
         file.open(airport.getfileName());
    }
    catch(...){
         cout<<"There was an error.";
    }
    string str="employee;"+to_string(id)+";"+passport+";"+name+";"+to_string(age)+";"+nationality+";"+to_string(salary);
    file<<str<<endl;

    file.close();
}

Employee::Employee(int id, Airport airport):Person(id){
this->id=-1;

    string str;
    //open file
    ifstream file;
    try{
        file.open(airport.getfileName());
    }
    catch(...){
        cout<<"there was an error";
    }
    //search for id and assign the attributes
    while (getline(file,str))
    {
        if((airport.typeOfObjectInLine(str)=="employee")&&(stoi(airport.getAttributeFromLine(str,1))==id)){
            this->id=id;
            passport=airport.getAttributeFromLine(str,2);
            name=airport.getAttributeFromLine(str,3);
            age=stoi(airport.getAttributeFromLine(str,4));
            nationality=airport.getAttributeFromLine(str,5);
            salary=stod(airport.getAttributeFromLine(str,6));
        }   
    }

    if(this->id==-1) cout<<"The provided id does not exist"<<endl;

    file.close();
}

//**********************************************
//MENU AND FUNCTIONS RELATED TO THE MENU
//**********************************************

//the employees have more options in their menu
void Employee::menu(Airport airport)const{
    Employee employee(id, airport);
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