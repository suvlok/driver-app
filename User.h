#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class User {
    public:
      User(char idOne, int idTwo, const string& name, int rating, Location location);

      string getId() const;
      string getName() const;
      int getRating() const;
      Location getLocation() const;

      void setRating(int newRating);
      void setLocation(Location newLocation);
      void setLocation(int x, int y);
      bool lessThan(User newUser) const;

      void print() const;

    protected:
        string id;
        string name;
        int rating;
        Location location;

};

#endif
