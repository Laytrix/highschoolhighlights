#include "flight.h"

Flight::Flight(const int &flightNum){

  this->flightNum = flightNum;
  for (int i = 0; i < numOfSeats; i++){
    seats[i] = new Seat(i+1);
  }
}

ostream& operator<< (ostream& out, const Flight& flight) {

  out << "Flight #" << flight.flightNum << endl;
  for (int i = 0; i < flight.numOfSeats; i++){
    out << *flight.seats[i] << endl;
  }
  return out;
}

Seat* Flight::getSeat(const int &num){
  return seats[num-1];
}

void Flight::printAvailableSeats (const string flightNum){
  
  cout << "Available Seats: " << endl;
  for (int i = 0; i < this->numOfSeats; i++){
    if (this->seats[i]->isAvailable()) 
      cout << this->seats[i]->getSeatNum() << endl;
  }
}

void Flight::readDatabase(const string &file){

  string line;
    ifstream readfile (file);
    int index = 0;
    if (readfile.is_open())
    {
      while ( getline (readfile,line) )
      {
        index++;
        
        if (index == 1){
          this->setFlightNum(line);
          continue;
        }  
              
        //seat number
        if (index % 5 == 2)
          this->getSeat((index)/5 + 1)->setSeatNum(line);
        
        //availability
        if (index % 5 == 3)
          this->getSeat((index - 2)/5 + 1)->setAvailability(line);  
        
        //name
        if (index % 5 == 4)
          this->getSeat((index - 2)/5 + 1)->getPassenger().setName(line);
        
        //address    
        if (index % 5 == 0)
          this->getSeat((index - 2)/5 + 1)->getPassenger().setAddress(line);
        
        //phone number
        if (index % 5 == 1)
          this->getSeat((index - 2)/5 + 1)->getPassenger().setPhoneNum(line);

      }
      readfile.close();
  }
  else cout<<"Cannot access file";
}

void Flight::writeDatabase(const string &file){

  ofstream writefile;
  writefile.open (file);

  writefile << this->flightNum << endl;
  
  for (int i = 0; i < numOfSeats; i++){
    writefile << this->seats[i]->getSeatNum() << endl;
    writefile << (this->seats[i]->isAvailable()? "yes" : "no") << endl;
    writefile << this->seats[i]->getPassenger().getName() << endl;
    writefile << this->seats[i]->getPassenger().getAddress() << endl;
    writefile << this->seats[i]->getPassenger().getPhoneNum() << endl;
  }
  
  writefile.close();
}
