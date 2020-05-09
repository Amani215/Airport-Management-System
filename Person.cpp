#include <iostream>
#include <string>
#include "Person.h"

using namespace std;
 
//*****************************************
//CONSTRUCTORS & DESTRUCTORS
//*****************************************

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

Person::Person(int id,string filename){
    //open file
    //search for id
    //get the attributes
}

//Destructor
Person::~Person(){}

//*****************************************
//FUNCTIONS FOR SHOWING DATA
//*****************************************

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

//*****************************************
//OTHER FUNCTIONS
//*****************************************

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
}

//returns the Person with the id from the airport
void Person::getPerson(Airport airport,int id){
    //open file for reading
    //search for person with id
    //create new person and give it the properties
}