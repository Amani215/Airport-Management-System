#include "fileManagement.h"

//FUNCTIONS THAT MODIFY THE FILE

//writes the string inside the file with the fileName specified in the object
void FileManagement::write(string line) const{
    //open file
    ofstream file;
    try{
        file.open(fileName,ios::app);
    }catch(...){
        cout<<"Could not open file!"<<endl;
        throw exception();
    }
    //write the line in the file
    file<<line<<endl;
    //close the file
    file.close();
}

//modifies the line "lineNumber" with the the string "line"
void FileManagement::modify(string line,int lineNumber){
    ifstream initialFile;   //initial file
    ofstream finalFile;     //resulting file with the modified line
    
    //open the initial file for reading
    try{initialFile.open(fileName);}
    catch(...){
        cout<<"Could not open file!"<<endl;
        throw exception();
    }
    //open the result file for writing
    try{finalFile.open("temp",ios::app);}
    catch(...){
        cout<<"Could not create File!"<<endl;
        throw exception();
    }
    int i=-1;   //for counting the lines
    string str; //for reading the lines
    while(getline(initialFile,str)){
        i++;    //increment the line count
        //if the lineNumber is reached write the given new line
        if(i==lineNumber){
            finalFile<<line<<endl;
        }
        //if not keep copying the rest of the lines
        else{
            finalFile<<str<<endl;
        }
    }
    //close the files
    initialFile.close();
    finalFile.close();
    //delete the old file
    remove(fileName.c_str());
    //rename the result file like the old one
    rename("temp",fileName.c_str());
}

//FUNCTIONS THAT DO NOT MODIFY THE FILE

//returns the number of the line where the object of type "typeOfObject" and ID "idOfObject"
int FileManagement::lineOfObject(string typeOfObject,string idOfObject) const{
    //open the file
    ifstream file;
    try{file.open(fileName);}
    catch(...){
        cout<<"Could not open file!"<<endl;
        throw exception();
    }
    //read the file until th eobject is found
    int counter=-1;
    string str;
    while(getline(file,str)){
        counter++;
        //if the object is found stop counting
        if((typeOfObjectInLine(str)==typeOfObject)&&(getAttributeFromLine(str,1)==idOfObject)){
            break;
        }
    }
    //close the file
    file.close();
    //return the number of the line
    return counter;
}

//returns the value of the attribute according to the given position
string FileManagement::getAttributeFromLine(string str,int orderOfTheAttribute)const{
    char attribute[50]="";
    int j=0, i=0;
    //count the number of commas until orderOfTheAttribute is reached
    do{
        while (str[i]!=','){
            i++;
        }
        j++;
        i++;
    }while (j<orderOfTheAttribute);
    //copy the read attribute in the resulting string
    j=0;
    while ((str[i]!=',')){
        attribute[j]=str[i];
        j++;
        i++;
    }
    //add the terminating character
    attribute[j]='\0';
    //return the resulting string
    return attribute;
}

//returns the type of the object in the line
string FileManagement::typeOfObjectInLine(string str)const{
    char temp[10]="";
    int i=0;
    //keep copying characters inside the resulting string until the first comma is reached
    while (str[i]!=','){
        temp[i]=str[i];
        i++;
    }
    //add the terminating character
    temp[i]='\0';
    //return the resulting string
    return temp;
}

//returns true if the flight with the given number exists in the database
bool FileManagement::existant(string typeOfObject, string idOfObject)const{
    //open the file for reading
    ifstream file;
    try{file.open(fileName);}
    catch(...){
        cout<<"Could not open file"<<endl;
        throw exception();
    }
    //read the file
    string str;
    while (getline(file, str)){
        //if the object is found close file and return true
        if((typeOfObjectInLine(str)==typeOfObject)&&(getAttributeFromLine(str,1)==idOfObject)){
            file.close();
            return true;
        }
    }
    //if the object is not found an dthe end of the file is reached close the file and return false
    file.close();
    return false;
}

//file exists if there is a line where the password is written
bool FileManagement::fileExists()const{
    //open file for reading
    ifstream file;
    try{file.open(fileName);}
    catch(...){
        cout<<"Could not open file!"<<endl;
        throw exception();
    }
    //read the file
    string str;
    while(getline(file,str)){
        //if password is found inside the file then close the file and return true
        if(typeOfObjectInLine(str)=="password"){
            file.close();
            return true;
        }
    }
    //if the password is not found then the file is new: close the file and return false
    file.close();
    return false;
}

//returns the number of objects of type "typeOfObject" inside the file
int FileManagement::numberOf(string typeOfObject)const{
    int counter=0;
    //open file for reading
    ifstream file;
    try{file.open(fileName);}
    catch(...){
        cout<<"Could not open file!";
        throw exception();
    }
    //count lines of objects
    string str;
    while (getline(file,str)){
        //if an object of suitable type is found increment the counter
        if(typeOfObjectInLine(str)==typeOfObject){
            counter++;
        }
    }
    //close the file
    file.close();
    //return the number
    return counter;
}