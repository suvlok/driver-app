#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;

class CustomerList {
  class Node {
      public:
          Customer* data;
          Node*    next;
  };

  public:
      CustomerList();

      ~CustomerList();

      bool isEmpty() const;

      void add(Customer*);

      void get(const string& name, Customer**);

      void remove(const string& name, Customer**);

      void print() const;

      void clear();


  private:
      Node* head; //the head of the driver list



};

#endif
