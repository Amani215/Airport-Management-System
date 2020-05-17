#include <iostream>
#include <fstream>
#include<string> 
#include "Airport.h"
#include "Flight.h"
#include "fileManagement.h"

using namespace std;

//*********************************************
//CONSTRUCTORS & DESTRUCTORS
//*********************************************

//Default constructor
Airport::Airport(){
    //read the name of the airport
    cout<<"Please give the name of this airport (without spaces)"<<endl;
    cin>>airportName;
    //read the location
    cout<<"Please give the location of this airport"<<endl;
    cin>>location;
    //create the name of the text file from the name and the location
    fileName=airportName+"-"+location+".txt";

    //setting the password
    FileManagement fileManager(fileName);
    //if this airport is new then the password should be set to its default value "admin"
    if(!fileManager.fileExists()){
        password="admin";
        fileManager.write("password,"+password+",");
    }
    //if the airport is old then get the password from the file
    else
    {
        FileManagement fileManager(fileName);
        //open the airport file
        ifstream file;
        try{file.open(fileName);}
        catch(...){
            cout<<"Could not create file!"<<endl;
            throw exception();
        }
        //the password is always in the first line so we break the loop from the first iteration
        string str;
        while(getline(file,str)){
            password=fileManager.getAttributeFromLine(str,1);
            break;
        }
    }
}

//*********************************************
//FUNCTIONS FOR SHOWING DATA
//*********************************************

//Prints all the General Data of the Airport (name, location, passengersNum, employeesNum and flightsData)
void Airport::showAirportData() const{
    FileManagement fileManager(fileName);
    cout<<"--"<<airportName<<" Airport General Data--"<<endl;
    cout<<"Location: "<<location<<endl;
    cout<<"Number of passengers now: "<< fileManager.numberOf("passenger")<<endl;
    cout<<"Number of employees now: "<<fileManager.numberOf("employee")<<endl;
}

//Prints the password
void Airport::showPassword()const{ cout<<"Password: "<<password<<endl; }

//Prints a flight's data according to the given flight number
void Airport::showFlightData(string flightNum) const{
    //if the flight number is 0 then the passenger doesn't have a registered flight yet
    if(flightNum=="0"){
        cout<<"You do not have a registered flight yet."<<endl;
    }
    //if it's not 0 then search for a flight with such a number
    else{
        FileManagement fileManager(fileName);
        bool found=false;   //set to true if the flight is found

        //open the airport file
        ifstream file;
        try{file.open(fileName);}
        catch(...){
            cout<<"Could not open file!"<<endl;
            throw exception();
        }

        //search for the flight with the given flight number
        string str;
        while(getline(file,str)){
            //if it's found then show the data of the flight and set the variable found to true
            if((fileManager.typeOfObjectInLine(str)=="flight")&&(fileManager.getAttributeFromLine(str,1)==flightNum)){
                Flight flight(*this,flightNum);
                flight.showFlightData(*this);
                found=true;
            }
        }
        //if it's not found then show a message
        if(found==false) cout<<"There's no flight with such an id"<<endl;
    }
}

//prints the data of each flight registered in the airport
void Airport::flightsData() const{
    FileManagement fileManager(fileName);
    //if there are no flights then show a message
    if(fileManager.numberOf("flight")==0){
        cout<<"     Sorry, there are no flights for the moment."<<endl;
    }
    //if there are flights then show their data
    else{
        //open file for reading
        ifstream file;
        try{ file.open(fileName);}
        catch(...){
            cout<<"Could not open file!";
            throw exception();
        }
        //read the file
        string str;
        while (getline(file,str)){
            //if a flight is found show the data
            if(fileManager.typeOfObjectInLine(str)=="flight"){
                showFlightData(fileManager.getAttributeFromLine(str,1));
            }
        }
    }
}

//*********************************************
//FUNCTIONS FOR CHANGING DATA
//*********************************************

//Change the password
void Airport::setPassword(){
    //read the new password
    cout<<"New password (do not use spaces!): ";
    cin>>password;
    //Change it in the file
    FileManagement file(fileName);
    file.modify("password,"+password+",",0);

}

//Change the name of the airport
void Airport::setAirportName(){
    //read the name
    cout<<"The current name is "<<airportName<<", please set the new one (do not use spaces!): ";
    cin>>airportName;
    //rename the file
    rename(fileName.c_str(),(airportName+"-"+location+".txt").c_str());
    fileName=airportName+"-"+location+".txt";
}

//Change a flight data according to the given number
void Airport::changeFlightData(){
    FileManagement fileManager(fileName);
    //read the flight number
    string input;
    cout<<"Please give the number of the flight: ";
    cin>>input;
    
    //if the given number is new then create a new flight
    if(!fileManager.existant("flight",input)){
        cout<<"This flight does not exists in the database, it's going to be added as a new one"<<endl;
        Flight flight(*this,input);
    }
    //if the flight with the given number exists then change its data
    else{ 
        Flight flight(*this,input);
        flight.changeFlightData(*this);
    }
}

//*********************************************
//OTHER FUNCTIONS
//*********************************************

//returns true if the input is equal to the password
bool Airport::checkPassword(string input)const{
    return (input.compare(password)==0);
}