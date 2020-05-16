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
    
    cout<<"Please give the name of this airport (without spaces)"<<endl;
    cin>>airportName;
    
    cout<<"Please give the location of this airport"<<endl;
    cin>>location;
    
    password="admin";
    
    fileName=airportName+"-"+location+".txt";

    FileManagement fileManager(fileName);
    if(!fileManager.fileExists()) fileManager.write("password,"+password);
}


//*********************************************
//FUNCTIONS FOR SHOWING DATA
//*********************************************

//Shows all the General Data of the Airport (name, location, passengersNum, employeesNum and flightsData)
void Airport::showAirportData() const{
    FileManagement fileManager(fileName);
    cout<<"--"<<airportName<<" Airport General Data--"<<endl;
    cout<<"Location: "<<location<<endl;
    cout<<"Number of passengers now: "<< fileManager.numberOf("passenger")<<endl;
    cout<<"Number of employees now: "<<fileManager.numberOf("employee")<<endl;
    cout<<"Flights:"<<endl;
    flightsData();
}
//Shows all the General Data of the Airport and the password
void Airport::showAirportDataPersonnel() const{
    FileManagement fileManager(fileName);
    cout<<"--"<<airportName<<" Airport General Data--"<<endl;
    cout<<"Location: "<<location<<endl;
    cout<<"Number of passengers now: "<< fileManager.numberOf("passenger")<<endl;
    cout<<"Number of employees now: "<<fileManager.numberOf("employee")<<endl;
    showPassword();
    cout<<"Flights:"<<endl;
    flightsData();
}
//Shows the password
void Airport::showPassword()const{ cout<<"Password: "<<password<<endl; }
//Shows a flight according to the given flight number
void Airport::showFlightData(string flightNum) const{
    FileManagement fileManager(fileName);
    bool found=false;

    string str;
    //open file and search for id
    ifstream file;
    try{file.open(fileName);}
    catch(...){
        cout<<"Could not open file!"<<endl;
        throw exception();
    }

    while(getline(file,str)){
        if((fileManager.typeOfObjectInLine(str)=="flight")&&(fileManager.getAttributeFromLine(str,1)==flightNum)){
            Flight flight(*this,flightNum);
            flight.showFlightData(*this);
            found=true;
        }
    }
    if(found==false) cout<<"There's no flight with such an id"<<endl;
}
//prints the data of each flight registered in the airport
void Airport::flightsData() const{
    FileManagement fileManager(fileName);
    string str;
    //open file for reading
    ifstream file;
    try{ file.open(fileName);}
    catch(...){
        cout<<"Could not open file!";
        throw exception();
    }
    while (getline(file,str)){
        if(fileManager.typeOfObjectInLine(str)=="flight"){
            showFlightData(fileManager.getAttributeFromLine(str,1));
        }
    }
}


//*********************************************
//FUNCTIONS FOR CHANGING DATA
//*********************************************

//Change the password
void Airport::setPassword(){
    cout<<"New password: ";
    cin>>password;
    //Change it in the file
    FileManagement file(fileName);
    file.modify("password,"+password,0);

}
//Change the name of the airport
void Airport::setAirportName(){
    cout<<"The current name is "<<airportName<<", please set the new one: ";
    cin>>airportName;
    //change the filename and copy the old file in the new one
    rename(fileName.c_str(),(airportName+"-"+location+".txt").c_str());
}
//Change a flight data according to the given id
void Airport::changeFlightData(){
    FileManagement file(fileName);

    string input;
    cout<<"Please give the id of the flight: ";
    cin>>input;

    Flight flight(*this,input);
    //change the flight with that id in the file
    if(file.existant("flight",input)){ 
        flight.changeFlightData(*this,input);
    }
}


//*********************************************
//OTHER FUNCTIONS
//*********************************************

//returns true if the input is equal to the password
bool Airport::checkPassword(string input)const{
    return (input.compare(password)==0);
}