#pragma once

#include<iostream>
#include<string>
#include "Airport.h"

using namespace std;

class Flight{
    string flightNum;       //flight ID 
    string destination;     //destination of the flight
    int dateOfTakingOff[8]; //date of the flight stored in a table (ddmmyyyy)
    int timeOfTakingOff[4]; //time of the flight stored in a table (hhmm)
    double price;           //price in forints
    string airlineCompany;  //name of the airline company
    int numberOfSeats;      //number of seats of the airplane
    string* crew;           //table of the names of the crew 
    int sizeOfTheCrew;      //number of people in the crew
  public:
    //CONSTRUCTORS & DESTRUCTORS

    //Default constructor
    Flight(Airport airport,string flightNum);
    //Destructor
    ~Flight(){}
    
    //FUNCTIONS FOR CHANGING THE DATA

    //fills the table of the crew with names of the members
    void fillTheCrew();
    
    //FUNCTIONS FOR SHOWING THE DATA

    //shows the data of the flight
    void showFlightData() const;
    //Shows the date of taking off
    void showDate() const;
    //Shows the time of taking off
    void showTime() const;
    //Shows the list of the Crew
    void showCrew() const;
};