#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Airport.h"

using namespace std;

class FileManagement{
    string fileName;
public:
    //Default Constructor
    FileManagement(string fileName):fileName(fileName){}

    //FUNCTIONS THAT MODIFY THE FILE

    //adds the string to the file
    void write(string line) const;
    //Modify the line in the file
    void modify(string line,int lineNumber);

    //FUNCTIONS THAT DO NOT MODIFY THE FILE

    //returns the line where the specified object is in the file (it should be existant)
    int lineOfObject(Airport airport, string typeOfObject,string idOfObject) const;
    //returns the type of the object in the line
    string typeOfObjectInLine(string str)const;
    //returns the type of the object in the line
    string getAttributeFromLine(string str,int orderOfTheAttribute)const;
    //returns true if the object with the given id exists in the database
    bool existant(string typeOfObject, string idOfObject)const;
    //returns true if the file contains a password line
    bool fileExists()const;
    //returns the number of objects of type "typeOfObject" in the file
    int numberOf(string typeOfObject)const;
};