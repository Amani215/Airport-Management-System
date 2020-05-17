#include <iostream>
#include <string>
#include "Person.h"
#include "fileManagement.h"

using namespace std;
 
//*****************************************
//CONSTRUCTORS & DESTRUCTORS
//*****************************************

//Constructor
Person::Person(Airport airport,string passport, bool existantPerson){
    //set passport to passport
    this->passport=passport;
    //if the person exists in the database
    if (existantPerson){
        FileManagement fileManager(airport.getfileName());
        //open file for reading
        ifstream file;
        try{file.open(airport.getfileName());}
        catch(...){
            cout<<"Could not open file!"<<endl;
            throw exception();
        }
        //search for person with id
        string str;
        while (getline(file,str)){
            //when found copy the attributes to the new Person object
            if(fileManager.getAttributeFromLine(str,1)==passport){
                name=fileManager.getAttributeFromLine(str,2);
                age=stoi(fileManager.getAttributeFromLine(str,3));
                nationality=fileManager.getAttributeFromLine(str,4);
                break;
            }
        }
        //close the file
        file.close();
    }
    //if the person does not exist in the database
    else{
        //read the name
        cout<<"Please give your full name (without spaces): ";
        cin>>name;
        //read the age
        cout<<"Please give your age: ";
        cin>>age;
        //read the nationality
        cout<<"Please specify your nationality (without spaces): ";
        cin>>nationality;
    }
}

//Destructor
Person::~Person(){}

//*****************************************
//FUNCTIONS FOR CHANGING DATA
//*****************************************

//change the data of the person
void Person::changeData(){
    string input;
    cout<<"--Changing the data--"<<endl;
    cout<<"If you don't want to change a parameter please press 0 and enter"<<endl<<endl;
    
    //changing the name (if 0 don't change)
    cout<<"Name: ";
    cin>>input;
    if (input!="0") name=input; 
    //change the age (if 0 don't change)
    cout<<"Age: ";
    cin>>input;
    if(input!="0") age=stoi(input);
    //change the nationality (if 0 don't change)
    cout<<"Nationality: ";
    cin>>input;
    if(input!="0") nationality=input;
    //read the passport (if 0 don't change)
    cout<<"Passport: ";
    cin>>input;
    if(input!="0") passport=input;
}

//*****************************************
//OTHER FUNCTIONS
//*****************************************

string Person::getName()const{ return name;}
string Person::getPassport()const{return passport;}