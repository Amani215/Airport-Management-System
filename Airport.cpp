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
    
    fileName=airportName+"-"+location+".txt";

    //setting the password
    FileManagement fileManager(fileName);
    if(!fileManager.fileExists()){
        password="admin";
        fileManager.write("password,"+password+",");
    }else{
        FileManagement fileManager(fileName);
        ifstream file;
        try{file.open(fileName);}
        catch(...){
            cout<<"Could not create file!"<<endl;
            throw exception();
        }
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

//Shows all the General Data of the Airport (name, location, passengersNum, employeesNum and flightsData)
void Airport::showAirportData() const{
    FileManagement fileManager(fileName);
    cout<<"--"<<airportName<<" Airport General Data--"<<endl;
    cout<<"Location: "<<location<<endl;
    cout<<"Number of passengers now: "<< fileManager.numberOf("passenger")<<endl;
    cout<<"Number of employees now: "<<fileManager.numberOf("employee")<<endl;
}

//Shows the password
void Airport::showPassword()const{ cout<<"Password: "<<password<<endl; }

//Shows a flight according to the given flight number
void Airport::showFlightData(string flightNum) const{
    if(flightNum=="0"){
        cout<<"You do not have a registered flight yet."<<endl;
    }
    else{
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
}
//prints the data of each flight registered in the airport
void Airport::flightsData() const{
    FileManagement fileManager(fileName);
    if(fileManager.numberOf("flight")==0){
        cout<<"     Sorry, there are no flights for the moment."<<endl;
    }
    else{
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
    file.modify("password,"+password+",",0);

}
//Change the name of the airport
void Airport::setAirportName(){
    cout<<"The current name is "<<airportName<<", please set the new one: ";
    cin>>airportName;
    //change the filename and copy the old file in the new one
    rename(fileName.c_str(),(airportName+"-"+location+".txt").c_str());
    fileName=airportName+"-"+location+".txt";
}
//Change a flight data according to the given id
void Airport::changeFlightData(){
    FileManagement fileManager(fileName);

    string input;
    cout<<"Please give the id of the flight: ";
    cin>>input;
    
    if(!fileManager.existant("flight",input)){
        cout<<"This flight does not exists in the database, it's going to be added as a new one"<<endl;
        Flight flight(*this,input);
    }
    else{ 
        Flight flight(*this,input);
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