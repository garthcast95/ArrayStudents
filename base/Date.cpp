#include "Date.h"
#include<iostream>
using namespace std;


Date::Date(int d,int m,int y){
    setDay(d);
    setMonth(m);
    setYear(y);
}
Date:: Date(){
    day = 0;
    month = 0;
    year = 0;
}

void Date::setDay(int d){
    this->day = d;
}


void Date::setMonth(int m){
    this->month = m;
}
void Date::setYear(int y){
    this->year = y;
}

int Date::getDay(){return this->day;}

int Date::getMonth(){return this->month;}

int Date::getYear(){return this->year;}


bool Date::operator== (Date& d1){
    if( this->day == d1.getDay() &&
    this->month == d1.getMonth() &&
    this->year == d1.getYear() ){
        return true;
    }
    return false;
}





void Date::print(){
    cout<<day<<"/"<<month<<"/"<<year;
}
Date::~Date(){
}
