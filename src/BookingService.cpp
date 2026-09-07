#ifndef BOOKINGSERVICE_CPP
#define BOOKINGSERVICE_CPP

#include <iostream>
#include <vector>
using namespace std;

#include "ShowSeat.cpp"
#include "PriceCalculator.cpp"
#include "Payment.cpp"
#include "Booking.cpp"
#include "Customer.cpp"
#include "TicketPrinter.cpp"
#include "Show.cpp"

class BookingService {
public:
    Booking* bookTicket(
        Customer* customer,
        Show* show,
        vector<ShowSeat*> selectedSeats,
        PriceCalculator* priceCalculator,
        Payment* payment,
        TicketPrinter* ticketPrinter
    ) {
        // Check seat availability
        for (ShowSeat* seat : selectedSeats) {
            if (!seat->isAvailable()) {
                cout << "Error: Seat "
                     << seat->getSeatNumber()
                     << " is already booked.\n";

                return nullptr;
            }
        }

        // Temporarily reserve seats
        for (ShowSeat* seat : selectedSeats) {
            seat->book();
        }

        // Calculate total price
        double totalAmount =
            priceCalculator->calculate(selectedSeats);

        // Process payment
        bool paymentSuccessful =
            payment->pay(totalAmount);

        // Release seats if payment fails
        if (!paymentSuccessful) {
            for (ShowSeat* seat : selectedSeats) {
                seat->release();
            }

            cout << "Payment failed. Booking cancelled.\n";

            return nullptr;
        }

        // Create booking
        Booking* booking = new Booking(
            customer,
            show,
            selectedSeats,
            totalAmount
        );

        booking->confirm();

        // Print ticket
        ticketPrinter->print(booking);

        return booking;
    }

    void cancelBooking(Booking* booking) {
        if (booking == nullptr) {
            return;
        }

        for (ShowSeat* seat : booking->getSeats()) {
            seat->release();
        }

        booking->cancel();

        cout << "Booking cancelled successfully.\n";
    }
};

#endif