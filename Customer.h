#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"

class Customer: public User{
  public:
    //Construtor
    Customer();
    Customer(const string& name);
    Customer(string name, int rating, Location location);
    //others
    void print() const;

  private:
    //class variables
    static const char code;
    static int nextId;
};

#endif
