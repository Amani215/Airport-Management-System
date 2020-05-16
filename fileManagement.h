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
};