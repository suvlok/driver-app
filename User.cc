#include "User.h"

User::User(char idOne, int idTwo, const string& name, int rating, Location location){
  string newId = "";
  newId.push_back(idOne);
  newId += idTwo;

  id = newId;
  this->name = name;
  this->rating = rating;
  this->location = location;
}

string User::getId() const{
  return id;
}

string User::getName() const{
  return name;
}

int User::getRating() const{
  return rating;
}

Location User::getLocation() const{
  return location;
}

void User::setRating(int newRating){
  rating = newRating;
}

void User::setLocation(Location newLocation){
  location = newLocation;
}

void User::setLocation(int x, int y){
  location.x = x;
  location.y = y;
}

bool User::lessThan(User newUser) const{
  if(this->name < newUser.name){
    return true;
  }
  return false;
}

void User::print() const{
  cout<<"Id: "<< id <<endl;
  cout<<"Name: "<< name <<endl;
  cout<<"Rating: "<< rating <<endl;
  cout<<"Location: "<<endl;
  location.print();
}
