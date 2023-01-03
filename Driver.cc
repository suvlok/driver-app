#include "Driver.h"

const char code = 'D';
int nextId;

Driver::Driver(const string& name, int rating, const Size size, Location location): User(code, nextId, name, rating, location), size(size) {}

Driver::Driver(): User(code, nextId, "Bob", 5, location) {}

bool Driver::match(int otherRating, const Size size) const{
  int ratingDif = abs(rating - otherRating);

  if(this->size >= size && ratingDif <= 2){
    return true;
  }
  return false;
}

int Driver::getDistance(Location location){
  return this->location.getDistance(location);
}

void Driver::print(){
  User::print();
  cout<<"Code: "<< code <<endl;
  cout<<"Next ID: " << nextId <<endl;
}
