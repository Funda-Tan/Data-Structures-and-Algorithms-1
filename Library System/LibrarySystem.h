//Funda Tan
//Section-01
//21801861

using namespace std;
#ifndef SIMPLELIBRARYSYSTEM_H
#define SIMPLELIBRARYSYSTEM_H
#include "Student.h"
#include <string>

class LibrarySystem
{

public:
    LibrarySystem();
    ~LibrarySystem();

    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);

    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);

    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);

    void showAllBooks() const;
    void showBook(const int bookId) const;
    void showStudent(const int studentId) const;

    void putReturnedBook(const int bookId, const string bookName, const int bookYear);

private:
    //student node
    struct StudentNode
    {
        Student s;
        StudentNode* next;
    };

    int noStudent;
    StudentNode* head;
    StudentNode* findS(int index) const;

    //book not checked out node
    struct BookNode
    {
        Book b;
        BookNode* next2;
    };

    int noBook;
    BookNode* headBook;
    BookNode* findB(int index) const;

    //checked out book node
    struct CBookNode
    {
        Book b;
        Student s;
        CBookNode* next3;
    };

    int noCBook;
    CBookNode* headCBook;
    CBookNode* findC(int index) const;
};

#endif // SIMPLELIBRARYSYSTEM_H
