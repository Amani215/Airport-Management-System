#pragma once

#include<iostream>
#include<string>
#include <time.h>
#include "Airport.h"

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

    void fillTheCrew(Airport airport,string str);
    //this change the attributes aprt from the flightNum and the destination which will always be constant
    void changeFlightData(string flightNum);
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
    //change the crew data
    void changeCrew(string flightNum);
    
    //FUNCTIONS FOR SHOWING THE DATA

    //shows the data of the flight
    void showFlightData() const;
    //Shows the date of taking off
    void showDate() const;
    //Shows the time of taking off
    void showTime() const;

    void stringToTime(string str);

    void writeTime(Airport airport, tm* time);

    void readTime(Airport airport, tm* time);
    //Shows the list of the Crew
    void showCrew() const;

    int getSizeOfTheCrew(Airport airport, string str)const;
    
    string crewToString(const Flight& flight)const;
};