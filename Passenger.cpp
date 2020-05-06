#include <iostream>
#include <string>
#include "Passenger.h"
#include "Airport.h"
#include "Flight.h"

using namespace std;

//Constructor
Passenger::Passenger(Airport airport):Person(airport){
    cout<<"If you have a flight please enter the flight number  lease press 0)"<<endl;
    cin>>flightNum;
    if(flightNum=="0"){
        flightSeat="0";
    }
    else{
        cout<<"Please specify your seat number";
        cin>>flightSeat;
    }
}

//Destructor
Passenger::~Passenger(){}

//the passengers only get options for general information about the airport and their flights
void Passenger::menu(Airport airport)const{
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
           case 1:
                printData();
                break;
           case 2:
                airport.showAirportData();
                break;
           case 3:
                showFlightData(flightNum);
                break;
           case 4:
                //changeData(this);
                break;
           case 5:
                //setFlightData();//error
                break;
           case 6:
                airport.flightsData();
                break;
           case 0:
                cout<<"Thank you, goodbye!"<<endl;
                break;
           default: //error handling for characters and strings!!
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

//OPTION 3: See flight data
void Passenger::showFlightData(string id) const{
    //open file and search for id
    //create object Flight with id
    //flight.showFlightData();
}

//Option 5: Change Flight Data
void Passenger::setFlightData(){
    cout<<"Current flight ID: "<<flightNum<<endl;
    cout<<"New Flight ID (if you don't want to change it please write it again): ";
    cin>>flightNum;

    cout<<"Current seat: "<<flightSeat<<endl;
    cout<<"New seat (if you don't want to change it please write it again): ";
    cin>>flightSeat;
}