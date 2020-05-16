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
    if(airport.existantFlight(flightNum)){
        this->flightNum="-1";
        string str;

        //open file
        ifstream file;
        try{file.open(airport.getfileName());}
        catch(...){cout<<"there was an error";}

        //search for id and assign the attributes
        while (getline(file,str))
        {
            if((airport.typeOfObjectInLine(str)=="flight")&&(airport.getAttributeFromLine(str,1)==flightNum)){
                this->flightNum=flightNum;
                destination=airport.getAttributeFromLine(str,2);
                timeOfTakingOff=airport.getAttributeFromLine(str,3);
                price=stod(airport.getAttributeFromLine(str,5));      
                airlineCompany=airport.getAttributeFromLine(str,6); 
                numberOfSeats=stoi(airport.getAttributeFromLine(str,7));   
                pilotPassport=airport.getAttributeFromLine(str,8);
            }   
        }

        if(this->flightNum=="-1") cout<<"The provided id does not exist"<<endl;
        file.close();
    }
    else{
        int input;

        this->flightNum=flightNum;

        cout<<"Destination: ";
        cin>>destination;

        setTime();
        
        cout<<"Price of the ticket: ";
        cin>>price;
        cout<<"Airline Company: ";
        cin>>airlineCompany;
        cout<<"Number of seats: ";
        cin>>numberOfSeats;

        string pilot;
        cout<<"Pilot passport number: ";
        setPilot(airport);

        //adding the object to the file
        FileManagement file(airport.getfileName());
        string str="flight,"+flightNum+","+destination+","+timeOfTakingOff+","+to_string(price)+","+airlineCompany+","+to_string(numberOfSeats)+","+pilot;
        file.write(str);
    } 
}

//*************************************
//FUNCTIONS FOR CHANGING DATA
//*************************************

//this changes the attributes apart from the flightNum and the destination which will always be constant
void Flight::changeFlightData(Airport airport, string flightNum){
    cout<<"If you don't want to change an attribute please type it again"<<endl;
    setTime();
    setPrice(flightNum);
    setAirlineCompany(flightNum);
    setNumberOfSeats(flightNum);
    Employee employee(airport,pilotPassport,true);
    cout<<"Current pilot is "<<employee.getName()<<" with passport number "<<employee.getPassport()<<endl;
    cout<<"Change it to: ";
    setPilot(airport);

    string attributes="flight,"+flightNum+","+timeOfTakingOff+","+to_string(price)+","+airlineCompany+","+to_string(numberOfSeats)+","+pilotPassport;
    ifstream file;
    string str;
    try{file.open(airport.getfileName());}
    catch(...){
        cout<<"Could not open file!"<<endl;
        throw exception();
    }
    int line=-1;
    while(getline(file,str)){
        line++;
        if((airport.typeOfObjectInLine(str)=="flight")&&(airport.getAttributeFromLine(str,1)==flightNum)){
            break;
        }
    }
    file.close();
    FileManagement newFile(airport.getfileName());
    newFile.modify(attributes,line);
    cout<<endl<<"Changes are done!"<<endl;
}
//set the time of taking off
void Flight::setTime(){
    int input;
    string str;
    do{
        cout<<"Day of Taking off: ";
        cin>>input;
    }while((input<0)||(input>31));
    str=to_string(input)+"-";

    do{        
        cout<<"Month of Taking off: ";
        cin>>input;
    }while((input<0)||(input>12));
    str+=(to_string(input)+"-");

    do{
        cout<<"Year of Taking off: ";
        cin>>input;
    }while(input<0);
    str+=(to_string(input)+" ");

    do{
        cout<<"Hour of Taking off: ";
        cin>>input;
    }while((input<0)||(input>23));
    str+=(to_string(input)+":");
    
    do{
        cout<<"Minute of Taking off: ";
        cin>>input;
    }while((input<0)||(input>59));
    str+=to_string(input);

    timeOfTakingOff=str;
}
//set the price of the flight
void Flight::setPrice(string flightNum){
    cout<<"Current price: "<<price<<" change it to:";
    cin>>price;
}
//set the airline Company
void Flight::setAirlineCompany(string flightNum){
    cout<<"Current airline company: "<<airlineCompany<<" change it to:";
    cin>>airlineCompany;
}
//set the number of seats in the plane
void Flight::setNumberOfSeats(string flightNum){
    cout<<"Current number of seats: "<<numberOfSeats<<" change it to:";
    cin>>numberOfSeats;
}
//set the pilot passport number
void Flight::setPilot(Airport airport){
    string pilot;
    cin>>pilot;
    if(!airport.existantEmployee(pilot)) {
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
        }while(!airport.existantEmployee(pilot)); 
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
    }