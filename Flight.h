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
    //int dateOfTakingOff[8]; //date of the flight stored in a table (ddmmyyyy)
    //int timeOfTakingOff[4]; //time of the flight stored in a table (hhmm)
    struct tm* timeOfTakingOff;
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
    //set the date of taking off to a new one
    void setDate(string flightNum);
    //set the time of taking off to a new one
    void setTime(string flightNum);
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
    //Shows the date of taking off
    void showDate() const;
    //Shows the time of taking off
    void showTime() const;

    void stringToTime(string str);

    void writeTime(Airport airport, tm* time);

    void readTime(Airport airport, tm* time);
};