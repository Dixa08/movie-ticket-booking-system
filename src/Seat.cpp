#ifndef SEAT_CPP
#define SEAT_CPP

#include <string>
using namespace std;

class Seat {
private:
    string seatNumber;
    string seatType;

public:
    Seat(string seatNumber, string seatType) {
        this->seatNumber = seatNumber;
        this->seatType = seatType;
    }

    string getSeatNumber() {
        return this->seatNumber;
    }

    string getSeatType() {
        return this->seatType;
    }
};

#endif