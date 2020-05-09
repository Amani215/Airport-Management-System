#pragma once

#include <string>
#include "Airport.h"

class Person{
  protected:
    int id;          //id of the person
    string name;        //name of the person
    int age;            //age of the person
    string nationality; //nationality of the Person
    string passport;    //number of the passport
  public:
    //CONSTRUCTORS & DESTRUCTORS

    //Constructor
    Person(Airport airport);
    Person(int id, string filename);
    //Destructor
    ~Person();
    
    //FUNCTIONS FOR SHOWING DATA

    //print the data of the Person
    virtual void printData()const =0;//a person has to be a passenger or an employee (pure virtual)
    
    //FUNCTIONS FOR CHANGING DATA

    //change the data 
    void changeData();

    //OTHER FUNCTIONS

    //returns true if the person doesn't exist in the database
    bool newPerson(Airport airport) const;
    //returns a new id that doesn't exist in the database
    int getID(Airport airport);//should be virtual too so that passenger gets id with p and employee with e at the beginning
    //returns the Person with the id from the airport
    void getPerson(Airport airport,int id);
};

//************************************************************************************
//                                      ISSUES
//************************************************************************************
//*cannot read strings with spaces
//*change the data of a person in general?

