#include "fileManagement.h"

void FileManagement::write(string line) const{
    ofstream file;
    try{
        file.open(fileName,ios::app);
    }catch(...){
        cout<<"Could not open file!"<<endl;
        throw exception();
    }
    file<<line<<endl;
    file.close();
}

void FileManagement::modify(string line,int lineNumber){
    ifstream initialFile;
    ofstream finalFile;
    
    try{initialFile.open(fileName);}
    catch(...){
        cout<<"Could not open file!"<<endl;
        throw exception();
    }
    try{finalFile.open("temp",ios::app);}
    catch(...){
        cout<<"Could not create File!"<<endl;
        throw exception();
    }
    int i=-1;
    string str;
    while(getline(initialFile,str)){
        i++;
        if(i==lineNumber){
            finalFile<<line<<endl;
        }
        else{
            finalFile<<str<<endl;
        }
    }
    initialFile.close();
    finalFile.close();
    remove(fileName.c_str());
    rename("temp",fileName.c_str());
}

int FileManagement::lineOfObject(Airport airport, string typeOfObject,string idOfObject) const{
    ifstream file;
    string str;
    try{file.open(airport.getfileName());}
    catch(...){
        cout<<"Could not open file!"<<endl;
        throw exception();
    }
    int counter=-1;
    while(getline(file,str)){
        counter++;
        if((airport.typeOfObjectInLine(str)==typeOfObject)&&(airport.getAttributeFromLine(str,1)==idOfObject)){
            break;
        }
    }
    file.close();
    return counter;
}

//returns the value of the attribute according to the given position
string FileManagement::getAttributeFromLine(string str,int orderOfTheAttribute)const{
    char attribute[50]="";
    int j=0, i=0;
    do{
        while (str[i]!=','){
            i++;
        }
        j++;
        i++;
    }while (j<orderOfTheAttribute);
    j=0;
    while ((str[i]!=',')){
        attribute[j]=str[i];
        j++;
        i++;
    }
    attribute[j]='\0';
    return attribute;
}

//returns the type of the object in the line
string FileManagement::typeOfObjectInLine(string str)const{
    char temp[10]="";
    int i=0;
    while (str[i]!=','){
        temp[i]=str[i];
        i++;
    }
    temp[i]='\0';
    return temp;
}

//returns true if the flight with the given number exists in the database
bool FileManagement::existant(string typeOfObject, string idOfObject)const{
    ifstream file;
    try{file.open(fileName);}
    catch(...){
        cout<<"Could not open file"<<endl;
        throw exception();
    }

    string str;
    while (getline(file, str)){
        if((typeOfObjectInLine(str)==typeOfObject)&&(getAttributeFromLine(str,1)==idOfObject)){
            file.close();
            return true;
        }
    }
    return false;
}

//file exists if there is a line where the password is written
bool FileManagement::fileExists()const{
    ifstream file;
    try{file.open(fileName);}
    catch(...){
        cout<<"Could not open file!"<<endl;
        throw exception();
    }
    string str;
    while(getline(file,str)){
        if(typeOfObjectInLine(str)=="password") return true;
    }
    return false;
}

int FileManagement::numberOf(string typeOfObject)const{
    string str;
    int counter=0;
    //open file for reading
    ifstream file;
    try{file.open(fileName);}
    catch(...){
        cout<<"Could not open file!";
        throw exception();
    }
    //count lines of employees
    while (getline(file,str)){
        if(typeOfObjectInLine(str)==typeOfObject){
            counter++;
        }
    }
    //return the number
    return counter;
}