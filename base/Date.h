#ifndef Data_H
#define Date_H


class Date{
    int day;
    int month;
    int year;

    public:
        //date constructor
        Date();
        Date(int,int,int);
        void setDay(int);//setter for Day
        void setMonth(int);//setter for Month
        void setYear(int);//setter for Year

        int getDay(); //getter for day
        int getMonth();// getter for month
        int getYear(); //getter for year

        //funciton to print date
        void print();
        //equal to operator to check two dates are same or not
        bool operator ==(Date&);

        ~Date();

};



#endif
