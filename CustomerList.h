#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"

class CustomerList{

  class Node{
    public:
      Customer* data;
      Node* next;
  };

  public:
    //Construtor
    CustomerList();
    //Destructor
    ~CustomerList();
    //others
    bool isEmpty() const;
    void add(Customer* customer);
    bool get(string name, Customer** customer) const;
    bool remove(string name, Customer** customer);
    void print() const;
    void clear();

  private:
    Node* head;
};

#endif
