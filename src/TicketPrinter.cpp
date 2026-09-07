#ifndef TICKETPRINTER_CPP
#define TICKETPRINTER_CPP

#include <iostream>
using namespace std;

#include "Booking.cpp"
#include "Show.cpp"
#include "Movie.cpp"
#include "ShowSeat.cpp"
#include "Screen.cpp"

class TicketPrinter {
public:
    void print(Booking* booking) {
        cout << "\n========== MOVIE TICKET ==========\n";

        cout << "Booking ID: "
             << booking->getBookingId() << endl;

        cout << "Movie: "
             << booking->getShow()->getMovie()->getTitle()
             << endl;

        cout << "Screen: "
             << booking->getShow()->getScreen()->getScreenNumber()
             << endl;

        cout << "Time: "
             << booking->getShow()->getStartTime()
             << endl;

        cout << "Seats: ";

        for (ShowSeat* seat : booking->getSeats()) {
            cout << seat->getSeatNumber() << " ";
        }

        cout << "\nTotal Amount: Rs. "
             << booking->getTotalAmount() << endl;

        cout << "Status: "
             << booking->getStatus() << endl;

        cout << "==================================\n";
    }
};

#endif