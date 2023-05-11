#include "CoVoiture.h"

CoVoiture::CoVoiture(){
  this->driverList = new DriverList();
  this->customerList = new CustomerList();
}

CoVoiture::~CoVoiture(){
  driverList->clear();
  customerList->clear();
  delete driverList;
  delete customerList;
}

void CoVoiture::addDriver(string name, int rating, Size size, Location location){
  Driver* driver = new Driver(name, rating, size, location);
  driverList->add(driver);
}

bool CoVoiture::getDriver(string name, Driver** driver) const{
  Driver* d;
  bool check = driverList->get(name, &d);
  if(check){
    cout<< "Driver- " <<  name << " has been found!" << endl << endl;
    *driver = d;
  }else{
    cout<< "Driver- " <<  name << " has not been found :sadge:" << endl << endl;
    *driver = NULL;
  }
  return check;
}

bool CoVoiture::removeDriver(string name){
   Driver* driver;
   bool check = driverList->remove(name, &driver);
   if(check){
     delete driver;
     cout<< "Driver- " <<  name << " has been removed!" << endl << endl;
   }else{
     cout<< "Driver- " <<  name << " cant be removed cuz they dont exist!" << endl << endl;
   }
   return check;
}

void CoVoiture::addCustomer(string name, int rating, Location location){
  Customer* customer = new Customer(name, rating, location);
  customerList->add(customer);
}

bool CoVoiture::getCustomer(string name, Customer** customer) const{
  Customer* c;
  bool check = customerList->get(name, &c);
  if(check){
    cout<< "Customer- " <<  name << " has been found!" << endl << endl;
    *customer = c;
  }else{
    cout<< "Customer- " <<  name << " has NOT been found oof!" << endl << endl;
    *customer = NULL;
  }
  return check;
}

bool CoVoiture::removeCustomer(string name){
  Customer* customer;
  bool check = customerList->remove(name, &customer);
  if(check){
    delete customer;
    cout<< "Customer- " <<  name << " has been removed!" << endl << endl;
  }else{
    cout<< "Customer- " <<  name << " isnt found so cant be removed!" << endl << endl;
  }
  return check;
}

bool CoVoiture::findRide(string name, Size size, Driver** d) const{
  Driver* driver;
  Customer* customer;

  bool driverCheck = false;
  bool customerCheck = customerList->get(name, &customer);

  if(customerCheck){
    cout<< "Customer- " <<  name << " has been found, now finding rider!" << endl << endl;
    driverCheck = driverList->findRide(customer->User::getRating(), size, customer->User::getLocation(), &driver);
    *d = driver;
  }else{
    cout<< "Customer- " <<  name << " has not been found" << endl << endl;
    *d = NULL;
  }

  if(driverCheck){
    cout<< "Driver for " << name << " has been found!" << endl << endl;
  }else{
    cout<< "No Driver matches provided specifications!" << endl << endl;
  }

  return driverCheck;
}

void CoVoiture::printCustomers() const{
  customerList->print();
}

void CoVoiture::printDrivers() const{
  driverList->print();
}
