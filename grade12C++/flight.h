#ifndef FLIGHT_H
#define FLIGHT_H

#include "seat.h"

using namespace std;

class Flight {
  private:
    string flightNum;
    const static int numOfSeats = 10;
    Seat* seats[numOfSeats];
        

  public:
    //constructor
    Flight(const int &flightNum); 

    //overloaded stream insertion operator
    friend ostream& operator << (ostream& out, const Flight& flight);

    void setFlightNum(const string &num){ flightNum = num; }

    //getter
    string getFlightNum(){ return flightNum; } 
    int getNumOfSeats(){ return numOfSeats; }
    Seat* getSeat(const int &num);
        

    void printAvailableSeats (const string flightNum);

    //reads database to assign proper info for flight
    void readDatabase(const string &file);

    //writes
    void writeDatabase(const string &file); 
};

#endif
