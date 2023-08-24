#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

class Passenger {
    private:
        string name, address, phoneNum;

    public:
        //default constructor
        Passenger();

        //constructor
        Passenger(const string &name, const string &address, const string &phoneNum);
        
        //copy constructor
        Passenger(const Passenger &copy);
        
        //overloaded assignment operator
        Passenger& operator= (const Passenger& pass);
        //overloaded stream insertion operator
        friend ostream& operator << (ostream& out, const Passenger& pass);
        
        string getName(){ return name; }
        string getAddress(){ return address; }
        string getPhoneNum(){ return phoneNum; }


        void setName (const string &name) { this->name = name; }
        void setAddress (const string &address) { this->address = address; }
        void setPhoneNum (const string &phoneNum) { this->phoneNum = phoneNum; }
        
        void clear();
};

#endif
