#include <iostream>
#include <string>
using namespace std;

#include "DriverList.h"
#include "Location.h"

DriverList::DriverList(): head(NULL){}


DriverList::~DriverList(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        //delete currNode->data;       //MAYBE CHANGE THIS
        delete currNode;
        currNode = nextNode;
    }

}

bool DriverList::isEmpty() const {
  Node* tempNode = head;

  if(tempNode == NULL){
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
        if (newNode->data->lessThan(*currNode->data)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (prevNode == NULL){
        head = newNode;
    }else{
        prevNode->next = newNode;
    }
    newNode->next = currNode;

}

void DriverList::remove(const string& name, Driver** goner){
    Node* currNode;
    Node* prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->getName() == name){
           break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *goner = NULL;
        return;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *goner = currNode->data;
    delete currNode;
}

void DriverList::get(const string& name, Driver** driver){
    Node * currNode;

    currNode = head;

    while (currNode!=NULL){
        if (currNode->data->getName()==name){
           break;
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *driver = NULL;
        return;
    }
    //currNode is not NULL
    *driver = currNode->data;
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
  Node *temp = head, *next;

    while(temp != NULL){
        next = temp->next;
        delete temp->data;
        delete temp;
        temp = next;
    }
    delete head;

    head = NULL;
}

bool DriverList::findRide(int rating, const Size size, Location location, Driver** d) {
  Node *temp = head;
  Node *closestDistance = temp;
  bool nodeReached = false;

  while(temp != NULL) {
    if(temp->data->match(rating, size)){
      if( closestDistance->data->getLocation().getDistance(location) >= temp->data->getLocation().getDistance(location)) {
        nodeReached = true;
        closestDistance = temp;
      }
    }
    temp = temp->next;
  }

  if(nodeReached){
    *d = closestDistance->data;
    return true;
  }

  *d = NULL;
  return false;
}
