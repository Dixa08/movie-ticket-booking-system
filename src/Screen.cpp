#ifndef SCREEN_CPP
#define SCREEN_CPP

#include <string>
#include <vector>
using namespace std;

class Seat;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int screenNumber) {
        this->screenNumber = screenNumber;
    }

    void addSeat(Seat seat) {
        seats.push_back(seat);
    }

    int getScreenNumber() {
        return this->screenNumber;
    }

    vector<Seat> getSeats() {
        return this->seats;
    }
};

#endif