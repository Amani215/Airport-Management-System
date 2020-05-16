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

    //adds the string to the file
    void write(string line) const;

    //Modify the line in the file
    void modify(string line,int lineNumber);

    //returns the line where the specified object is in the file (it should be existant)
    int lineOfObject(Airport airport, string typeOfObject,string idOfObject) const;
    //returns the type of the object in the line
    string typeOfObjectInLine(string str)const;
    //returns the type of the object in the line
    string getAttributeFromLine(string str,int orderOfTheAttribute)const;
    //returns true if the object with the given id exists in the database
    bool existant(string typeOfObject, string idOfObject)const;

    bool fileExists()const;

    int numberOf(string typeOfObject)const;
};