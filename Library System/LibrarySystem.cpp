//Funda Tan
//Section-01
//21801861

#include <iostream>
#include "LibrarySystem.h"
#include "Student.h"
using namespace std;

//constructor
LibrarySystem::LibrarySystem(){
    head = NULL;
    headBook = NULL;
    headCBook = NULL;
    noStudent = 0; //initialize properties
    noBook = 0;
    noCBook = 0;
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

    BookNode* cur2;
    while(noBook != 0){
        cur2 = headBook;
        headBook = headBook->next2;
        cur2->next2 = NULL;
        delete cur;
        cur2 = NULL;
        noBook--; //decrement no of students
    }

    CBookNode* cur3;
    while(noCBook != 0){
        cur3 = headCBook;
        headCBook = headCBook->next3;
        cur3->next3 = NULL;
        delete cur3;
        cur3 = NULL;
        noCBook--; //decrement no of students
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
        cout << "Student " << studentId << " has been added" << endl;
    }

    else
        cout << "Student " << studentId << " already exists" << endl;
}

//find method for list
LibrarySystem::StudentNode* LibrarySystem::findS(int index) const{
    StudentNode *cur = head;
    for(int skip = 1; skip < index; ++skip) //traverse the linked list
        cur = cur-> next;
    return cur;
}

//find method for list
LibrarySystem::BookNode* LibrarySystem::findB(int index) const{
    BookNode *cur = headBook;
    for(int skip = 1; skip < index; ++skip) //traverse the linked list
        cur = cur-> next2;
    return cur;
}

//find method for list
LibrarySystem::CBookNode* LibrarySystem::findC(int index) const{
    CBookNode *cur = headCBook;
    for(int skip = 1; skip < index; ++skip) //traverse the linked list
        cur = cur-> next3;
    return cur;
}

void LibrarySystem::deleteStudent(const int studentId){
    bool flag = false;
    int i = 0;
    int counter = 0;

    //return books of the student will be deleted
    for(CBookNode* cur = headCBook; cur != NULL; cur = cur->next3){
        if((cur->s).getId() == studentId){
            cout << "Book " << cur->b.getId()  << " has been returned" << endl;
            putReturnedBook(cur->b.getId(),cur->b.getTitle(),cur->b.getYear());
            flag = true;
        }
        i++;
    }

    //if there is books that returned. also remove it to checked out list
    if(flag == true){
        CBookNode *cur;

        if(counter == 0){ //if it is the first node to be deleted
            cur = headCBook;
            headCBook = headCBook->next3;
        }

        else{ //if it is not the first node to be deleted
            CBookNode *prev = findC(counter);
            cur = prev->next3;
            prev->next3 = cur->next3;
        }

        cur->next3 = NULL;
        delete cur;
        cur = NULL;
        noCBook--; //decrement the number of books checked out
    }

    //check if there exist student with the specified id
    bool flag1 = false;
    for(StudentNode* cur = head; cur != NULL; cur = cur->next){
        if((cur->s).getId() == studentId){
            flag1 = true;
        }
    }

    //if there exist student with the specified id
    if(flag1 == true){
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
        cout << "Student " << studentId  << " has been deleted" << endl;
    }

    //if the student with the specified id does not exist
    else
        cout << "Student " << studentId  << " does not exist" << endl;
}

