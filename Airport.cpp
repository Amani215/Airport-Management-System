#include <iostream>
#include<string>
#include "Airport.h"

using namespace std;

//Default constructor
Airport::Airport(){
    
    cout<<"Please give the name of this airport (without spaces)"<<endl;
    cin>>airportName;
    
    cout<<"Please give the location of this airport"<<endl;
    cin>>location;
    
    password="admin";
    
    fileName=airportName+".txt";
}

//Destructor
Airport::~Airport(){}

//returns the number of registered passengers in the airport
int Airport::passengersNum() const{
    //open file for reading
    //count ids that begin with p
    //return the number
    return 0;
}

//returns the number of registered employees in the airport
int Airport::employeesNum() const{
    //open file for reading
    //count ids that begin with e
    //return the number
    return 0;
}

//prints the data of each flight registered in the airport
void Airport::flightsData() const{
    
}

//returns true if the input is equal to the password
bool Airport::checkPassword(string input)const{
    return (input.compare(password)==0);
}

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
void Airport::showPassword()const{
    cout<<"Password: "<<password<<endl;
}

void Airport::setAirportName(){
    cout<<"The current name is "<<airportName<<", please set the new one: ";
    cin>>airportName;
}

void Airport::changeFlightData(){
    string input;
    cout<<"Please give the id of the flight: ";
    cin>>input;
    //create object Flight with id
    //change the flight with that id in the file
    //Flight flight(id);
}

void Airport::setPassword(){
    cout<<"New password: ";
    cin>>password;
}
        