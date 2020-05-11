#include <iostream>
#include <string>
#include "Person.h"

using namespace std;
 
//*****************************************
//CONSTRUCTORS & DESTRUCTORS
//*****************************************

//Constructor
Person::Person(Airport airport,string passport, bool existantPerson){
    this->passport=passport;
    if (existantPerson){
        //open file for reading
        ifstream file;
        try{
            file.open(airport.getfileName());
        }
        catch(...){
            cout<<"Could not open file."<<endl;
        }
        //search for person with id
        string str;
        while (getline(file,str)){
            if(airport.getAttributeFromLine(str,1)==passport){
                name=airport.getAttributeFromLine(str,2);
                age=stoi(airport.getAttributeFromLine(str,3));
                nationality=airport.getAttributeFromLine(str,4);
            }
        }
    }
    else{
        cout<<"Please give your full name (without spaces): ";
        cin>>name;//add error handling for space
        cout<<"Please give your age: ";
        cin>>age;//add error handlin for characters
        cout<<"Please specify your nationality: ";
        cin>>nationality;//add error handlin for space
    }
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
