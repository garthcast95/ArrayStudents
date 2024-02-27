#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<iostream>
#include "Address.h"
#include "Date.h"
using namespace std;


class Student
{
private:
    string fName;  //first name
    string sName;  //last name

    Address* address; //pointer to store address of student
    Date* dob;// data of birsth
    Date* dog; // graduation date
    float gpa; // gpa of student

    int cch; //completed credit hours

    void MakeNull(); //this function will return dynamically allocated memory
   
public:
    Student(); //default constructor
    Student(Student&); //copy constructor
    Student(string,string,Address*,Date*,Date*,float,int); //parametrized constructor
    //setter for setting the argument
    void setFirstName(string);
    void setSecondName(string);
    void setAddress(Address*);
    void setDOB(Date*);
    void setDOG(Date*);
    void setGPA(float);
    void setCCH(int);

    //getter for getting the variable

    int getCCH();
    float getGPA();
    Date* getDOB();
    Date* getDOG();
    Address* getAddress();
    string getFirstName();
    string getSecondName();
    //distructor
    ~Student();



    //overload equal operator so we can dynamically assign heap memory
    Student& operator =(Student&);
    void print();//function to print student
};

#endif