#ifndef BOOKING_CPP
#define BOOKING_CPP

#include <string>
#include <vector>
using namespace std;

class Customer;
class Show;
class ShowSeat;

class Booking {
private:
    static int nextBookingId;

    int bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    double totalAmount;
    string status;

public:
    Booking(
        Customer* customer,
        Show* show,
        vector<ShowSeat*> seats,
        double totalAmount
    ) {
        this->bookingId = nextBookingId++;
        this->customer = customer;
        this->show = show;
        this->seats = seats;
        this->totalAmount = totalAmount;
        this->status = "PENDING";
    }

    void confirm() {
        this->status = "CONFIRMED";
    }

    void cancel() {
        this->status = "CANCELLED";
    }

    int getBookingId() {
        return this->bookingId;
    }

    Customer* getCustomer() {
        return this->customer;
    }

    Show* getShow() {
        return this->show;
    }

    vector<ShowSeat*> getSeats() {
        return this->seats;
    }

    double getTotalAmount() {
        return this->totalAmount;
    }

    string getStatus() {
        return this->status;
    }
};

int Booking::nextBookingId = 1001;

#endif