#ifndef COVOITURE_H
#define COVOITURE_H

#include "CustomerList.h"
#include "DriverList.h"

class CoVoiture{
  public:
    //Construtor
    CoVoiture();
    //Destructor
    ~CoVoiture();
    //others
    void addDriver(string name, int rating, Size size, Location location);
    bool getDriver(string name, Driver** driver) const;
    bool removeDriver(string name);
    void addCustomer(string name, int rating, Location location);
    bool getCustomer(string name, Customer** customer) const;
    bool removeCustomer(string name);
    bool findRide(string name, Size size, Driver** d) const;
    void printCustomers() const;
    void printDrivers() const;

  private:
    DriverList* driverList;
    CustomerList* customerList;
};

#endif
