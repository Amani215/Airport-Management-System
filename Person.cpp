#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

//Constructor
Person::Person(Airport airport){
    cout<<"Please give your passport number: ";
    cin>>passport;
    if(newPerson(airport)){
        cout<<"Please give your full name (without spaces): ";
        cin>>name;//add error handling for space
        cout<<"Please give your age: ";
        cin>>age;//add error handlin for characters
        cout<<"Please specify your nationality: ";
        cin>>nationality;//add error handlin for space
        id=getID(airport);
        cout<<"Your ID is: "<<id<<endl;
    }
    else{
        this->getPerson(airport,id);
    }
}

//Destructor
Person::~Person(){}

//print the data of the Person
// virtual void print()const =0;//a person has to be a passenger or a pilot (pure virtual)

//returns true if the person doesn't exist in the database
bool Person::newPerson(Airport airport) const{
    //open file (airport.filename) for reading
    //search for passport in the file
    //return true if passport is not found
    //return false if passport is found
}

//returns a new id that doesn't exist in the database
int Person::getID(Airport airport) {
    //open file and return the number of the new line
    return 1;
}//should be virtual too so that passenger gets id with p and employee with e at the beginning

//returns the Person with the id from the airport
void Person::getPerson(Airport airport,int id){
    //open file for reading
    //search for person with id
    //create new person and give it the properties
}

//change the data
void Person::changeData(){
    string input;
    cout<<"--Changing the data--"<<endl;
    cout<<"If you don't want to change a parameter please press 0 and enter"<<endl<<endl;
    
    cout<<"Name: ";
    cin>>input;
    if (input!="0") name=input;
    
    cout<<"Age: ";
    cin>>input;
    if(input!="0") age=stoi(input);
    
    cout<<"Nationality: ";
    cin>>input;
    if(input!="0") nationality=input;
    
    cout<<"Passport: ";
    cin>>input;
    if(input!="0") passport=input;
}