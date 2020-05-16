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
Passenger::Passenger(Airport airport,string passport, bool existantPerson)
    :Person(airport,passport, existantPerson)
{
    if(existantPerson){
        this->passport="";
        //open file
        ifstream file;
        try{
            file.open(airport.getfileName());
        }
        catch(...){
            cout<<"there was an error";
        }

        //search for id and assign the attributes
        string str;
        while (getline(file,str))
        {
            if((airport.typeOfObjectInLine(str)=="passenger")&&(airport.getAttributeFromLine(str,1)==passport)){
                this->passport=airport.getAttributeFromLine(str,1);
                name=airport.getAttributeFromLine(str,2);
                age=stoi(airport.getAttributeFromLine(str,3));
                nationality=airport.getAttributeFromLine(str,4);
                flightNum=airport.getAttributeFromLine(str,5);
                flightSeat=airport.getAttributeFromLine(str,6);
                break;
            }   
        }

        if(this->passport=="") cout<<"There was an error"<<endl;

        file.close();
    }
    else{
        cout<<"If you have a flight please enter the flight number (if not please press 0)"<<endl;
        cin>>flightNum;
        if(flightNum=="0"){
            flightSeat="0";
        }
        else{
            if(!airport.existantFlight(flightNum)){
                do{
                    int input;
                    cout<<endl<<"There's no such flight in the database. Do you want to:"<<endl
                        <<"    1. Wait for updates and set flight to 0"<<endl
                        <<"    2. Change Flight Number "<<endl;
                    cin>>input;
                    if (input==1) {
                        flightNum="0";
                        flightSeat="0";
                        break;
                    }
                    else if (input==2){
                        cout<<"Flight Number: ";
                        cin>>flightNum;
                    }
                }while(!airport.existantFlight(flightNum));
            }
            if(airport.existantFlight(flightNum)){
                cout<<"Please specify your seat number";
                cin>>flightSeat;
            }
        }
        ofstream file;
        try{
            file.open(airport.getfileName(),ios::app);
        }
        catch(...){
            cout<<"There was an error.";
        }
        string str="passenger,"+passport+","+name+","+to_string(age)+","+nationality+","+flightNum+","+flightSeat+"\n";
        file<<str;

        file.close();
    }
}
 
//Destructor
Passenger::~Passenger(){}

//*************************************
//MENU AND FUNCTIONS RELATED TO IT
//*************************************

//the passengers only get options for general information about the airport and their flights
void Passenger::menu(Airport airport)const{
    Passenger passenger(airport,passport,true);
    if(passenger.passport!=passport) return; //if an error happens while searching for the id

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
                cout<<"--My Personal Data--"<<endl;
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
                passenger.setMyFlightData(airport);
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
    cout<<" Passport number: "<<passport<<endl;
    cout<<" Name: "<<name<<endl;
    cout<<" Age: "<<age<<endl;
    cout<<" Nationality: "<<nationality<<endl;
    cout<<" Flight info:"<<endl;
    cout<<"     Flight number: "<<flightNum<<endl;
    cout<<"     Booked seat: "<<flightSeat<<endl;
}

//Option 5: Change Flight Data
void Passenger::setMyFlightData(Airport airport){
    cout<<"Current flight number: "<<flightNum<<endl;
    cout<<"New Flight ID (if you don't want to change it please write it again): ";
    cin>>flightNum;
    if(!airport.existantFlight(flightNum)){
        do{
            cout<<"Sorry there's no such flight in our database. Do you want to:"<<endl
                <<" 1. Set the Flight to 0 and proceed"<<endl
                <<" 2. Register in another flight"<<endl;
            int input;
            cin>>input;
            if(input==1){
                flightNum="0";
                flightSeat="0";
                break;
            }
            if(input==2){
                cout<<"New Flight: ";
                cin>>flightNum;
            }
        }while(!airport.existantFlight(flightNum));
    }
    
    if(flightNum!="0"){
        cout<<"Current seat: "<<flightSeat<<endl;
        cout<<"New seat (if you don't want to change it please write it again): ";
        cin>>flightSeat;
    }
}