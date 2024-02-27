#include "Student.h"


Student::Student(){
    setFirstName("\0");
    setSecondName("\0");
    this->dob = nullptr;
    this->dog = nullptr;
    setGPA(0.0);
    setCCH(0);
    this->address  = nullptr;
}
Student::Student(string fName,string sName,Address* a,Date* dob,Date* dog,float g,int c){
    setFirstName(fName);
    setSecondName(sName);
    setDOB(dob);
    setDOG(dog);
    setGPA(g);
    setCCH(c);
    setAddress(a);
}
void Student:: setFirstName(string fname){
    this->fName = fname;    
}
void Student::setSecondName(string sName){
    this->sName = sName;
}
void Student:: setAddress(Address* a){
    address = a;
}
void Student::setDOB(Date* d){
    dob = d;
}
void Student::setDOG(Date* d){
    dog = d;
}
void Student::setGPA(float g){
    this->gpa = g;
}
void Student::setCCH(int c){
    this->cch = c;
}

int Student::getCCH(){
    return this->cch;
}
float Student::getGPA(){
    return this->gpa;
}
Date* Student::getDOB(){
    return this->dob;
}
Date* Student::getDOG(){
    return this->dog;
}
Address* Student::getAddress(){
    return this->address;
}
string Student::getFirstName(){
    return this->fName;
}
string Student::getSecondName(){
    return this->sName;
}
Student::~Student(){
        MakeNull();
}


Student& Student::operator=(Student& o){

    if(this == &o) return *this; 
    MakeNull();
    setFirstName(o.fName);
    setSecondName(o.sName);
    setDOB(o.dob);
    setDOG(o.dog);
    setGPA(o.gpa);
    setCCH(o.cch);
    setAddress(o.address);
    return *this;
}


Student::Student(Student& o){
    if(this == &o) return;

    setFirstName(o.fName);
    setSecondName(o.sName);
    setDOB(o.dob);
    setDOG(o.dog);
    setGPA(o.gpa);
    setCCH(o.cch);
    setAddress(o.address);
}

void Student:: print(){
    cout<<fName<<","<<sName<<","<<address->getAddress1()<<","<<address->getAddress2()<<","
    <<address->getCity()<<","<<address->getState()<<","<<address->getZipCode()<<","
    <<dob->getDay()<<"/"<<dob->getMonth()<<"/"<<dob->getYear()<<","
    <<dog->getDay()<<"/"<<dog->getMonth()<<"/"<<dog->getYear()<<","
    <<gpa<<","<<cch<<endl;
}

void Student:: MakeNull(){
    if(this!=nullptr)
    { 
        if(this->dob) delete this->dob;
        if(this->dog) delete this->dog;
        if(this->address) delete this->address;  
    }
}


