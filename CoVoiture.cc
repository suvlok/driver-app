#include "CoVoiture.h"

CoVoiture::CoVoiture(){ //check this

}

CoVoiture::~CoVoiture(){
  driverList.clear();
  customerList.clear();
}

void CoVoiture::addDriver(const string& name, int rating, const Size size, Location location){
  Driver *temp = new Driver(name, rating, size, location);
  driverList.add(temp);
}

bool CoVoiture::getDriver(const string& name, Driver ** driver){
  Driver *temp;

  driverList.get(name, &temp);
  *driver = temp;

  if(temp == NULL){
    cout<<"Could not find the Driver!"<<endl;
    return false;
  }
  else {
    return true;
  }
}

bool CoVoiture::removeDriver(const string& name){
  Driver *temp;

  driverList.remove(name, &temp);

  if(temp == NULL){
    cout<<"Could not remove the Driver!"<<endl;
    return false;
  } else {
    return true;
  }

}

void CoVoiture::addCustomer(const string& name, int rating, Location location){
  Customer *temp = new Customer(name, rating, location);
  customerList.add(temp);
}

bool CoVoiture::getCustomer(const string& name, Customer ** customer){
  Customer *temp;

  customerList.get(name, &temp);
  *customer = temp;

  if(temp == NULL){
    cout<<"Could not get the Customer!"<<endl;
    return false;
  }
  else {
    return true;
  }
}

bool CoVoiture::removeCustomer(const string& name){
  Customer *temp;

  customerList.remove(name, &temp);

  if(temp == NULL){
    cout<<"Could not remove the Customer!"<<endl;
    return false;
  } else {
    return true;
  }

}

bool CoVoiture::findRide(const string& name, const Size size, Driver** driver){
  Customer *tempC;

  customerList.get(name, &tempC);
  if(tempC == NULL){
    cout<<"Could not get the Customer!"<<endl;
    return false;
  }

  Driver *tempD;
  driverList.findRide(tempC->getRating(), size, tempC->getLocation(), &tempD);
  if(tempD == NULL){
    cout<<"Could not get the Driver!"<<endl;
    return false;
  } else{
    *driver = tempD;
    return true;
  }
}

void CoVoiture::printCustomers() const{
  customerList.print();
}

void CoVoiture::printDrivers() const{
  driverList.print();
}
