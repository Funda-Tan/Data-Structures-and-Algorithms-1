//Funda Tan
//Section-01
//21801861

#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class Book {
    public:
        Book();
        ~Book();
        void setId(int id);
        void setTitle(string title);
        void setYear(int year);
        int getId();
        string getTitle();
        int getYear();
        int getStatus();
        void changeStatus();

    private:
        int id;
        string title;
        int year;
        int status;
};

#endif // BOOK_H
