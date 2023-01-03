#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "User.h"
#include "defs.h"

using namespace std;

class Driver: public User {
    public:
      Driver(const string& name = "Bob", int rating = 1, const Size size = small, Location location = Location());
      Driver();
      bool match(int rating, const Size size) const;
      int getDistance(Location location);
      void print();

    protected:
      Size size;

};

#endif
