#include "passenger.h"

//default constructor
Passenger::Passenger(){
  name = "-";
  address = "-";
  phoneNum = "-";
}

//constructor
Passenger::Passenger(const string &n, const string &a, const string &p){
  name = n;
  address = a;
  phoneNum = p;
}

//copy constructor
Passenger::Passenger(const Passenger &copy){
  name = copy.name;
  address = copy.address;
  phoneNum = copy.phoneNum;
}

//overloaded assignment op
Passenger& Passenger::operator= (const Passenger& p){
  name = p.name;
  address = p.address;
  phoneNum = p.phoneNum;
  return *this;
}

//overloaded stream insertion op
ostream& operator<< (ostream &out, const Passenger& p) {
  out<<"Name: "<<p.name<<endl<<"Address: "<<p.address<<endl<<"Phone Number: "<<p.phoneNum<<endl;
  return out;
}

void Passenger::clear (){
  name = "-";
  address = "-";
  phoneNum = "-";
}
