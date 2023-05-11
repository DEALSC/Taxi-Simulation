#include "DriverList.h"

DriverList::DriverList()
  : head(NULL){}

DriverList::~DriverList(){
  Node* currNode = head;
  Node* nextNode = NULL;

  while(currNode!=NULL){
      nextNode = currNode->next;
      //delete currNode->data;
      delete currNode;
      currNode = nextNode;
  }
}

bool DriverList::isEmpty() const{
  if(head->data == NULL){
    return true;
  }
  return false;
}

void DriverList::add(Driver* driver){
  Node* newNode = new Node();
  newNode->data = driver;
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

bool DriverList::get(string name, Driver** driver) const{
  Node * currNode;

  currNode = head;

  while (currNode!=NULL){
      if (currNode->data->User::getName() == name){
         break;
      }
      currNode = currNode->next;
  }

  if (currNode == NULL){
      *driver = NULL;
      return false;
  }
  //currNode is not NULL
  *driver = currNode->data;
  return true;
}

bool DriverList::remove(string name, Driver** driver){
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
      *driver = NULL;
      return false;
  }
  //currNode is not NULL
  if (prevNode == NULL){
      head = currNode->next;
  }else{
      prevNode->next = currNode->next;
  }
  *driver = currNode->data;
  delete currNode;
  return true;
}

bool DriverList::findRide(int rating, Size size, Location location, Driver** d) const{
  Node* currNode = head;
  int distance = currNode->data->getDistance(location)+1; //+1 so that distance will always be the first driver's distance when the loop starts
  bool driverCheck = false;

  while(currNode != NULL){
      if(currNode->data->getDistance(location) < distance && currNode->data->match(rating, size)){ //looks for driver that's closest and one that is within the difference 2 of the ratings
        distance = currNode->data->getDistance(location);
        *d = currNode->data;
        driverCheck = true;
      }
      currNode = currNode->next;
  }

  return driverCheck;
}

void DriverList::print() const{
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

void DriverList::clear(){
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
