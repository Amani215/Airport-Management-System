#include <iostream>
#include <string>
#include "Passenger.h"
#include "Airport.h"
#include "Flight.h"
#include "fileManagement.h"

using namespace std;

//*************************************
//CONSTRUCTORS & DESTRUCTORS
//*************************************

//Constructor
Passenger::Passenger(Airport airport,string passport, bool existantPerson)
    :Person(airport,passport, existantPerson)
{
    if(existantPerson){
        FileManagement fileManager(airport.getfileName());
        this->passport="";
        //open file
        ifstream file;
        try{ file.open(airport.getfileName());}
        catch(...){
            cout<<"Could not open file!"<<endl;
            throw exception();
        }
        //search for id and assign the attributes
        string str;
        while (getline(file,str))
        {
            if((fileManager.typeOfObjectInLine(str)=="passenger")&&(fileManager.getAttributeFromLine(str,1)==passport)){
                this->passport=fileManager.getAttributeFromLine(str,1);
                name=fileManager.getAttributeFromLine(str,2);
                age=stoi(fileManager.getAttributeFromLine(str,3));
                nationality=fileManager.getAttributeFromLine(str,4);
                flightNum=fileManager.getAttributeFromLine(str,5);
                flightSeat=fileManager.getAttributeFromLine(str,6);
                break;
            }   
        }

        if(this->passport=="") cout<<"There was an error"<<endl;

        file.close();
    }
    else{
        FileManagement fileManager(airport.getfileName());
        cout<<"If you have a flight please enter the flight number (if not please press 0)"<<endl;
        cin>>flightNum;
        if(flightNum=="0"){
            flightSeat="0";
        }
        else{
            if(!fileManager.existant("flight",flightNum)){
                int input;
                do{
                    cout<<endl<<"There's no such flight in the database. Do you want to:"<<endl
                        <<"    1. Wait for updates and set flight to 0"<<endl
                        <<"    2. Change Flight Number "<<endl;
                    cin>>input;
                    if (input==1) {
                        flightNum="0";
                        flightSeat="0";
                    }
                    else if (input==2){
                        cout<<"Flight Number: ";
                        cin>>flightNum;
                    }
                }while((!fileManager.existant("flight",flightNum))&&(input!=1));
            }
            if(fileManager.existant("flight",flightNum)){
                cout<<"Please specify your seat number";
                cin>>flightSeat;
            }
        }
        string str="passenger,"+passport+","+name+","+to_string(age)+","+nationality+","+flightNum+","+flightSeat+",";
        fileManager.write(str);
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
           case 1:
                cout<<"--My Personal Data--"<<endl;
                passenger.printData();
                break;
           case 2:
                airport.showAirportData();
                break;
           case 3:
                airport.showFlightData(flightNum);
                break;
           case 4:
                passenger.changeData(airport);
                break;
           case 5:
                passenger.setMyFlightData(airport);
                break;
           case 6:
                airport.flightsData();
                break;
           case 0:
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
//OPTION 4: change personal data
//calls the function changeData of the base class Person and applies the changes in the airport file
void Passenger::changeData(Airport airport){
    FileManagement fileManager(airport.getfileName());
    Person::changeData();
    string attributes="passenger,"+passport+","+name+","+to_string(age)+","+nationality+","+flightNum+","+flightSeat+",";
    fileManager.modify(attributes,fileManager.lineOfObject(airport,"passenger",passport));
}
//Option 5: Change Flight Data
void Passenger::setMyFlightData(Airport airport){
    FileManagement fileManager(airport.getfileName());
    cout<<"Current flight number: "<<flightNum<<endl;
    cout<<"New Flight ID (if you don't want to change it please write it again): ";
    cin>>flightNum;
    if(!fileManager.existant("flight",flightNum)){
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
        }while(!fileManager.existant("flight",flightNum));
    }
    
    if(flightNum!="0"){
        cout<<"Current seat: "<<flightSeat<<endl;
        cout<<"New seat (if you don't want to change it please write it again): ";
        cin>>flightSeat;
    }

    string attributes="passenger,"+passport+","+name+","+to_string(age)+","+nationality+","+flightNum+","+flightSeat+",";
    fileManager.modify(attributes,fileManager.lineOfObject(airport,"passenger",passport));
}