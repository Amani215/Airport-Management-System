#pragma once

#include <string>
#include "Airport.h"

class Person{ 
  protected:
    string name;        //name of the person
    int age;            //age of the person
    string nationality; //nationality of the Person
    string passport;    //number of the passport
  public:
    //CONSTRUCTORS & DESTRUCTORS

    //Constructor
    Person(Airport airport, string passport, bool existantPerson);
    //Destructor
    ~Person();
    
    //FUNCTIONS FOR SHOWING DATA

    //print the data of the Person
    virtual void printData()const =0;//a person has to be a passenger or an employee (pure virtual)
    
    //FUNCTIONS FOR CHANGING DATA

    //change the data 
    void changeData();

    //OTHER FUNCTIONS
    
    //returns the name of the person
    string getName()const;
    //returns the passport of the person
    string getPassport()const;
};