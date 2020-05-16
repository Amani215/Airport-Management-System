#pragma once

#include "Person.h"
#include "Airport.h"

class Employee:public Person{
        double salary;  //salary in forints
    public:
        //CONSTRUCTORS & DESTRUCTORS 

        //Constructor
        Employee(Airport airport,string passport, bool existantPerson);
        //Destructor
        ~Employee(){}
        
        //MENU AND FUNCTIONS RELATED TO THE MENU

        //the employees have more options in their menu than the passengers
        void menu(Airport airport)const;
        //Prints the data of the employee
        virtual void printData()const override;
        //change the data of the employee
        void changeData();
        //change the salary of the employee
        void setSalary();
};