#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "User.h"

using namespace std;

class Customer: public User {
    public:
      Customer(const string& name = "Bob", int rating = 0, Location location = Location());
      Customer();
      void print();

};

#endif
