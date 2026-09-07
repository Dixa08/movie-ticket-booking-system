#include <iostream>
using namespace std;

#include "Payment.cpp"

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Processing Card payment of Rs. " << amount << "...\n";
        return true;
    }
};