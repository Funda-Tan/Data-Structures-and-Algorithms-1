//Funda Tan
//Section-01
//21801861

#ifndef SIMPLESTUDENT_H
#define SIMPLESTUDENT_H
#include <string>
using namespace std;
#include "Book.h"

class Student {

    public:
        Student(const int stuId, const string stuName);
        Student();
        ~Student();
        void setId(const int stuId);
        void setName(const string stuName);
        int getId();
        string getName();
        void addBook(const int bookId, const string bookName, const int year);
        void showBooks();
        void showBook(int id);
        void showBooksInList();
        bool have(int id);
        void returnBook(int id, string& title, int& year);
        void returnAllBooks();

    private:
        //checked out books of student
        struct StuBookNode{
            Book b;
            StuBookNode* next;
        };

        int noStuBook;
        StuBookNode* head;
        int id;
        string name;
        StuBookNode* findB(int index) const;
};

#endif // SIMPLESTUDENT_H
