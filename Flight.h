#pragma once

#include<iostream>
#include<string>
#include <time.h>
#include "Airport.h"
#include "Employee.h"

using namespace std;

class Flight{
    string flightNum;       //flight ID 
    string destination;     //destination of the flight
    string timeOfTakingOff; //time of taking off of the plane
    double price;           //price in forints
    string airlineCompany;  //name of the airline company
    int numberOfSeats;      //number of seats of the airplane
    string pilotPassport;   //pilot for the flight
  public:
    //CONSTRUCTORS & DESTRUCTORS

    //Default constructor
    Flight(Airport airport,string flightNum);
    //Destructor
    ~Flight(){}
    
    //FUNCTIONS FOR CHANGING THE DATA

    //this change the attributes aprt from the flightNum and the destination which will always be constant
    void changeFlightData(Airport airport, string flightNum);
    void setTime();
    //set the price of the flight
    void setPrice(string flightNum);
    //set the airline Company
    void setAirlineCompany(string flightNum);
    //set the number of seats in the plane
    void setNumberOfSeats(string flightNum);

    void setPilot(Airport airport);
    
    //FUNCTIONS FOR SHOWING THE DATA

    //shows the data of the flight
    void showFlightData(Airport airport) const;
};