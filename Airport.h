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
        //Default constructor
        Airport();
        
        //Destructor
        ~Airport();
        
        //returns the number of registered passengers in the airport
        int passengersNum() const;
        
        //returns the number of registered employees in the airport
        int employeesNum() const;
        
        //prints the data of each flight registered in the airport
        void flightsData() const;
        
        //returns true if the input is equal to the password
        bool checkPassword(string input)const;
        
        //Shows all the Data of the Airport (name, location, passengersNum, employeesNum and flightsData)
        void showAirportData() const;
        
        //Shows all the General Data of the Airport and the password
        void showAirportDataPersonnel() const;
        
        //Shows the password
        void showPassword()const;
        
        void setAirportName();

        void changeFlightData();

        void setPassword();
};

//*********************************************************************************************
//                                          ISSUES
//*********************************************************************************************
//*Missing file handling
//*Missing error handling
//*can we put objects inside a file? (asking for flightsData)



