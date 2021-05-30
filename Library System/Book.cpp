//Funda Tan
//Section-01
//21801861

#include "Book.h"

//constructor
Book::Book(){
    id = 0;
    title = "";
    year = 0;
}

//destructor
Book::~Book(){
}

//setters
void Book::setId(int bookId){
    id = bookId;
}

void Book::setTitle(string bookTitle){
    title = bookTitle;
}

void Book::setYear(int bookYear){
    year = bookYear;
}

//getters
int Book::getId(){
    return id;
}

string Book::getTitle(){
    return title;
}

int Book::getYear(){
    return year;
}
