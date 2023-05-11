#ifndef DRIVERLIST_H
#define DRIVERLIST_H

#include "Driver.h"

class DriverList{

  class Node{
    public:
      Driver* data;
      Node* next;
  };

  public:
    //Construtor
    DriverList();
    //Destructor
    ~DriverList();
    //others
    bool isEmpty() const;
    void add(Driver* driver);
    bool get(string name, Driver** driver) const;
    bool remove(string name, Driver** driver);
    bool findRide(int rating, Size size, Location location, Driver** d) const;
    void print() const;
    void clear();

  private:
    Node* head;
};

#endif
