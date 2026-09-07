#ifndef SHOWSEAT_CPP
#define SHOWSEAT_CPP

#include <string>
using namespace std;

class ShowSeat {
private:
    string seatNumber;
    string seatType;
    string status;

public:
    ShowSeat(string seatNumber, string seatType) {
        this->seatNumber = seatNumber;
        this->seatType = seatType;
        this->status = "AVAILABLE";
    }

    bool isAvailable() {
        return this->status == "AVAILABLE";
    }

    void book() {
        if (isAvailable()) {
            this->status = "BOOKED";
        }
    }

    void release() {
        this->status = "AVAILABLE";
    }

    string getSeatNumber() {
        return this->seatNumber;
    }

    string getSeatType() {
        return this->seatType;
    }

    string getStatus() {
        return this->status;
    }
};

#endif