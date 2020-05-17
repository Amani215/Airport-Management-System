#include <iostream>
#include <fstream>
#include <string>
#include "Employee.h"
#include "Person.h"
#include "fileManagement.h"

using namespace std;

//**********************************************
//CONSTRUCTORS & DESTRUCTORS
//**********************************************

//Constructor
Employee::Employee(Airport airport,string passport, bool existantPerson)
     :Person(airport,passport, existantPerson)
{
     if(existantPerson){
          FileManagement fileManager(airport.getfileName());
          string str;

          //open file
          ifstream file;
          try{file.open(airport.getfileName());}
          catch(...){
               cout<<"Could not open file!"<<endl;
               throw exception();
          }

          //search for id and assign the attributes
          while (getline(file,str))
          {
               if((fileManager.typeOfObjectInLine(str)=="employee")&&(fileManager.getAttributeFromLine(str,1)==passport)){
                    passport=fileManager.getAttributeFromLine(str,1);
                    name=fileManager.getAttributeFromLine(str,2);
                    age=stoi(fileManager.getAttributeFromLine(str,3));
                    nationality=fileManager.getAttributeFromLine(str,4);
                    salary=stod(fileManager.getAttributeFromLine(str,5));
               }   
          }

          file.close();
     }
     else{
          salary=300000;
          FileManagement file(airport.getfileName());
          string str="employee,"+passport+","+name+","+to_string(age)+","+nationality+","+to_string(salary)+",";
          file.write(str);
     }
}

//**********************************************
//MENU AND FUNCTIONS RELATED TO THE MENU
//**********************************************

//the employees have more options in their menu than the passengers
void Employee::menu(Airport airport)const{
    Employee employee(airport,passport,true);
    if(employee.passport!=passport) return;//if an error happens

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
                    cout<<"--My Personal Data--"<<endl;
                    employee.printData();
                    break;
               case 2://Done
                    airport.showAirportDataPersonnel();
                    break;
               case 3:
                    airport.flightsData();
                    break;
               case 4://Done
                    employee.changeData(airport);
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
    cout<<"    Passport number: "<<passport<<endl;
    cout<<"    Name: "<<name<<endl;
    cout<<"    Age: "<<age<<endl;
    cout<<"    Nationality: "<<nationality<<endl;
    cout<<"    Salary: "<<salary<<" ft"<<endl;
}

//OPTION 4: 
//change the data
void Employee::changeData(Airport airport){ 
     FileManagement fileManager(airport.getfileName());
     Person::changeData(); 
     setSalary();
     string attributes="employee,"+passport+","+name+","+to_string(age)+","+nationality+","+to_string(salary)+",";
     fileManager.modify(attributes,fileManager.lineOfObject(airport,"employee",passport));
}
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
//option 3,6