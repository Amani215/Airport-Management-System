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
     //if the given passport exists in the database the copy the attributes from the file
     if(existantPerson){
          FileManagement fileManager(airport.getfileName());

          //open the airport file
          ifstream file;
          try{file.open(airport.getfileName());}
          catch(...){
               cout<<"Could not open file!"<<endl;
               throw exception();
          }

          //search for employee with given passport and assign the attributes
          string str;
          while (getline(file,str))
          {    
               //when the employee is found copy the attributes
               if((fileManager.typeOfObjectInLine(str)=="employee")&&(fileManager.getAttributeFromLine(str,1)==passport)){
                    passport=fileManager.getAttributeFromLine(str,1);
                    name=fileManager.getAttributeFromLine(str,2);
                    age=stoi(fileManager.getAttributeFromLine(str,3));
                    nationality=fileManager.getAttributeFromLine(str,4);
                    salary=stod(fileManager.getAttributeFromLine(str,5));
               }   
          }
          //close the airport file
          file.close();
     }
     //if the given passport is new then create a new employee in the database
     else{
          salary=300000;
          //add the attributes to the airport file
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
    //allocate memory for a temporary employee
    Employee* employee= new Employee(airport,passport,true);
    if(employee->passport!=passport) return;//if an error happens

    //ask for password
    string password;
    cout<<"Please write the airport password: ";
    cin>>password;
    
    //if password is correct proceed
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
           cout<<"6. Add/Change flight data"<<endl;
           cout<<"7. Change the password"<<endl;
           cout<<"0. Log out."<<endl<<endl;
           
           //read the user's choice
           cin>>option;
           
           //execute the user's choice
           switch(option){
               case 1://Done
                    cout<<"--My Personal Data--"<<endl;
                    employee->printData();
                    break;
               case 2://Done
                    airport.showAirportData();
                    airport.showPassword();
                    break;
               case 3:
                    airport.flightsData();
                    break;
               case 4://Done
                    employee->changeData(airport);
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
    
    delete employee;
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
     //change attributes inherited from the base class Person
     Person::changeData(); 
     //change the salary
     setSalary();
     //set the changes in the airport file
     string attributes="employee,"+passport+","+name+","+to_string(age)+","+nationality+","+to_string(salary)+",";
     fileManager.modify(attributes,fileManager.lineOfObject("employee",passport));
}

//change the salary
void Employee::setSalary(){
     double input;
     cout<<"Salary: ";
     cin>>input;
     //if 0 is typed then the employee chose not to change it
     if (input!=0) salary= input;
}