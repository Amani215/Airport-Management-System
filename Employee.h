#pragma once

#include "Person.h"
#include "Airport.h"

class Employee:public Person{
    //protected: 
        double salary;  //salary in forints
    public:
        //CONSTRUCTORS & DESTRUCTORS 

        //Constructor
        //Employee(Airport airport);
        Employee(Airport airport,string passport, bool existantPerson);
        //Destructor
        ~Employee(){}
        
        //MENU AND FUNCTIONS RELATED TO THE MENU

        //the employees have more options in their menu
        void menu(Airport airport)const;
        //OPTION 1: show the data of the employee
        virtual void printData()const override;
        //OPTION 4: 
        //change the data of the employee
        void changeData();
        //change the salary of the employee
        void setSalary();
};

