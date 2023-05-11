#ifndef USER_H
#define USER_H

#include "defs.h"
#include "Location.h"

class User{
  public:
    //Construtor
    User(char idLetter, int idNumber, string name, int rating, Location location);
    //getters
    string getId() const;
    string getName() const;
    int getRating() const;
    Location getLocation() const;
    //setter
    void setRating(int rating);
    void setLocation(Location location);
    void setLocation(int x, int y);
    //others
    bool lessThan(const User& user) const;
    void print() const;

  protected:
    string id;
    string name;
    int rating;
    Location location;
};

#endif
