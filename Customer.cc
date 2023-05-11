#include "Customer.h"

int Customer::nextId = 1;
const char Customer::code = 'C';

Customer::Customer() : User(code, nextId, "Luigi", 5, Location(5,4))
{
  ++nextId;
}

Customer::Customer(const string& name) : User(code, nextId, name, 5, Location(5,4))
{
  ++nextId;
}

Customer::Customer(string name, int rating, Location location) : User(code, nextId, name, rating, location)
{
  ++nextId;
}

void Customer::print() const{
  cout<< "Customer::print()" << endl;
  User::print();
}
