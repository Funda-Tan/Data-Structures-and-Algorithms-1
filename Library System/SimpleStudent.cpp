//Funda Tan
//Section-01
//21801861

#include "SimpleStudent.h"

//constructors
Student::Student( const int stuId, const string stuName){
    id = stuId;
    name = stuName;
}

Student::Student(){
    id = 0;
    name = "";
}

//set methods
void Student::setId( const int stuId){
    id = stuId;
}

void Student::setName( const string stuName){
    name = stuName;
}

//get methods
int Student::getId(){
    return id;
}

string Student::getName(){
    return name;
}

Student::~Student(){
}
