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