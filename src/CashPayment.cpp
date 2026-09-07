#include <iostream>
using namespace std;

#include "Payment.cpp"

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Processing Cash payment of Rs. " << amount << "...\n";
        return true;
    }
};