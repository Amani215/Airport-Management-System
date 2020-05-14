#include <iostream>
#include <string>
#include "Flight.h"
#include "Airport.h"

using namespace std;
    //*************************************
    //CONSTRUCTORS & DESTRUCTORS
    //*************************************

    //Default constructor
    Flight::Flight(Airport airport,string flightNum):flightNum(flightNum){
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
                    //int dateOfTakingOff[8];
                    //int timeOfTakingOff[4]; 
                    price=stod(airport.getAttributeFromLine(str,5));      
                    airlineCompany=airport.getAttributeFromLine(str,6); 
                    numberOfSeats=stoi(airport.getAttributeFromLine(str,7));     
                    fillTheCrew(airport,str);
                }   
            }

            if(this->flightNum=="-1") cout<<"The provided id does not exist"<<endl;
            file.close();
        }
        else{
            long int input;
            cout<<"Destination: ";
            cin>>destination;

            cout<<"Date of taking off (ddmmyyyy): ";
            cin>>input;
            int divider=1;
            for(int i=0;i<8;i++){
                dateOfTakingOff[i]=(int)(((input % (divider*10))/divider));
                divider=divider*10;
            }
            
            cout<<"Time of taking off (hhmm): ";
            cin>>input;
            divider=1;
            for(int i=0;i<4;i++){
                timeOfTakingOff[i]=(int)(((input % (divider*10))/divider));
                divider=divider*10;
            }
            
            cout<<"Price of the ticket: ";
            cin>>price;
            cout<<"Airline Company: ";
            cin>>airlineCompany;
            cout<<"Number of seats: ";
            cin>>numberOfSeats;
            cout<<"Size of the crew: ";
            cin>>sizeOfTheCrew;
            crew= nullptr;

            //adding the object to the file
            ofstream file;
            try{ file.open(airport.getfileName());}
            catch(...){ cout<<"There was an error.";}

            string str="flight,"+flightNum+","+destination+","+to_string(price)+","+airlineCompany+","+to_string(numberOfSeats)+",";
            string crewMembers=crewToString(*this);
            file<<str<<crewMembers<<endl;
            file.close();
        }
    }

    //*************************************
    //FUNCTIONS FOR CHANGING DATA
    //*************************************

    //fills the table of the crew with names of the members
    void Flight::fillTheCrew(){
        crew=new string[sizeOfTheCrew];
        
        for(int i=0; i<sizeOfTheCrew;i++){
            cout<<"Name of member "<<i<<": ";
            cin>>crew[i];
        }
    }

    void Flight::fillTheCrew(Airport airport,string str){
        int i=0;
        sizeOfTheCrew=getSizeOfTheCrew(str);
        crew=new string[sizeOfTheCrew];
        while(i<sizeOfTheCrew){
            crew[i]=airport.getAttributeFromLine(str,8+i);
            i++;
        }
    }

    void Flight::changeFlightData(string flightNum){
        cout<<"If you don't want to change an attribute please type it again"<<endl;
        setDate(flightNum);
        setTime(flightNum);
        setPrice(flightNum);
        setAirlineCompany(flightNum);
        setNumberOfSeats(flightNum);
        cout<<"Current crew:"<<endl;
        showCrew();
        int answer;
        cout<<"Do you want to change it? (Press 1 if yes, 0 if no"<<endl;
        cin>>answer;
        if(answer==1) changeCrew(flightNum);

        cout<<endl<<"Changes are done!"<<endl;
    }

    //set the date of taking off to a new one
    void Flight::setDate(string flightNum){
        cout<<"Current date of taking off: ";
        showDate();
        cout<<" change it to: ";
    }
    //set the time of taking off to a new one
    void Flight::setTime(string flightNum){
        cout<<"Current time of taking off: ";
        showTime();
        cout<<" change it to: ";
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
    //change the crew data
    void Flight::changeCrew(string flightNum){

    }

    //*************************************
    //FUNCTIONS FOR SHOWING DATA
    //*************************************

    //shows the data of the flight
    void Flight::showFlightData() const{
        cout<<"Flight Number: "<<flightNum<<endl;
        cout<<"     Destination: "<<destination<<endl;
        cout<<"     Date of taking off: ";
        showDate();
        cout<<endl;
        cout<<"     Time of taking off: ";
        showTime();
        cout<<endl;
        cout<<"     Price: "<<price<<endl;
        cout<<"     Airline Company: "<<airlineCompany<<endl;
        cout<<"     Number of seats: "<<numberOfSeats<<endl;
        cout<<"     Crew list:"<<endl;
        showCrew();
    }
    
    //Shows the date of taking off
    void Flight::showDate() const{
        for(int i=0;i<8;i++){
            if((i==2)||(i==4)) cout<<"-";
            cout<<dateOfTakingOff[i];
        }
    }
    
    //Shows the time of taking off
    void Flight::showTime() const{
        for(int i=0;i<4;i++){
            if(i==2) cout<<":";
            cout<<timeOfTakingOff[i];
        }
    }
    
    //Shows the list of the Crew
    void Flight::showCrew() const{
        if(crew){
            for(int i=0;i<sizeOfTheCrew;i++){
                cout<<"         "<<i<<". "<<crew[i]<<endl;
            }
        }else{
            cout<<"         There are no names yet..."<<endl;
        }
    }

    int Flight::getSizeOfTheCrew(string str)const{//*******************************
        int i=8,counter=0;
    }

    string Flight::crewToString(const Flight& flight)const{
        int i=0;
        string result="";
        if(crew){
            while(i<flight.sizeOfTheCrew){
                if(i<flight.sizeOfTheCrew-1)
                    result+=flight.crew[i]+",";
                else
                    result+=flight.crew[i];
                i++;
            }
        }
        else 
            result="0";
        return result;
    }
//**********ISSUES*********
//how to add a table in a file?