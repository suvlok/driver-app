#include <iostream>
#include <string>
using namespace std;

#include "CustomerList.h"
#include "Location.h"

CustomerList::CustomerList(): head(NULL){}


CustomerList::~CustomerList(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        //delete currNode->data;       //MAYBE CHANGE THIS
        delete currNode;
        currNode = nextNode;
    }

}

bool CustomerList::isEmpty() const {
  Node* tempNode = head;

  if(tempNode == NULL){
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

void CustomerList::remove(const string& name, Customer** goner){
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

void CustomerList::get(const string& name, Customer** customer){
    Node * currNode;

    currNode = head;

    while (currNode!=NULL){
        if (currNode->data->getName()==name){
           break;
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *customer = NULL;
        return;
    }
    //currNode is not NULL
    *customer = currNode->data;
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
