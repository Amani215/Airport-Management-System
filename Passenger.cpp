#include <iostream>
#include <string>
#include "Passenger.h"
#include "Airport.h"
#include "Flight.h"

using namespace std;

//*************************************
//CONSTRUCTORS & DESTRUCTORS
//*************************************

//Constructor
Passenger::Passenger(Airport airport):Person(airport){
    cout<<"If you have a flight please enter the flight number (if not please press 0)"<<endl;
    cin>>flightNum;
    if(flightNum=="0"){
        flightSeat="0";
    }
    else{
        cout<<"Please specify your seat number";
        cin>>flightSeat;
    }
}

Passenger::Passenger(int id, string filename):Person(id,filename){
    //open file
    //search for id
    //give the flight attributes
}

//Destructor
Passenger::~Passenger(){}

//*************************************
//MENU AND FUNCTIONS RELATED TO IT
//*************************************

//the passengers only get options for general information about the airport and their flights
void Passenger::menu(Airport airport)const{
    Passenger passenger(id,airport.getfileName());
    int option;
    
    do{
       //Menu
       cout<<endl;
       cout<<"1. See my personal data"<<endl;
       cout<<"2. See airport data"<<endl;
       cout<<"3. See my flight data"<<endl;
       cout<<"4. Change my personal data"<<endl;
       cout<<"5. Change my flight data"<<endl;
       cout<<"6. Discover flights"<<endl;
       cout<<"0. Exit."<<endl<<endl;
       
       //read the user's choice
       cin>>option;
       
       //execute the user's choice
       switch(option){
           case 1://Done
                passenger.printData();
                break;
           case 2://Done
                airport.showAirportData();
                break;
           case 3:
                airport.showFlightData(flightNum);
                break;
           case 4://Done (file handling)
                passenger.changeData();
                break;
           case 5://Done (file handling)
                passenger.setMyFlightData();
                break;
           case 6:
                airport.flightsData();
                break;
           case 0://Done
                cout<<"Thank you, goodbye!"<<endl;
                break;
           default: 
                cout<<"There's no such option!"<<endl; 
                break;
       }
    }while(option!=0);
    
    return;//the user chose to log out (option 0)
}  

//OPTION 1: see personal data
//prints the data of the Passenger 
void Passenger::printData()const{
    cout<<"--My Personal Data--"<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Passport number: "<<passport<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Age "<<age<<endl;
    cout<<"Nationality: "<<nationality<<endl;
    cout<<"Flight info:"<<endl;
    cout<<"     Flight number: "<<flightNum<<endl;
    cout<<"     Booked seat: "<<flightSeat<<endl;
}

//Option 5: Change Flight Data
void Passenger::setMyFlightData(){
    cout<<"Current flight ID: "<<flightNum<<endl;
    cout<<"New Flight ID (if you don't want to change it please write it again): ";
    cin>>flightNum;

    cout<<"Current seat: "<<flightSeat<<endl;
    cout<<"New seat (if you don't want to change it please write it again): ";
    cin>>flightSeat;
}

//*********************MISSING*******************
//Passenger passenger(id,airport.getfileName()); 