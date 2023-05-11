#include "CustomerList.h"

CustomerList::CustomerList()
  : head(NULL){}

CustomerList::~CustomerList(){
  Node* currNode = head;
  Node* nextNode = NULL;

  while(currNode!=NULL){
      nextNode = currNode->next;
      //delete currNode->data;
      delete currNode;
      currNode = nextNode;
  }
}

bool CustomerList::isEmpty() const{
  if(head->data == NULL){
    return true;
  }
  return false;
}

void CustomerList::add(Customer* customer){
  Node* newNode = new Node();
  newNode->data = customer;
  newNode->next = NULL;

  Node* currNode = head;
  Node* prevNode = NULL;

  while(currNode!=NULL){
      if (newNode->data->User::lessThan(*currNode->data)){
          break;
      }
      prevNode = currNode;
      currNode = currNode->next;
  }

  //insert currNode
  if (prevNode == NULL){
      head = newNode;
  }else{
      prevNode->next = newNode;
  }
  newNode->next = currNode;
}

bool CustomerList::get(string name, Customer** customer) const{
  Node * currNode;

  currNode = head;

  while (currNode!=NULL){
      if (currNode->data->User::getName() == name){
         break;
      }
      currNode = currNode->next;
  }

  if (currNode == NULL){
      *customer = NULL;
      return false;
  }
  //currNode is not NULL
  *customer = currNode->data;
  return true;
}

bool CustomerList::remove(string name, Customer** customer){
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  while (currNode!=NULL){
      if (currNode->data->User::getName() == name){
         break;
      }
      prevNode = currNode;
      currNode = currNode->next;
  }

  if (currNode == NULL){
      *customer = NULL;
      return false;
  }
  //currNode is not NULL
  if (prevNode == NULL){
      head = currNode->next;
  }else{
      prevNode->next = currNode->next;
  }
  *customer = currNode->data;
  delete currNode;
  return true;
}

void CustomerList::print() const{
  Node* currNode = head;
  cout<<"Print list..."<<endl;

  if (currNode == NULL){
      cout <<"List empty"<<endl;
  }

  while(currNode != NULL){
      currNode->data->print();
      currNode = currNode->next;
  }
}

void CustomerList::clear(){
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  while (currNode!=NULL){
      prevNode = currNode;
      currNode = currNode->next;
      delete prevNode->data;
      delete prevNode;
  }

  head = currNode;
}
