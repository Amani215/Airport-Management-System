#include <iostream>
#include <string>
#include "Flight.h"

using namespace std;

    //Default constructor
    Flight::Flight(){
        long int input;
        
        cout<<"Flight Number: ";
        cin>>flightNum;
        
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
    }
    
    //Destructor
    Flight::~Flight(){}
    
    //fills the table of the crew with names of the members
    void Flight::fillTheCrew(){
        crew=new string[sizeOfTheCrew];
        
        for(int i=0; i<sizeOfTheCrew;i++){
            cout<<"Name of member "<<i<<": ";
            cin>>crew[i];
        }
    }
    
    //shows the data of the flight
    void Flight::showFlightData() const{
        cout<<"Flight Number: "<<flightNum<<endl;
        cout<<"Destination: "<<destination<<endl;
        cout<<"Date of taking off: ";
        showDate();
        cout<<"Time of taking off: ";
        showTime();
        cout<<"Price: "<<price<<endl;
        cout<<"Airline Company: "<<airlineCompany<<endl;
        cout<<"Number of seats: "<<numberOfSeats<<endl;
        cout<<"Crew list:"<<endl;
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
                cout<<i<<". "<<crew[i]<<endl;
            }
        }else{
            cout<<"There are no names yet..."<<endl;
        }
    }