#include <iostream>
using namespace std;

#include "Payment.cpp"

class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
    cout << "Processing UPI payment of Rs. " << amount << "...\n";

    char choice;
    cout << "Payment successful? (y/n): ";
    cin >> choice;

    return choice == 'y' || choice == 'Y';
}
};