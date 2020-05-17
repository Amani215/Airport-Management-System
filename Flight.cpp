#include <iostream>
#include <string>
#include <time.h>
#include "Flight.h"
#include "Airport.h"
#include "fileManagement.h"

using namespace std;

//*************************************
//CONSTRUCTORS & DESTRUCTORS
//*************************************

//Default constructor
Flight::Flight(Airport airport,string flightNum){
    FileManagement fileManager(airport.getfileName());
    //if the flight with the given flight number exists in the database
    if(fileManager.existant("flight",flightNum)){
        //open the airport file
        ifstream file;
        try{file.open(airport.getfileName());}
        catch(...){
            cout<<"Could not open file!"<<endl;
            throw exception();
        }

        //search for the flight number in the file and assign the attributes to the flight object
        string str;
        while (getline(file,str))
        {   
            if((fileManager.typeOfObjectInLine(str)=="flight")&&(fileManager.getAttributeFromLine(str,1)==flightNum)){
                this->flightNum=flightNum;
                destination=fileManager.getAttributeFromLine(str,2);
                timeOfTakingOff=fileManager.getAttributeFromLine(str,3);
                price=stod(fileManager.getAttributeFromLine(str,4));      
                airlineCompany=fileManager.getAttributeFromLine(str,5); 
                numberOfSeats=stoi(fileManager.getAttributeFromLine(str,6));   
                pilotPassport=fileManager.getAttributeFromLine(str,7);
                break;
            }   
        }
        //close the file
        file.close();
    }
    //if the flight with the given flight number doesn't exist in the airport file
    else{
        int input;
        //assign the flight number to the new Flight object
        this->flightNum=flightNum;
        //read destination
        cout<<"Destination (without spaces): ";
        cin>>destination;
        //set the time of taking off
        setTime();
        //read the price of the ticket
        cout<<"Price of the ticket: ";
        cin>>price;
        //read the name of the airline company
        cout<<"Airline Company: ";
        cin>>airlineCompany;
        //read the number of seats
        cout<<"Number of seats: ";
        cin>>numberOfSeats;
        //get the pilot's passport (it should exist in the database)
        cout<<"Pilot passport number: ";
        setPilot(airport);

        //adding the object to the file
        string str="flight,"+flightNum+","+destination+","+timeOfTakingOff+","+to_string(price)+","+airlineCompany+","+to_string(numberOfSeats)+","+pilotPassport+",";
        fileManager.write(str);
    } 
}

//*************************************
//FUNCTIONS FOR CHANGING DATA
//*************************************

//this changes the attributes apart from the flightNum and the destination which will always be constant
void Flight::changeFlightData(Airport airport){
    showFlightData(airport);

    cout<<"If you don't want to change an attribute please type it again"<<endl;
    setTime();
    setPrice(flightNum);
    setAirlineCompany(flightNum);
    setNumberOfSeats(flightNum);
    //changing the pilot:
    Employee employee(airport,pilotPassport,true);
    cout<<"Current pilot is "<<employee.getName()<<" with passport number "<<employee.getPassport()<<endl;
    cout<<"Change it to: ";
    setPilot(airport);
    //add the changes to the file
    string attributes="flight,"+flightNum+","+destination+","+timeOfTakingOff+","+to_string(price)+","+airlineCompany+","+to_string(numberOfSeats)+","+pilotPassport+",";
    FileManagement fileManager(airport.getfileName());
    fileManager.modify(attributes,fileManager.lineOfObject(airport,"flight",flightNum));

    cout<<endl<<"Changes are done!"<<endl;
}

//set the time of taking off
void Flight::setTime(){
    unsigned int input;
    string str;
    //read the day (should be less than 32)
    do{
        cout<<"Day of Taking off: ";
        cin>>input;
    }while(input>31);
    str=to_string(input)+"-";

    //read the month (should be less than 13)
    do{        
        cout<<"Month of Taking off: ";
        cin>>input;
    }while(input>12);
    str+=(to_string(input)+"-");
    
    //read the year
    cout<<"Year of Taking off: ";
    cin>>input;
    str+=(to_string(input)+"::");

    //read the hour (should be less than 24)
    do{
        cout<<"Hour of Taking off: ";
        cin>>input;
    }while(input>23);
    str+=(to_string(input)+":");
    
    //read the minute (should be less than 60)
    do{
        cout<<"Minute of Taking off: ";
        cin>>input;
    }while(input>59);
    str+=to_string(input);
    //assign the resulting string to the time attribute
    timeOfTakingOff=str;
}

//set the price of the flight
void Flight::setPrice(string flightNum){
    cout<<"Current price: "<<price<<" change it to:";
    cin>>price;
}

//set the airline Company
void Flight::setAirlineCompany(string flightNum){
    cout<<"Current airline company: "<<airlineCompany<<". Change it to:";
    cin>>airlineCompany;
}

//set the number of seats in the plane
void Flight::setNumberOfSeats(string flightNum){
    cout<<"Current number of seats: "<<numberOfSeats<<". Change it to:";
    cin>>numberOfSeats;
}

//set the pilot passport number
void Flight::setPilot(Airport airport){
    FileManagement fileManager(airport.getfileName());
    string pilot;
    cin>>pilot;
    if(!fileManager.existant("employee",pilot)) {
        int input;
        do{
            cout<<"This passport number doesn't exist in the employees database. Do you want to add it?"<<endl;
            cout<<" 0.No"<<endl<<" 1.Yes"<<endl;
            cin>>input;
            if(input==1) Employee newEmployee(airport,pilot,false);
            else
            {
                cout<<"Please give a new passport number"<<endl;
                cin>>pilot;
            } 
        }while(!fileManager.existant("employee",pilot)); 
    }
    pilotPassport=pilot;
}

//*************************************
//FUNCTIONS FOR SHOWING DATA
//*************************************

//shows the data of the flight
void Flight::showFlightData(Airport airport) const{
        cout<<"Flight Number: "<<flightNum<<endl;
        cout<<" Destination: "<<destination<<endl;
        cout<<" Time of taking off: "<<timeOfTakingOff<<endl;
        cout<<" Price: "<<price<<endl;
        cout<<" Airline Company: "<<airlineCompany<<endl;
        cout<<" Number of seats: "<<numberOfSeats<<endl;
        cout<<" Pilot: "<<endl;
        Employee pilot(airport, pilotPassport,true);
        pilot.printData();
        cout<<endl;
    }