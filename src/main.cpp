#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Movie.cpp"
#include "Seat.cpp"
#include "ShowSeat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "Booking.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"

int main() {
    
Movie movie1(
    "Interstellar",
    "English",
    169
);

Movie movie2(
    "Kantara",
    "Kannada",
    148
);
Screen screen1(1);
Screen screen2(2);

screen1.addSeat(Seat("A1", "SILVER"));
screen1.addSeat(Seat("A2", "SILVER"));
screen1.addSeat(Seat("A3", "SILVER"));
screen1.addSeat(Seat("A4", "SILVER"));

screen1.addSeat(Seat("B1", "GOLD"));
screen1.addSeat(Seat("B2", "GOLD"));
screen1.addSeat(Seat("B3", "GOLD"));
screen1.addSeat(Seat("B4", "GOLD"));

screen1.addSeat(Seat("C1", "PLATINUM"));
screen1.addSeat(Seat("C2", "PLATINUM"));

screen2.addSeat(Seat("A1", "SILVER"));
screen2.addSeat(Seat("A2", "SILVER"));
screen2.addSeat(Seat("A3", "SILVER"));
screen2.addSeat(Seat("A4", "SILVER"));

screen2.addSeat(Seat("B1", "GOLD"));
screen2.addSeat(Seat("B2", "GOLD"));
screen2.addSeat(Seat("B3", "GOLD"));
screen2.addSeat(Seat("B4", "GOLD"));

screen2.addSeat(Seat("C1", "PLATINUM"));
screen2.addSeat(Seat("C2", "PLATINUM"));


Show show1(&movie1, &screen1, "6:00 PM");
Show show2(&movie2, &screen2, "7:30 PM");

for (Seat seat : screen1.getSeats()) {
    show1.addShowSeat(
        new ShowSeat(
            seat.getSeatNumber(),
            seat.getSeatType()
        )
    );
}

for (Seat seat : screen2.getSeats()) {
    show2.addShowSeat(
        new ShowSeat(
            seat.getSeatNumber(),
            seat.getSeatType()
        )
    );
}

Customer customer("Dixa", "9876543210");
PriceCalculator priceCalculator;
TicketPrinter ticketPrinter;
BookingService bookingService;
Booking* lastBooking = nullptr;

UpiPayment upiPayment;
CardPayment cardPayment;
CashPayment cashPayment;

Payment* payment = &upiPayment;
//------------------------------------------
    int choice;

    do {
        cout << "\n===== MOVIE TICKET BOOKING =====\n";
        cout << "1. List Movies\n";
        cout << "2. View Shows\n";
        cout << "3. View Seats\n";
        cout << "4. Book Ticket\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n===== MOVIES CURRENTLY PLAYING =====\n";

            cout << "1. " << movie1.getTitle()
            << " | " << movie1.getLanguage()
            << " | " << movie1.getDuration() << " minutes\n";

             cout << "2. " << movie2.getTitle()
            << " | " << movie2.getLanguage()
            << " | " << movie2.getDuration() << " minutes\n";

        break;

        case 2:
        cout << "\n===== AVAILABLE SHOWS =====\n";

         cout << "1. " << show1.getMovie()->getTitle()
         << " | Screen " << show1.getScreen()->getScreenNumber()
         << " | " << show1.getStartTime() << "\n";

        cout << "2. " << show2.getMovie()->getTitle()
         << " | Screen " << show2.getScreen()->getScreenNumber()
         << " | " << show2.getStartTime() << "\n";

        break;

        case 3:
        cout << "\n===== SEAT LAYOUT =====\n";

        cout << "\nInterstellar - Screen 1 - 6:00 PM\n";

        for (ShowSeat* seat : show1.getShowSeats()) {
        cout << seat->getSeatNumber()
             << " [" << seat->getSeatType()
             << "] - " << seat->getStatus() << "\n";
            }

        cout << "\nKantara - Screen 2 - 7:30 PM\n";

        for (ShowSeat* seat : show2.getShowSeats()) {
        cout << seat->getSeatNumber()
             << " [" << seat->getSeatType()
             << "] - " << seat->getStatus() << "\n";
        }

        break;

            
        case 4: {
    int showChoice;
    int numberOfSeats;

    cout << "\n===== BOOK TICKET =====\n";
    cout << "1. Interstellar - Screen 1 - 6:00 PM\n";
    cout << "2. Kantara - Screen 2 - 7:30 PM\n";
    cout << "Choose show: ";
    cin >> showChoice;

    Show* selectedShow = nullptr;

    if (showChoice == 1) {
        selectedShow = &show1;
    }
    else if (showChoice == 2) {
        selectedShow = &show2;
    }
    else {
        cout << "Invalid show.\n";
        break;
    }

    cout << "Enter number of seats: ";
    cin >> numberOfSeats;

    vector<ShowSeat*> selectedSeats;

    for (int i = 0; i < numberOfSeats; i++) {

        string seatNumber;

        cout << "Enter seat " << i + 1 << ": ";
        cin >> seatNumber;

        ShowSeat* selectedSeat = nullptr;

        for (ShowSeat* seat : selectedShow->getShowSeats()) {
            if (seat->getSeatNumber() == seatNumber) {
                selectedSeat = seat;
                break;
            }
        }

        if (selectedSeat == nullptr) {
            cout << "Seat " << seatNumber << " not found.\n";
            selectedSeats.clear();
            break;
        }

        selectedSeats.push_back(selectedSeat);
    }

    int paymentChoice;

cout << "\n===== PAYMENT METHOD =====\n";
cout << "1. UPI\n";
cout << "2. Card\n";
cout << "3. Cash\n";
cout << "Choose payment method: ";
cin >> paymentChoice;

Payment* selectedPayment = nullptr;

if (paymentChoice == 1) {
    selectedPayment = &upiPayment;
}
else if (paymentChoice == 2) {
    selectedPayment = &cardPayment;
}
else if (paymentChoice == 3) {
    selectedPayment = &cashPayment;
}
else {
    cout << "Invalid payment method.\n";
    break;
}

    Booking* booking = bookingService.bookTicket(
    &customer,
    selectedShow,
    selectedSeats,
    &priceCalculator,
    selectedPayment,
    &ticketPrinter
);
    if (booking == nullptr) {
    cout << "Booking could not be completed.\n";
}
else {
    lastBooking = booking;
}
    break;
}


       case 5:
    cout << "\n===== CANCEL BOOKING =====\n";

    if (lastBooking == nullptr) {
        cout << "No booking available to cancel.\n";
        break;
    }

    cout << "Booking ID: " << lastBooking->getBookingId() << endl;
    cout << "Movie: "
         << lastBooking->getShow()->getMovie()->getTitle() << endl;

    bookingService.cancelBooking(lastBooking);

    lastBooking = nullptr;

    break;

        case 6:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}