#include "flight.h"
using namespace std;

void nuke(){
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void alphabeticalSeats(Flight* flights[], int flight){

  Seat* seatsCopy[flights[flight-1]->getNumOfSeats()];

  for (int i = 0; i < flights[flight-1]->getNumOfSeats(); i++){
    seatsCopy[i] = flights[flight-1]->getSeat(i+1);
  }
  
  for (int i = 1; i < flights[flight-1]->getNumOfSeats(); i++){
  
    Seat* temp = seatsCopy[i];
    int j = i;
    
    while (j > 0 && seatsCopy[j-1]->getPassenger().getName() > temp->getPassenger().getName()) {
      seatsCopy[j] = seatsCopy[j-1];
      j--;
    }
    seatsCopy[j] = temp;
  }

  for (int i = 0; i < flights[flight-1]->getNumOfSeats(); i++){
    if (!(seatsCopy[i]->isAvailable()))
      cout<<*seatsCopy[i]<<endl;
  }
}

void initializeFlights (Flight* flights[], int numOfFlights){
  string filename;
  for (int i = 0; i < numOfFlights; i++){
    flights[i]= new Flight(i+1);
    filename = "flight" + to_string(i+1) + ".txt";
    flights[i]->readDatabase(filename);
  }
}

bool searchSeats (Flight* flights[], int flight, string name){

  for (int i = 0; i < flights[flight - 1]->getNumOfSeats(); i++){
    if (name == flights[flight - 1]->getSeat(i+1)->getPassenger().getName())
      return true;
  }
  return false;
}

void saveFlightInfo (Flight* flights[], int numOfFlights){
  
  string filename;
  for (int i = 0; i < numOfFlights; i++){
    filename = "flight" + to_string(i+1) + ".txt";
    flights[i]->writeDatabase(filename);
  }
}

void enterFlightInfo (Flight* flights[], int numOfFlights) {

  nuke();
  
  int flight, choice;
  
  cout<<"Which flight would you like to check? (1-3)" << endl << endl;
  
  cin>>flight;

  while (flight != 1 && flight != 2 && flight != 3 ){
    cout<<"Invalid input, try again."<<endl<<endl;
    cin>>flight;
  }
  
  cout<<endl<<endl<<*flights[flight - 1];
  cout<<"Check another flight?"<<endl<<endl;
  cout<<"1: Yes"<<endl;
  cout<<"0: No"<<endl<<endl;

  while (choice != 1 && choice != 0){
    
    cin>>choice;
    
    if (choice == 1)
      enterFlightInfo(flights, numOfFlights);
    
    else if (choice == 0)
      return;
    else {
      cout<<"Invalid input, try again."<<endl<<endl;
      continue;
    }
  }
}

void enterReserveSeat (Flight* flights[], int numOfFlights){

  nuke();
  
  int flight, choice, seatChoice;
  string name, address, phoneNum;

  cout<<"For which flight would you like to book a reservation? (1-3)"<<endl<<endl;
  cin>>flight;

  while (flight != 1 && flight != 2 && flight != 3 ){
    cout<<"Invalid input, try again."<<endl<<endl;
    cin>>flight;
  }

  flights[flight - 1]->printAvailableSeats(to_string(flight - 1));

  cout<<"Which seat would you like to reserve?"<<endl<<endl;
  cin>>seatChoice;

  while (seatChoice < 1 && seatChoice > 10){
    cout<<"Invalid input, try again."<<endl<<endl;
    cin>>seatChoice;
  }
  
  while (!flights[flight - 1]->getSeat(seatChoice)->isAvailable()){
    cout<<"Seat already reserved, pick an available seat."<<endl<<endl;
    cin>>seatChoice;

    while (seatChoice < 1 && seatChoice > 10){
    cout<<"Invalid input, try again."<<endl<<endl;
    cin>>seatChoice;
    }
  }
 
  cout<<"Please enter name: "<<endl<<endl;
  
  cin.ignore();
  getline(cin, name);
  
  flights[flight - 1]->getSeat(seatChoice)->getPassenger().setName(name);
  
  cout<<endl<<"Enter address: "<<endl<<endl;
  
  getline(cin, address);
  
  flights[flight - 1]->getSeat(seatChoice)->getPassenger().setAddress(address);
  
  cout<<endl<<"Enter phone number: "<<endl<<endl;
  
  getline(cin, phoneNum);
  
  flights[flight - 1]->getSeat(seatChoice)->getPassenger().setPhoneNum(phoneNum);
  flights[flight - 1]->getSeat(seatChoice)->setAvailability("no");
  
  cout<<endl<<endl<<"Seat reserved. Reserve another seat?"<<endl<<endl<<"1: Yes"<<endl<<"0: No"<<endl<<endl;
  cin>>choice;

  while (choice != 1 && choice != 0){
    cout<<"Invalid input, try again."<<endl<<endl;
    cin>>choice;
  }

  if (choice == 1)
    enterReserveSeat(flights, numOfFlights);
  return;
}

void enterUnreserveSeat (Flight* flights[], int numOfFlights){

  nuke();
  
  int flight, choice;
  string name, address, phoneNum;
  
  cout<<"For which flight would you like to cancel a reservation? (1-3)"<<endl<<endl;
  cin>>flight;
  
  while (flight != 1 && flight != 2 && flight != 3 ){
    cout<<"Invalid input, try again."<<endl;
    cin>>flight;
  }

  cout<<endl<<"What NAME is the seat reservation under?"<<endl<<endl;
  cin.ignore();
  getline(cin, name);
  
  while (!searchSeats(flights, flight, name)){
    cout<<endl<<endl<<"No seat reservation under the given name."<<endl<<"Try again/enter 0 to return to the menu."<<endl<<endl;
    getline(cin, name);
    
    if (name == "0")
      return;
  }
  
  cout<<endl<<endl<<"Seat unreserved. Would you like to unreserve another seat?"<<endl<<endl;
  cout<<"1: Yes"<<endl;
  cout<<"0: No"<<endl;
  cin>>choice;

  while (choice != 1 && choice != 0){
    cout<<"Invalid input, try again."<<endl<<endl;
    cin>>choice;
  }

  if (choice == 1)
    enterUnreserveSeat(flights, numOfFlights);
  return;
}

void enterCheckAvailability (Flight* flights[], int numOfFlights){

  nuke();
  
  int flight, choice, seat;
  
  cout<<"Which flight would you like to check? (1-3)" << endl << endl;
  cin>>flight;
  
  while (flight != 1 && flight != 2 && flight != 3 ){
    cout<<"Invalid input, try again."<<endl<<endl;
    cin>>flight;
  }
  
  cout<<endl<<endl<< "Which seat would you like to check on flight "<<flight<<"?"<<endl<<endl;
  cin>>seat;

  while (seat < 1 && seat > 10){
    cout<<"Invalid input, try again."<<endl<<endl;
    cin>>seat;
  }
  
  if (flights[flight - 1]->getSeat(seat)->isAvailable())
    cout<<endl<<"This seat IS available."<<endl;
    
  else if (!flights[flight - 1]->getSeat(seat)->isAvailable())
    cout<<endl<<endl<<"This seat IS NOT available.";

  cout<<endl<<endl<<"Would you like to check another seat's availability?"<<endl<<endl;
  cout<<"1: Yes"<<endl;
  cout<<"0: No"<<endl;
  cin>>choice;

  while (choice != 1 && choice != 0){
    cout<<endl<<endl<<"Invalid input, try again."<<endl<<endl;
    cin>>choice;
  }

  if (choice == 1)
    enterCheckAvailability(flights, numOfFlights);
  return;
}

void printPassengers(Flight* flights[], int numOfFlights){

  nuke();

  int flight, choice;
  
  cout<<"Which flight's passenger manifest would you like to check? (1-3)"<<endl<<endl;
  
  cin>>flight;

  while (flight != 1 && flight != 2 && flight != 3 ){
    cout<<"Invalid input, try again."<<endl<<endl;
    cin>>flight;
  }

  cout<<endl<<endl<<endl;
  alphabeticalSeats(flights, flight);
  
  cout<<"Manifest printed by alphabetical order. Check another flight's passenger manifest?"<<endl<<endl<<"1: Yes"<<endl<<"0: No"<<endl<<endl;
  cin>>choice;

  while (choice != 1 && choice != 0){
    cout<<"Invalid input, try again."<<endl<<endl;
    cin>>choice;
  }

  if (choice == 1)
    printPassengers(flights, numOfFlights);
  return;
}

void enterMainMenu (Flight* flights[], int numOfFlights){

  nuke();
  
  int choice;
  
  cout<<"Welcome to the Fly-by-Night Airline database."<<endl;
  cout<<"Input one of the following numbers to begin:"<<endl<<endl;
  cout<<"1: Check Flight Info"<<endl;
  cout<<"2: Create reservation"<<endl;
  cout<<"3: Cancel reservation (never bothered finishing, the user prompting is all there but it doesnt edit the txt file)"<<endl;
  cout<<"4: Check a Specific Seat"<<endl;
  cout<<"5: Check all current passengers"<<endl;
  cout<<"0: Quit Application"<<endl<<endl;
  
  while (choice != 0){
    cin>>choice;
    
    switch (choice){
      case 0:
        saveFlightInfo(flights, numOfFlights);
        nuke();
        cout<<"Fly-by-Night Database exited."<<endl;
        exit(0);
      case 1:
        enterFlightInfo(flights, numOfFlights);
        enterMainMenu(flights, numOfFlights);
      case 2:
        enterReserveSeat(flights, numOfFlights);
        enterMainMenu(flights, numOfFlights);
      case 3:
        enterUnreserveSeat(flights, numOfFlights);
        enterMainMenu(flights, numOfFlights);
      case 4:
        enterCheckAvailability(flights, numOfFlights);
        enterMainMenu(flights, numOfFlights);
      case 5:
        printPassengers(flights, numOfFlights);
        enterMainMenu(flights, numOfFlights);
      default:
        cout<<"Invalid input, try again.";
    }
  }
}

int main(){
  int numOfFlights = 3;
  Flight* flights[numOfFlights];

  initializeFlights(flights, numOfFlights);
  enterMainMenu(flights, numOfFlights);
}
