#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include <string>
using namespace std;

class Customer {
private:
    string name;
    string phone;

public:
    Customer(string name, string phone) {
        this->name = name;
        this->phone = phone;
    }

    string getName() {
        return this->name;
    }

    string getPhone() {
        return this->phone;
    }
};

#endif