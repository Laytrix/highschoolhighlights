#ifndef SEAT_H
#define SEAT_H

#include "passenger.h"

using namespace std;

class Seat {
  private:
      string seatNum;
      bool available;
      Passenger passenger;

  public:
      //constructor - initalizes an empty seat
      Seat(const int &seatNum); 
      //constructor - initalizes a reserved seat with passenger info
      Seat(const int &seatNum, const Passenger &passenger); 

      //overloaded assignment operator
      void operator= (Seat& seat);
      
      //overloaded stream insertion operator
      friend ostream& operator << (ostream& out, const Seat& seat);
 
      //get functions
      string getSeatNum() { return seatNum; }
      bool isAvailable() { return available; }
      Passenger& getPassenger() { return passenger; }

      //assigns a passenger to a seat once it has been sold, returns false if seat is already assigned
      bool reserveSeat (const Passenger &passenger);
      bool unreserveSeat ();

      //set function
      void setSeatNum(const string &seatNumber) { seatNum = seatNumber; }
      void setAvailability(const string &availability);
};

#endif
