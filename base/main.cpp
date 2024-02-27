#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include "Address.h"
#include "Student.h"
using namespace std;
//A function take string format date (DD/MM/YYYY)  as input and return in Date class
Date stringToDate(string date){

    stringstream ss (date);
    string integer;
    int i = 0,day,month,year;
    while(getline(ss,integer,'/')){
        stringstream s1(integer);
        if(i==0) s1>>day;
        else if(i==1) s1>>month;
        else if(i==2) s1 >> year;
        s1.clear();
        integer.clear();
        i++;
    }
    return Date(day,month,year);

};
//Create the shortReport
void generateShortReport(Student**& s,int size){

    ofstream myfile;
    myfile.open("shortReport.txt");
    myfile<<"Surname,GivenName\n";
    for(int i=0;i<size;++i){
        myfile<<s[i]->getSecondName()<<","
            <<s[i]->getFirstName()<<"\n";
    }
    myfile.close();
}

//Function and create whole data
void generateReport(Student**& s,int size,string name){
    ofstream myfile;
    myfile.open(name);
    myfile<<"Surname,GivenName,StreetAddress,Address2,City,State,ZipCode,Birthday,Graduation,GPA,Credit Hours Complete\n";
    for (int i = 0; i < size; i++)
    {
        myfile<<s[i]->getSecondName()<<","
            <<s[i]->getFirstName()<<","
            <<s[i]->getAddress()->getAddress1()<<","
            <<s[i]->getAddress()->getAddress2()<<","
            <<s[i]->getAddress()->getCity()<<","
            <<s[i]->getAddress()->getState()<<","
            <<s[i]->getAddress()->getZipCode()<<","
            <<s[i]->getDOB()->getDay()<<"/"<<s[i]->getDOB()->getMonth()<<"/"<<s[i]->getDOB()->getYear()<<","
            <<s[i]->getDOG()->getDay()<<"/"<<s[i]->getDOG()->getMonth()<<"/"<<s[i]->getDOG()->getYear()<<","
            <<s[i]->getGPA()<<","
            <<s[i]->getCCH()<<"\n";
    }
    myfile.close();

}

// A utility function to swap two students in the pointer array of student
void swap(Student*& one, Student*& two){
    Student* temp = one;
    one = two;
    two = temp;
}

//Function to short Student array
//SORT WITH SECOND NAME
void bubbleSort(Student** arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    //outer loop pick one student and correct it position
        for (j = 0; j < n-i-1; j++){
            if ((*arr[j]).getSecondName() > (*arr[j+1]).getSecondName())  {
                    swap(arr[j], arr[j+1]);
        }
    }
}
//This function with increase the size of student array

int extendArray(Student**& s,int size){
    Student** sList = new Student*[2*size];

    for(int i=0;i<size;++i){
        sList[i] = s[i];
        s[i] = nullptr;
    }
    delete s;
    s = sList;
    return size*2;
}



int main(int argc, char const *argv[])
{
    int size = 25;
    Student** sList = new Student*[size]; //create  a student array
    fstream fin;                          //fstream to read the file
    fin.open("students.dat",ios::in);     //open data file
    string line,temp;
    int i=0;
    while(getline(fin,line,'\n')){  //loop tile end of file
        if (i!=0){
            istringstream s(line); //create a string stream to split the single line on the basis of comma
            int count =0;
            string word = "\0";
            word.clear();
            int j=0;
            string fName,sName,sA1,sA2,city,state;
            int zipcode,cch;
            Date dob,dog;
            float gpa;
            //Use Getline for each student
            while(getline(s,word,',')){ //loop until all word has been read.
                if(j==0){ //to read surname
                    sName = word;
                }else if(j==1){ //to read first name
                    fName = word;
                }else if(j==2){
                    sA1  = word; ////to read address line one
                }
                else if(j==3){ //to read address line two
                    sA2  = word;
                }
                else if(j==4){ //to read city name
                    city  = word;
                }
                else if(j==5){ // to read state name
                    state  = word;
                }else if(j==6){ //to read zipcode
                    stringstream ss(word); //create string stream because zipcode is integer
                    ss>>zipcode;
                }else if(j==7){
                    dob = stringToDate(word); // convert date in string format into Date format
                }else if(j==8){
                    dog = stringToDate(word); // convert date in string format into Date format
                }
                else if(j==9){

                    gpa = stof(word); //to convert string gpa to float gpa

                }

                else if(j==10){
                    stringstream ss(word); //create string stream because credit hour is integer
                    ss>>cch;
                }

                j++;
            }
            if(i==size){
                size = extendArray(sList,size); //dynamically increase size of array
            }
            //store the student
            sList[i-1] = new Student(sName,fName,new Address(zipcode,city,state,sA1,sA2),new Date(dob),new Date(dog),gpa,cch);
        }
        ++i;
    }
    fin.close();//close file after reading all data
    //call function to generate full report
    generateReport(sList,i-1,"fullReport.txt");
    //call function to generate short report
    generateShortReport(sList,i-1);
    //short the student array using bubble sort to print alpha report
    bubbleSort(sList,i-1);
    generateReport(sList,i-1,"alphaReport.txt");


    //Free Memory
    for(int j=0;j<i-1;++j){
        delete sList[j];
    }
    delete [] sList;
    return 0;
}
