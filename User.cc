#include "User.h"

User::User(char idLetter, int idNumber, string name, int rating, Location location)
//:id(idLetter + to_string(idNumber)), name(name), rating(rating), location(location){}
{
  stringstream idCode;
  idCode << idLetter;
  idCode << to_string(idNumber);
  this->id = idCode.str();

  this->name = name;
  this->rating = rating;
  this->location = location;
}

string User::getId() const{
  return id;
}

string User::getName() const{
  return name;
}

int User::getRating() const{
  return rating;
}

Location User::getLocation() const{
  return location;
}

void User::setRating(int rating){
  this->rating = rating;
}

void User::setLocation(Location location){
  this->location.setLocation(location.getX(), location.getY());
}

void User::setLocation(int x, int y){
  this->location.setLocation(x, y);
}

bool User::lessThan(const User& user) const{
  if(this->name < user.name){
    return true;
  }
  return false;
}

void User::print() const{
  cout<< "id: " << id << endl;
  cout<< "name: " << name << endl;
  cout<< "rating: " << rating << endl;
  cout<< "location: "; location.print(); cout << endl << endl;
}
