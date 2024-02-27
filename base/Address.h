#ifndef ADDRESS_H
#define ADDRESS_H
#include<string>
#include<iostream>
using namespace std;

class Address{
    string address1; //to store address line 1;
    string address2; //to store address line 2
    string city; //to stoer city 
    string state;//to store state
    int zipcode; //to store zip code


    public:
        Address(); //default constructor
        Address(int,string,string,string,string); //parametrized constructor
        //all getter
        int getZipCode(); 
        string getAddress1();
        string getAddress2();
        string getCity();
        string getState();
        //all setter
        void setZipCode(int);
        void setAddress1(string);
        void setAddress2(string);
        void setCity(string);
        void setState(string);

        void print();
        //destructor
        ~Address();


        

        
};

#endif