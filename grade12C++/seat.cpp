#include "seat.h"

//constructor - empty seat
Seat::Seat(const int &seatNum){
  this->seatNum = seatNum;
  available = true;
}

//constructor - reserved seat
Seat::Seat(const int &seatNum, const Passenger &passenger){
  this->seatNum = seatNum;
  this->passenger = passenger;
  available = false;
}

ostream& operator << (ostream& out, const Seat& seat){
  out << "Seat " << seat.seatNum << endl;
  out << "Available: " << (seat.available? "yes" : "no") << endl;
  out << seat.passenger << endl;
  return out;
}

void Seat::operator= (Seat& seat) {
  this->passenger.setName(seat.passenger.getName());
}

bool operator== (Seat& s1, Seat& s2) {
  return (s1.getPassenger().getName() == s2.getPassenger().getName());
}

bool operator!= (Seat& s1, Seat& s2) {
  return (s1.getPassenger().getName() != s2.getPassenger().getName());
}

bool operator< (Seat& s1, Seat& s2) {
  return (s1.getPassenger().getName() < s2.getPassenger().getName());
}

bool operator> (Seat& s1, Seat& s2) {
  return (s1.getPassenger().getName() > s2.getPassenger().getName());
}

bool Seat::reserveSeat (const Passenger &p){
  if (available == false) 
    return false;
  
  passenger = p;
  available = false;
  
  return true;
}

bool Seat::unreserveSeat (){

  if (available)
    return false;

  passenger.clear();
  available = true;
  
  return true;
}

void Seat::setAvailability(const string &availability) {
  if (availability == "yes")
    available = true;
  else
    available = false;
}
