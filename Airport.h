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
        //Shows all the General Data of the Airport and the password
        void showAirportDataPersonnel() const;
        //Shows the password
        void showPassword()const;
        //returns the number of registered passengers in the airport
        int passengersNum() const;       
        //returns the number of registered employees in the airport
        int employeesNum() const;
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
        //file exists if there is a line where the password is written
        bool fileExists()const;
        //returns true if the input is equal to the password
        bool checkPassword(string input)const;
        //returns true if the employee with the given passport exists in the database
        bool existantEmployee(string passport)const;
        //returns true if the passenger with the given passport exists in the database
        bool existantPassenger(string passport)const;
        //returns true if the flight with the given number exists in the database
        bool existantFlight(string flightNum)const;
        //returns the type of the object in a line (examples: "passenger","employee","flight","password")
        string typeOfObjectInLine(string str)const;
        //returns the value of the attribute according to the given position
        string getAttributeFromLine(string str,int orderOfTheAttribute)const;
};



