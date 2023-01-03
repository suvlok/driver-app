#ifndef COVOITURE_H
#define COVOITURE_H

#include <iostream>
#include <string>
#include "CustomerList.h"
#include "DriverList.h"

using namespace std;

class CoVoiture {
    public:
      CoVoiture();
      ~CoVoiture();

      void addDriver(const string& name, int rating, const Size, Location);
      bool getDriver(const string& name, Driver **);
      bool removeDriver(const string& name);
      void addCustomer(const string& name, int rating, Location);
      bool getCustomer(const string& name, Customer **);
      bool removeCustomer(const string& name);
      bool findRide(const string& name, const Size size, Driver**);
      void printCustomers() const;
      void printDrivers() const;

    private:
      DriverList driverList;
      CustomerList customerList;

};

#endif
