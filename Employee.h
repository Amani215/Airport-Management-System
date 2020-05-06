#pragma once

#include "Person.h"
#include "Airport.h"

class Employee:public Person{
    protected:
        double salary;  //salary in forints
    public:
        //Constructor
        Employee(Airport airport);
        
        //Destructor
        ~Employee(){}
        
        //the employees have more options in their menu
        void menu(Airport airport)const;
        
        virtual void printData()const override;
        
        void changeData(){
            Person::changeData();
        }
};

