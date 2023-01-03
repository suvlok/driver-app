#include "Customer.h"

const static char code = 'C';
static int nextId;

Customer::Customer(const string& name, int rating, Location location): User(code, nextId, name, rating, location) {}

Customer::Customer(): User(code, nextId, "Bob", 5, location) {}

void Customer::print(){
  User::print();
  cout<<"Code: "<< code <<endl;
  cout<<"Next ID: " << nextId <<endl;
}
