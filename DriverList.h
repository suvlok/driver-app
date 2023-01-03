#ifndef DRIVERLIST_H
#define DRIVERLIST_H

#include <iostream>
#include <string>
#include "Driver.h"

using namespace std;

class DriverList {
  class Node {
      public:
          Driver* data;
          Node*    next;
  };

  public:
      DriverList();

      ~DriverList();

      bool isEmpty() const;

      void add(Driver*);

      void get(const string& name, Driver**);

      void remove(const string& name, Driver**);

      void print() const;

      void clear();

      bool findRide(int rating, const Size, Location, Driver** d);

  private:
      Node* head; //the head of the driver list



};

#endif