void LibrarySystem::deleteBook(const int bookId){
    bool flagCheck = false;
    for(BookNode* cur = headBook; cur != NULL; cur = cur->next2){
        if((cur->b).getId() == bookId){
            flagCheck = true; //if the book is not checked out
        }
    }

    bool flag = true;
    for(StudentNode* cur = head; cur != NULL; cur = cur->next){
        if((cur->s).have(bookId) == true){ //find if any student has the book
            flag = false;
            string title = "";
            int year = 0;
            (cur->s).returnBook(bookId, title, year);
            putReturnedBook(bookId, title, year); //if so, return it to LS
            flagCheck = true;
            cout << "Book " << bookId << " has been returned" << endl;
        }
    }


    if(flagCheck == true || flag == false){ //the book exist
        if(flag == true) //if the book is not checked out
            cout << "Book " << bookId << " has not been checked out" << endl;

        int i = 0;
        int counter = 0;
        for(BookNode* cur = headBook; cur != NULL; cur = cur->next2){
            if((cur->b).getId() == bookId){
                counter = i; //find which node to be deleted using counter
            }
            i++;
        }

        BookNode *cur;

        if(counter == 0){ //if it is the first node to be deleted
            cur = headBook;
            headBook = headBook->next2;
        }

        else{ //if it is not the first node to be deleted
            BookNode *prev = findB(counter);
            cur = prev->next2;
            prev->next2 = cur->next2;
        }

        cur->next2 = NULL;
        delete cur;
        cur = NULL;
        noBook--; //decrement the number of students
        cout << "Book " << bookId << " has been deleted" << endl;
    }

    else
        cout << "Book " << bookId << " does not exist" << endl;
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
                (cur->s).showBooks();
            }
        }
    }

    else //if student with specified id does not exist
        cout << "Student " << studentId << " does not exist" << endl;
}

void LibrarySystem::showBook(const int bookId) const{
    bool flag = false;
    //if the book is not checked out
    for(BookNode* cur = headBook; cur != NULL; cur = cur->next2){
        if((cur->b).getId() == bookId){
            flag = true;
            int space = 25 - (cur->b.getTitle()).length();
            cout << cur->b.getId() << "          " << cur->b.getTitle();
            for(int i = 0; i < space; i++)
                cout << " ";
            cout << cur->b.getYear() << "     " << "Not checked out" << endl;
        }
    }

    //if any student has that book
    if(flag == false){
        for(StudentNode* cur = head; cur != NULL; cur = cur->next){
            if(cur->s.have(bookId) == true){ //display the student information
                cur->s.showBook(bookId);
            }
        }
    }
}

void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear){
    bool flag = true;
    for(BookNode* cur = headBook; cur != NULL; cur = cur->next2){
        if((cur->b).getId() == bookId){
            flag = false; //a book exists with specified id
        }
    }

    //if there is no book exists with specified id
    if(flag != false){
        BookNode* newPtr = new BookNode; //create new node
        (newPtr->b).setId(bookId); //set properties
        (newPtr->b).setTitle(bookName);
        (newPtr->b).setYear(bookYear);

        if(noBook == 0){ //if it will be the first node
            newPtr->next2 = headBook;
            headBook = newPtr;
        }

        else{ //if it is not the first node
            BookNode *prev = findB(noBook);
            newPtr->next2 = prev->next2;
            prev->next2 = newPtr;
        }
        noBook++;

        cout << "Book " << bookId << " has been added" << endl;
    }
    else
        cout<< "Book " << bookId << " already exists" << endl;
}

