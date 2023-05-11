#ifndef DRIVER_H
#define DRIVER_H

#include "User.h"

class Driver: public User{
  public:
    //Construtor
    Driver(string name, int rating, Size size, Location location);
    Driver(const string& name);
    //others
    bool match(int rating, Size size) const;
    int getDistance(Location location);
    void print() const;

  private:
    Size size;
    //class variables
    static const char code;
    static int nextId;
};


#endif
