#pragma once

#include <string>
#include"Person.h"
#include"Airport.h"
#include "Flight.h" 
 
class Passenger:public Person{
  protected:
    string flightNum;   //id of the booked flight (or 0 if there's no flight booked)
    string flightSeat;  //number of booked seat (or 0 if there's no seat booked)
  public:
    //CONSTRUCTORS & DESTRUCTORS

    //Constructor
    Passenger(Airport airport);   
    Passenger(int id, Airport airport);
    //Destructor
    ~Passenger();
    
    //MENU AND ITS FUNCTIONS

    //the passengers only get options for general information about the airport and their flights
    void menu(Airport airport)const;   
    //prints the data of the Passenger
    virtual void printData()const override;
    //Change the flight data of the passenger (does not change the actual flight data)
    void setMyFlightData();
};

