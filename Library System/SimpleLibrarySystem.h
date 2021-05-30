//Funda Tan
//Section-01
//21801861

#ifndef SIMPLELIBRARYSYSTEM_H
#define SIMPLELIBRARYSYSTEM_H
#include <string>
#include "SimpleStudent.h"
using namespace std;

class LibrarySystem {

    public:
    LibrarySystem();
    ~LibrarySystem();

    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);

    void showStudent(const int studentId) const;


    private:
        //for node
        struct StudentNode{
            Student s;
            StudentNode* next;
        };

        int noStudent;
        StudentNode* head;
        StudentNode* findS(int index) const;
};

#endif // SIMPLELIBRARYSYSTEM_H
