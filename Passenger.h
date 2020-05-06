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
    //Constructor
    Passenger(Airport airport);
    
    //Destructor
    ~Passenger();
    
    //the passengers only get options for general information about the airport and their flights
    void menu(Airport airport)const; 
    
    //prints the data of the Passenger
    virtual void printData()const override;
    
    void changeData(){
        Person::changeData();}
    
    void showFlightData(string id) const;

    void setFlightData();
};

//consider adding a boolean for accompanied, if the passenger is a child the accompanied should be set to true (in the constructor)