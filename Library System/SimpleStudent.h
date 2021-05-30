//Funda Tan
//Section-01
//21801861

#ifndef SIMPLESTUDENT_H
#define SIMPLESTUDENT_H
#include <string>
using namespace std;

class Student
{
    public:
        Student(const int stuId, const string stuName);
        Student();
        ~Student();
        void setId(const int stuId);
        void setName(const string stuName);
        int getId();
        string getName();
    private:
        int id;
        string name;
};

#endif // SIMPLESTUDENT_H
