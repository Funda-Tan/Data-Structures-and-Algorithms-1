//Funda Tan
//Section-01
//21801861

#include "Student.h"
#include <iostream>

//constructors
Student::Student(const int stuId, const string stuName){
    id = stuId;
    name = stuName;
    head = NULL;
    noStuBook = 0;
}

Student::Student(){
    id = 0;
    name = "";
    head = NULL;
    noStuBook = 0;
}

//destructor
Student::~Student(){
    StuBookNode* cur;
    while(noStuBook != 0){
        cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
        cur = NULL;
        noStuBook--; //decrement no of student books
    }
}

//set methods
void Student::setId(const int stuId){
    id = stuId;
}

void Student::setName(const string stuName){
    name = stuName;
}

//get methods
int Student::getId(){
    return id;
}

string Student::getName(){
    return name;
}

//list method find
Student::StuBookNode* Student::findB(int index) const{
    StuBookNode *cur = head;
    for(int skip = 1; skip < index; ++skip) //traverse the linked list
        cur = cur-> next;
    return cur;
}

//user wants to add a book to LS
void Student::addBook(const int bookId, const string bookName, const int bookYear){
    bool flag = false;
    for(StuBookNode* cur = head; cur != NULL; cur = cur->next){
            if(cur->b.getId()==bookId)
                flag = true; //book exists
    }

    if(flag == false){ //book does not exist
        StuBookNode* newPtr = new StuBookNode; //create new node
        (newPtr->b).setId(bookId); //set properties
        (newPtr->b).setTitle(bookName);
        (newPtr->b).setYear(bookYear);

        if(noStuBook == 0){ //if it will be the first node
            newPtr->next = head;
            head = newPtr;

        }

        else{ //if it will not be the first node
            StuBookNode *prev = findB(noStuBook);
            newPtr->next = prev->next;
            prev->next = newPtr;
        }

        noStuBook++; //increment counter
    }

    else
        cout << "Book " << bookId << " already exists"  << endl;
}

void Student::showBooks(){
    if(noStuBook > 0){
    cout << "Student " << id << " has checked out the following books: " << endl;
    cout << "Book id       Book name                Year" << endl;
        //traverse student list
        for(StuBookNode* cur = head; cur != NULL; cur = cur->next){
                int space = 25 - (cur->b.getTitle()).length();
                cout << cur->b.getId() << "          " << cur->b.getTitle();
                for(int i = 0; i < space; i++)
                    cout << " ";
                cout << cur->b.getYear() << endl;
        }
    }

    //if student does not have any book
    else
        cout << "Student has no books" << endl;
}

void Student::showBooksInList(){
    //if there is any book then display
    if(noStuBook > 0){
        for(StuBookNode* cur = head; cur != NULL; cur = cur->next){
                int space = 25 - (cur->b.getTitle()).length();
                cout << cur->b.getId() << "          " << cur->b.getTitle();
                for(int i = 0; i < space; i++)
                    cout << " ";
                cout << cur->b.getYear() << "     " << "Checked out by student " << id << endl;
        }
    }
}

//show a specified book of a student with specified id
void Student::showBook(int bookId){
    for(StuBookNode* cur = head; cur != NULL; cur = cur->next){ //find which node it is
            if(cur->b.getId() == bookId){
                int space = 25 - (cur->b.getTitle()).length();
                cout << cur->b.getId() << "          " << cur->b.getTitle();
                for(int i = 0; i < space; i++)
                    cout << " ";
                cout << cur->b.getYear() <<  "     Checked out by student " << id << endl;
            }
    }
}

//check whether the student has the specified book
bool Student::have(int id){
    bool flag = false;
    //traverse student book list
    for(StuBookNode* cur = head; cur != NULL; cur = cur->next){
            if(cur->b.getId() == id)
                flag = true; //student has it
    }

    return flag; //student does not have it
}

void Student::returnBook(int id, string& title, int& year){
    for(StuBookNode* cur = head; cur != NULL; cur = cur->next){
        //collect title and year
        if(cur->b.getId() == id){
            title = (cur->b).getTitle();
            year = (cur->b).getYear();
        }
    }

    //remove it from student's book inventory
    int i = 0;
    int counter = 0;
    for(StuBookNode* cur = head; cur != NULL; cur = cur->next){
        if((cur->b).getId() == id){
            counter = i; //find which node to be deleted using counter
        }
        i++;
    }

    StuBookNode *cur;

    if(counter == 0){ //if it is the first node to be deleted
        cur = head;
        head = head->next;
    }

    else{ //if it is not the first node to be deleted
        StuBookNode *prev = findB(counter);
        cur = prev->next;
        prev->next = cur->next;
    }

    cur->next = NULL;
    delete cur;
    cur = NULL;
    noStuBook--; //decrement the number of students
}

void Student::returnAllBooks(){
    //return all books which student checked out
    for(StuBookNode* cur = head; cur != NULL; cur = cur->next){
            int id = (cur->b).getId();
            string title = (cur->b).getTitle();
            int year = (cur->b).getYear();
            returnBook(id, title, year);
            noStuBook--;
    }
}
