//Funda Tan
//Section-01
//21801861

#include <iostream>
#include "SimpleLibrarySystem.h"
using namespace std;

//constructor
LibrarySystem::LibrarySystem(){
    head = NULL;
    noStudent = 0; //initialize properties
}

//destructor
LibrarySystem::~LibrarySystem(){
    StudentNode* cur;
    while(noStudent != 0){
        cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
        cur = NULL;
        noStudent--; //decrement no of students
    }
}

void LibrarySystem::addStudent(const int studentId, const string studentName){

    //check if there is already a student with specified id
    bool flag = true;
    for(StudentNode* cur = head; cur != NULL; cur = cur->next){
        if((cur->s).getId() == studentId){
            flag = false;
        }
    }

    //if there is no student exists with specified id
    if(flag!=false){
        StudentNode* newPtr = new StudentNode; //create new node
        (newPtr->s).setId(studentId); //set id and name
        (newPtr->s).setName(studentName);

        if(noStudent == 0){ //if it will be the first node
            newPtr->next = head;
            head = newPtr;
        }

        else{ //if it is not the first node
            StudentNode *prev = findS(noStudent);
            newPtr->next = prev->next;
            prev->next = newPtr;
        }
        noStudent++;
    }

    else
        cout << "Student " << studentId << " already exists"  << endl;
}

LibrarySystem::StudentNode* LibrarySystem::findS(int index) const{
    StudentNode *cur = head;
    for(int skip = 1; skip < index; ++skip) //traverse the linked list
        cur = cur-> next;
    return cur;
}

void LibrarySystem::deleteStudent(const int studentId){
    //check if there exist student with the specified id
    bool flag = false;
    for(StudentNode* cur = head; cur != NULL; cur = cur->next){
        if((cur->s).getId() == studentId){
            flag = true;
        }
    }

    //if there exist student with the specified id
    if(flag == true){
        int i = 0;
        int counter = 0;
        for(StudentNode* cur = head; cur != NULL; cur = cur->next){
            if((cur->s).getId() == studentId){
                counter = i; //find which node to be deleted using counter
            }
            i++;
        }

        StudentNode *cur;

        if(counter == 0){ //if it is the first node to be deleted
            cur = head;
            head = head->next;
        }

        else{ //if it is not the first node to be deleted
            StudentNode *prev = findS(counter);
            cur = prev->next;
            prev->next = cur->next;
        }

        cur->next = NULL;
        delete cur;
        cur = NULL;
        noStudent--; //decrement the number of students
    }
    else
        cout << "Student " << studentId  << " does not exist" << endl;
}

void LibrarySystem::showStudent(const int studentId) const{
    //check whether there is a student with the specified id
    bool flag = false;
    for(StudentNode* cur = head; cur != NULL; cur = cur->next){
        if((cur->s).getId() == studentId){
            flag = true;
        }
    }

    //if there is a student with the specified id
    if(flag == true){
        for(StudentNode* cur = head; cur != NULL; cur = cur->next){
            if(cur->s.getId() == studentId){ //display the student information
                cout << "Student id: " << cur->s.getId() << " student name: " << cur->s.getName() << endl;
            }
        }
    }
    else
        cout << "Student " << studentId << " does not exist" << endl;
}
