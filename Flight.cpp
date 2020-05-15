#include <iostream>
#include <string>
#include <time.h>
#include "Flight.h"
#include "Airport.h"

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
                    //stringToTime(str);
                    readTime(airport,timeOfTakingOff);
                    price=stod(airport.getAttributeFromLine(str,5));      
                    airlineCompany=airport.getAttributeFromLine(str,6); 
                    numberOfSeats=stoi(airport.getAttributeFromLine(str,7));     
                    //fillTheCrew(airport,str);
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

            cout<<"Day of Taking off: ";
            cin>>input;
            timeOfTakingOff->tm_mday=input;

            cout<<"Month of Taking off: ";
            cin>>input;
            timeOfTakingOff->tm_mon=input-1;//Because 0<=tm_mon<=11

            cout<<"Year of Taking off: ";
            cin>>input;
            timeOfTakingOff->tm_year=input;

            cout<<"Hour of Taking off: ";
            cin>>input;
            timeOfTakingOff->tm_hour=input;

            cout<<"Minute of Taking off: ";
            cin>>input;
            timeOfTakingOff->tm_min=input;
            
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
            try{ file.open(airport.getfileName(),ios::app);}
            catch(...){ cout<<"There was an error.";}

            //convert the time to a string
            //char* timeString;
            //strftime(timeString,20,"%d:%m:%Y:%H:%M", timeOfTakingOff);
            
            /*time_t rawtime=mktime(timeOfTakingOff);
            struct tm * timeinfo;
            char buffer [80];
            time (&rawtime);
            timeinfo = localtime (&rawtime);
            strftime(buffer,80,"%d:%m:%Y:%H:%M", timeinfo);
            cout<<buffer<<endl;*/

            //put the data in the file
            string str="flight,"+flightNum+","+destination+",";
            file<<str;
            writeTime(airport,timeOfTakingOff);
            str=","+to_string(price)+","+airlineCompany+","+to_string(numberOfSeats);
            //string crewMembers=crewToString(*this);
            //str+=crewMembers;
            cout<<"here"<<endl;
            file<<str<<endl; 
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

    //fills the crew from an existant flight in file
    void Flight::fillTheCrew(Airport airport,string str){
        int i=0;
        sizeOfTheCrew=getSizeOfTheCrew(airport,str);
        crew=new string[sizeOfTheCrew];
        while(i<sizeOfTheCrew){
            crew[i]=airport.getAttributeFromLine(str,8+i);
            i++;
        }
    }

    void Flight::changeFlightData(string flightNum){
        cout<<"If you don't want to change an attribute please type it again"<<endl;
        //setDate(flightNum);
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

    //set the time of taking off to a new one
    void Flight::setTime(string flightNum){//*************************************
        int input;
        cout<<"Current time of taking off: ";
        showTime();
        cout<<" change it to: ";
        cout<<"Day of Taking off: ";
        cin>>input;
        timeOfTakingOff->tm_mday=input;

        cout<<"Month of Taking off: ";
        cin>>input;
        timeOfTakingOff->tm_mon=input;

        cout<<"Year of Taking off: ";
        cin>>input;
        timeOfTakingOff->tm_year=input;

        cout<<"Hour of Taking off: ";
        cin>>input;
        timeOfTakingOff->tm_hour=input;

        cout<<"Minute of Taking off: ";
        cin>>input;
        timeOfTakingOff->tm_min=input;
        //insert it in file
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
    void Flight::changeCrew(string flightNum){//***********************************************

    }

    //*************************************
    //FUNCTIONS FOR SHOWING DATA
    //*************************************

    //shows the data of the flight
    void Flight::showFlightData() const{
        cout<<"Flight Number: "<<flightNum<<endl;
        cout<<"     Destination: "<<destination<<endl;
        /*cout<<"     Date of taking off: ";
        showDate();
        cout<<endl;*/
        cout<<"     Time of taking off: ";
        showTime();
        cout<<endl;
        cout<<"     Price: "<<price<<endl;
        cout<<"     Airline Company: "<<airlineCompany<<endl;
        cout<<"     Number of seats: "<<numberOfSeats<<endl;
        cout<<"     Crew list:"<<endl;
        showCrew();
    }
    
    //Shows the time of taking off
    void Flight::showTime() const{
        cout<<timeOfTakingOff->tm_mday<<"-"<<timeOfTakingOff->tm_mon+1<<"-"<<timeOfTakingOff->tm_year<<" ";
        cout<<timeOfTakingOff->tm_hour<<":"<<timeOfTakingOff->tm_min<<endl;
    }
    
    int positionOfColon(string str, int colonNumber){
        int counter=0;
        for(int i=0; i<str.length();i++){
            if(str[i]==':') counter++;
            if(counter==colonNumber) return i;
        }
        return 0;
    }

    void Flight::stringToTime(string str){
        timeOfTakingOff->tm_mday= stoi(str.substr(0,positionOfColon(str,1)-1));
        timeOfTakingOff->tm_mon= stoi(str.substr(positionOfColon(str,1)+1,positionOfColon(str,2)-1));
        timeOfTakingOff->tm_year= stoi(str.substr(positionOfColon(str,2)+1,positionOfColon(str,3)-1));
        timeOfTakingOff->tm_hour= stoi(str.substr(positionOfColon(str,3)+1,positionOfColon(str,4)-1));
        timeOfTakingOff->tm_hour= stoi(str.substr(positionOfColon(str,4)+1,str.length()-1));
    }

    void Flight::writeTime(Airport airport, tm* time){	//from includehelp.com
        char str[20];
        
        fstream file;
        file.open(airport.getfileName(), ios::out|ios::binary);

        if(!file){
            cout<<"Error in creating file!!!"<<endl;
            return;
        }

        //make string to write
        sprintf(str,"%02d:%02d:%04d:%02d:%02d",time->tm_mday,time->tm_mon,time->tm_year,time->tm_hour,time->tm_min);

        //write into file
        file.write(str,sizeof(str));
        cout<<"Time "<<str<<" has been written into file."<<endl;
        
        //close the file
        file.close();
    }

    //function to read time from the file
    void Flight::readTime(Airport airport, tm* time){//from includehelp.com
        char str[20];
        int inD,inMon,inY,inH,inMin;

        fstream finC;
        finC.open(airport.getfileName(),ios::in|ios::binary);
        if(!finC){
            cout<<"Error in file opening..."<<endl;
            return;
        }
        if(finC.read((char*)str,sizeof(str))){
            //extract time values from the file
            sscanf(str,"%02:%02:%04d:%02d:%02d",&inD,&inMon,&inY,&inH,&inMin);
            //assign time into variables, which are passing in function
            time->tm_mday=inD;
            time->tm_mon=inMon;
            time->tm_year=inY;
            time->tm_hour=inH;
            time->tm_min=inMin;
        }
        finC.close();	
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

    int Flight::getSizeOfTheCrew(Airport airport, string str)const{
        return (airport.numberOfAttributesInLine(str)-8);
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