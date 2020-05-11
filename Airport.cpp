#include <iostream>
#include <fstream>
#include<string> 
#include "Airport.h"
#include "Flight.h"

using namespace std;

//*********************************************
//CONSTRUCTORS & DESTRUCTORS
//*********************************************

//Default constructor
Airport::Airport(){
    
    cout<<"Please give the name of this airport (without spaces)"<<endl;
    cin>>airportName;
    
    cout<<"Please give the location of this airport"<<endl;
    cin>>location;
    
    password="admin";
    
    fileName=airportName+"-"+location+".csv";
}


//*********************************************
//FUNCTIONS FOR SHOWING DATA
//*********************************************

//Shows all the General Data of the Airport (name, location, passengersNum, employeesNum and flightsData)
void Airport::showAirportData() const{
    cout<<"--"<<airportName<<" Airport General Data--"<<endl;
    cout<<"Location: "<<location<<endl;
    cout<<"Number of passengers now: "<< passengersNum()<<endl;
    cout<<"Number of employees now: "<<employeesNum()<<endl;
    cout<<"Flights:"<<endl;
    flightsData();
}

//Shows all the General Data of the Airport and the password
void Airport::showAirportDataPersonnel() const{
    cout<<"--"<<airportName<<" Airport General Data--"<<endl;
    cout<<"Location: "<<location<<endl;
    cout<<"Number of passengers now: "<< passengersNum()<<endl;
    cout<<"Number of employees now: "<<employeesNum()<<endl;
    showPassword();
    cout<<"Flights:"<<endl;
    flightsData();
}

//Shows the password
void Airport::showPassword()const{ cout<<"Password: "<<password<<endl; }

//returns the number of registered passengers in the airport
int Airport::passengersNum() const{
    string str;
    int counter=0;
    //open file for reading
    ifstream file;
    try{
        file.open(fileName);
    }
    catch(...){
        cout<<"There was an error.";
    }
    //count lines of passengers
    while (getline(file,str)){
        if(typeOfObjectInLine(str)=="passenger"){
            counter++;
        }
    }
    //return the number
    return counter;
}

//returns the number of registered employees in the airport
int Airport::employeesNum() const{
    string str;
    int counter=0;
    //open file for reading
    ifstream file;
    try{
        file.open(fileName);
    }
    catch(...){
        cout<<"There was an error.";
    }
    //count lines of passengers
    while (getline(file,str)){
        if(typeOfObjectInLine(str)=="employee"){
            counter++;
        }
    }
    //return the number
    return counter;
}

//Shows a flight according to the given id
void Airport::showFlightData(string flightId) const{
    bool found=false;

    string str;
    //open file and search for id
    ifstream file;
    try{
        file.open(fileName);
    }
    catch(...){
        cout<<"There was an error"<<endl;
    }

    while(getline(file,str)){
        if((this->getAttributeFromLine(str,1)=="flight")&&(this->getAttributeFromLine(str,2)==flightId)){
            Flight flight(flightId,*this);
            flight.showFlightData();
            found=true;
        }
    }
    if(found==false) cout<<"There's no flight with such an id"<<endl;
}

//prints the data of each flight registered in the airport
void Airport::flightsData() const{
    string str;
    //open file for reading
    ifstream file;
    try{
        file.open(fileName);
    }
    catch(...){
        cout<<"There was an error.";
    }
    while (getline(file,str)){
        if(typeOfObjectInLine(str)=="flight"){
            showFlightData(getAttributeFromLine(str,1));
        }
    }
}


//*********************************************
//FUNCTIONS FOR CHANGING DATA
//*********************************************

//Change the password
void Airport::setPassword(){
    cout<<"New password: ";
    cin>>password;
    //Change it in the file
}

//Change the name of the airport***********************************************
void Airport::setAirportName(){
    cout<<"The current name is "<<airportName<<", please set the new one: ";
    cin>>airportName;
    //change the filename and copy the old file in the new one
}

//Change a flight data according to the given id
void Airport::changeFlightData(){
    string input;
    cout<<"Please give the id of the flight: ";
    cin>>input;
    Flight flight(input,*this);
    //change the flight with that id in the file
}


//*********************************************
//OTHER FUNCTIONS
//*********************************************

//returns true if the input is equal to the password
bool Airport::checkPassword(string input)const{
    return (input.compare(password)==0);
}

bool Airport::existantEmployee(string passport)const{
    ifstream file;
    try{
        file.open(fileName);
    }
    catch(...){
        cout<<"Could not open file"<<endl;
    }

    string str;
    while (getline(file, str)){
        if((typeOfObjectInLine(str)=="employee")&&(passport==getAttributeFromLine(str,1))){
            file.close();
            return true;
        }
    }
    return false;
}

bool Airport::existantPassenger(string passport)const{
    ifstream file;
    try{
        file.open(fileName);
    }
    catch(...){
        cout<<"Could not open file"<<endl;
    }

    string str;
    while (getline(file, str)){
        if((typeOfObjectInLine(str)=="passenger")&&(passport==getAttributeFromLine(str,1))){
            file.close();
            return true;
        }
    }
    return false;
}

//returns the type of the object in the line
string Airport::typeOfObjectInLine(string str)const{
    char temp[10]="";
    int i=0;
    while (str[i]!=','){
        temp[i]=str[i];
        i++;
    }
    temp[i]='\0';
    return temp;
}

string Airport::getAttributeFromLine(string str,int orderOfTheAttribute)const{
    char attribute[50];
    int j=0, i=0;
    do{
        while (str[i]!=','){
            i++;
        }
        j++;
        i++;
    }while (j<orderOfTheAttribute);
    j=0;
    while (str[i]!=','){
        attribute[j]=str[i];
        j++;
        i++;
    }
    attribute[j]='\0';
    return attribute;
}