void LibrarySystem::putReturnedBook(const int bookId, const string bookName, const int bookYear){
    //check whether there is a book with specified id
    bool flag = true;
    for(BookNode* cur = headBook; cur != NULL; cur = cur->next2){
        if((cur->b).getId() == bookId){
            flag = false;
        }
    }

    //if there is no book exists with specified id
    if(flag!= false){
        BookNode* newPtr = new BookNode; //create new node
        (newPtr->b).setId(bookId); //set id and name
        (newPtr->b).setTitle(bookName);
        (newPtr->b).setYear(bookYear);

        if(noBook == 0){ //if it will be the first node
            newPtr->next2 = headBook;
            headBook = newPtr;
        }

        else{ //if it is not the first node
            BookNode *prev = findB(noBook);
            newPtr->next2 = prev->next2;
            prev->next2 = newPtr;
        }
        noBook++;
    }
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId){
    CBookNode* newPtr = new CBookNode; //create new node
    (newPtr->b).setId(bookId); //set book id and student id
    (newPtr->s).setId(studentId);

    for(BookNode* cur = headBook; cur != NULL; cur = cur->next2){
        if((cur->b).getId() == bookId){
            (newPtr->b).setTitle(cur->b.getTitle());
            (newPtr->b).setYear(cur->b.getYear());
        }
    }

    if(noCBook == 0){ //if it will be the first node
        newPtr->next3 = headCBook;
        headCBook = newPtr;
    }

    else{ //if it is not the first node
        CBookNode *prev = findC(noCBook);
        newPtr->next3 = prev->next3;
        prev->next3 = newPtr;
    }
    noCBook++;

    //book does not exist
    bool flagBook = false;
    for(BookNode* cur = headBook; cur != NULL; cur = cur->next2){
        if((cur->b).getId() == bookId){
            flagBook = true;
        }
    }

    bool checked = false;
    for(StudentNode* cur = head; cur != NULL; cur = cur->next){
        if((cur->s).have(bookId) == true){
            flagBook = true;
            checked = true;

        }
    }

    //if the book is checked out
    if(checked == true)
    cout << "Book "<< bookId << " has been already checked out by another student" << endl;

    else{
        if(flagBook == false) //book does not exist
            cout << "Book "<< bookId << " does not exist for checkout" << endl;

        else{ //book exits
            bool flagStu = false;
            //traverse student list
            for(StudentNode* cur = head; cur != NULL; cur = cur->next){
                if((cur->s).getId() == studentId){
                    flagStu = true;
                }
            }

            if(flagStu == false) //if student with specified id does not exist
                cout << "Student " << studentId << " does not exist for checkout" << endl;

            else{ //student with specified id exist
                for(StudentNode* cur = head; cur != NULL; cur = cur->next){
                    if((cur->s).getId() == studentId){ //find which student is it
                        for(BookNode* cur2 = headBook; cur2 != NULL; cur2 = cur2->next2){
                            if((cur2->b).getId() == bookId){
                                (cur->s).addBook(bookId, (cur2->b).getTitle(),(cur2->b).getYear());
                                cout << "Book " << bookId << " has been checked out by student " << studentId << endl;
                            }
                        }
                    }
                }

                int i = 0;
                int counter = 0;

                for(BookNode* cur = headBook; cur != NULL; cur = cur->next2){
                    if((cur->b).getId() == bookId){
                        counter = i; //find which node to be deleted using counter
                    }
                    i++;
                }

                BookNode *cur;

                if(counter == 0){ //if it is the first node to be deleted
                    cur = headBook;
                    headBook = headBook->next2;
                }

                else{ //if it is not the first node to be deleted
                    BookNode *prev = findB(counter);
                    cur = prev->next2;
                    prev->next2 = cur->next2;
                }

                cur->next2 = NULL;
                delete cur;
                cur = NULL;
                noBook--; //decrement the number of students

            }
        }
    }
}

void LibrarySystem::returnBook(const int bookId){
        string title ="";
        int year = 0;
        bool checked =false;

        //find if the book is checked out or not
        for(StudentNode* cur = head; cur != NULL; cur = cur->next){
            if((cur->s).have(bookId) == true){
                checked = true;
                (cur->s).returnBook(bookId, title, year);
                putReturnedBook(bookId, title, year);
            }
        }

        //not checked out
        if(checked == false){
            cout << "Book " << bookId << " has not been checked out" << endl;
        }

        //returned
        else
            cout << "Book " << bookId << " has been returned" << endl;
}

void LibrarySystem::showAllBooks() const{
    //show all books in a template
    cout << "Book id       Book name                Year     Status" << endl;
    //not checked out books
    for(BookNode* cur = headBook; cur != NULL; cur = cur->next2){
        int space = 25 - (cur->b.getTitle()).length();
        cout << cur->b.getId() << "          " << cur->b.getTitle();
        for(int i = 0; i < space; i++)
            cout << " ";
        cout << cur->b.getYear() << "     " << "Not checked out" << endl;
    }

    //checked out books
    for(StudentNode* cur = head; cur != NULL; cur = cur->next){
        (cur->s).showBooksInList();
    }
}
