#include "Address.h"


Address::Address(){
    setZipCode(0);
    setAddress1("\0");
    setAddress2("\0");
    setCity("\0");
    setState("\0");
}
Address::Address(int zipcode,string city,string state,string address1,string address2){
    setZipCode(zipcode);
    setAddress1(address1);
    setAddress2(address2);
    setCity(city);
    setState(state);
}
int Address::getZipCode(){
    return zipcode;
}
string Address::getAddress1(){
    return address1;
}
string Address::getAddress2(){
    return address2;
}
string Address::getCity(){
    return city;
}
string Address::getState(){
    return state;
}
void Address:: setZipCode(int zipcode){
    this->zipcode = zipcode;
}
void Address::setAddress1(string address1){
  // this->address1 = address1;

    this->address1 = address1;
}
void Address::setAddress2(string address2){
    this->address2 = address2;
}void Address::setCity(string city){
    this->city = city;
}void Address::setState(string state){
    this->state = state;
}

void Address::print(){
    cout<<city<<","<<address1<<","<<address2<<","<<state<<","<<zipcode<<endl;
}

Address::~Address(){
}