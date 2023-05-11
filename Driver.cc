#include "Driver.h"

int Driver::nextId = 1;
const char Driver::code = 'D';


Driver::Driver(string name, int rating, Size size, Location location) : User(code, nextId, name, rating, location)
{
  this->size = size;
  ++nextId;
}

Driver::Driver(const string& name) : User(code, nextId, name, 5, Location(5,4))
{
  ++nextId;
}

bool Driver::match(int rating, Size size) const{
  bool testRating = false;

  if(rating > this->rating){
    if((rating - this->rating) > 2){
      return false;
    }else{
      testRating = true;
    }
  }else{
    if((this->rating - rating) > 2){
      return false;
    }else{
      testRating = true;
    }
  }

  if(this->size  >= size && testRating){
    return true;
  }
  return false;
}

int Driver::getDistance(Location location){
  int distance = User::location.getDistance(location);
  return distance;
}

void Driver::print() const{
  cout<< "Driver::print()" << endl;
  User::print();
}
