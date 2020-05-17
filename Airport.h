#pragma once

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Airport{
        string fileName;    //name of the file of the airport
        string airportName; //name of the airport
        string location;    //location of the airport
        string password;    //password of the airport
    public:
        //CONSTRUCTORS & DESTRUCTORS

        //Default constructor
        Airport();   
        //Destructor
        ~Airport(){}
        
        //FUNCTIONS FOR SHOWING DATA

        //Shows all the Data of the Airport (name, location, passengersNum, employeesNum and flightsData)
        void showAirportData() const;
        //Shows the password
        void showPassword()const;
        //prints the data of a flight according to a given flight number
        void showFlightData(string flightNum)const;
        //prints the data of each flight registered in the airport
        void flightsData() const;
        
        //FUNCTIONS FOR CHANGING DATA

        //Change the name of the airport
        void setAirportName();
        //change the password
        void setPassword();
        //Changes the data of a flight according to a flight number (asked for inside the function)
        void changeFlightData();

        //OTHER FUNCTIONS

        //returns the name of the file
        string getfileName() const{return fileName;}
        //returns true if the input is equal to the password
        bool checkPassword(string input)const;
};



