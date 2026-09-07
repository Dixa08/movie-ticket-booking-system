# Step 1: Requirement Analysis

## Functional Requirements

### FR1 – List Movies

The system shall display all movies currently playing, including their title, language, and duration.

### FR2 – View Shows

The system shall allow the customer to select a movie and display its available shows, including screen number and start time.

### FR3 – View Seat Layout

The system shall allow the customer to select a show and display its seat layout with seat number, seat type, and availability status.

### FR4 – Select Seats

The system shall allow the customer to select one or more available seats. Invalid or already-booked seats shall be rejected without changing their status.

### FR5 – Calculate Price

The system shall calculate the total ticket price based on seat type:

* SILVER – ₹150
* GOLD – ₹250
* PLATINUM – ₹400

### FR6 – Payment

The system shall support payment through UPI, Card, and Cash. If payment fails, the booking shall not be confirmed and the selected seats shall be released.

### FR7 – Print Ticket

After successful payment, the system shall print a ticket containing:

* Booking ID
* Movie name
* Screen number
* Show time
* Seat numbers
* Total amount

### FR8 – Cancel Booking

The system shall allow cancellation of a confirmed booking. After cancellation, the booked seats shall become available again.

---

## Non-Functional Requirements

### NFR1 – Modularity

The system should be divided into separate classes/modules, with each class having a clear responsibility.

### NFR2 – Extensibility

The system should allow new payment methods to be added without modifying existing payment implementations or the main booking logic.

### NFR3 – Input Validation

Invalid menu choices, movie selections, show selections, and seat numbers should be handled properly without crashing the program.

### NFR4 – Maintainability

The code should use meaningful names, constants instead of magic numbers, minimal code duplication, and clear class responsibilities.

# Step 2: Noun–Verb Analysis

## Noun–Verb Identification

| Noun        | Class? | Reason                                                                    |
| ----------- | ------ | ------------------------------------------------------------------------- |
| Movie       | Yes    | Has its own data such as title, language, and duration.                   |
| Seat        | Yes    | Represents a physical seat with seat number and seat type.                |
| Screen      | Yes    | Represents a cinema screen/auditorium and owns physical seats.            |
| Cinema      | Yes    | Represents the cinema and owns its screens.                               |
| Show        | Yes    | Represents a movie screening on a particular screen at a particular time. |
| ShowSeat    | Yes    | Represents the status of a particular seat for a particular show.         |
| Customer    | Yes    | Stores customer information such as name and phone.                       |
| Booking     | Yes    | Represents a customer's booking and stores booking details.               |
| Payment     | Yes    | Represents the common payment contract.                                   |
| Ticket      | No     | Ticket information can be generated and printed by TicketPrinter.         |
| Seat Layout | No     | It is a view/arrangement of ShowSeats rather than an independent entity.  |
| Price       | No     | Price is calculated based on seat type by PriceCalculator.                |

## Important Verbs / Behaviors

| Verb / Action   | Responsible Class  |
| --------------- | ------------------ |
| List movies     | Cinema / main menu |
| Display shows   | Show               |
| Display seats   | Show               |
| Select seats    | BookingService     |
| Calculate price | PriceCalculator    |
| Pay             | Payment            |
| Book ticket     | BookingService     |
| Print ticket    | TicketPrinter      |
| Cancel booking  | BookingService     |
| Release seats   | ShowSeat           |

## Final Classes Identified

### Core Entity Classes

* Movie
* Seat
* Screen
* Cinema
* Show
* ShowSeat
* Customer
* Booking

### Behavior / Service Classes

* Payment
* UpiPayment
* CardPayment
* CashPayment
* PriceCalculator
* TicketPrinter
* BookingService

### Console Control

* main / Cinema menu

# Step 3: Relationship Analysis

| Class A        | Relationship | Class B     | Justification                                                                             |
| -------------- | ------------ | ----------- | ----------------------------------------------------------------------------------------- |
| Cinema         | Composition  | Screen      | Cinema owns its screens. If the Cinema is destroyed, its screens are also destroyed.      |
| Screen         | Composition  | Seat        | Screen owns its physical seats. If the Screen is destroyed, its seats are also destroyed. |
| Show           | Aggregation  | Movie       | A Movie can exist independently of a Show and can be used in multiple Shows.              |
| Show           | Aggregation  | Screen      | A Screen exists independently and can be used for different Shows.                        |
| Show           | Composition  | ShowSeat    | ShowSeats are created specifically for a Show and depend on that Show.                    |
| Booking        | Association  | Customer    | Customer exists independently of a Booking.                                               |
| Booking        | Aggregation  | ShowSeat    | ShowSeats belong to the Show and remain available even when a Booking is cancelled.       |
| Booking        | Association  | Payment     | Booking uses Payment but does not control the Payment object's lifetime.                  |
| Payment        | Inheritance  | UpiPayment  | UpiPayment is a type of Payment.                                                          |
| Payment        | Inheritance  | CardPayment | CardPayment is a type of Payment.                                                         |
| Payment        | Inheritance  | CashPayment | CashPayment is a type of Payment.                                                         |
| BookingService | Association  | Booking     | BookingService manages and creates bookings but does not own their lifetime.              |

## Relationship Meaning

* **Composition (◆)** – Strong ownership. Child depends on the parent.
* **Aggregation (◇)** – Weak ownership. Part can exist independently.
* **Association (──▶)** – Classes interact with each other.
* **Inheritance (──▷)** – Child class is a type of parent class.
## 7. SOLID Principles Mapping

### Single Responsibility Principle (SRP)
Each class has one major responsibility.

- Movie → stores movie information
- Seat → represents a physical seat
- ShowSeat → manages seat availability for a show
- PriceCalculator → calculates ticket price
- Payment → defines payment contract
- TicketPrinter → prints ticket
- BookingService → manages booking workflow

### Open/Closed Principle (OCP)
The system can be extended with a new payment method without modifying existing payment classes.

Example:

```text
Payment
 ├── UpiPayment
 ├── CardPayment
 ├── CashPayment
 └── NetBankingPayment   ← can be added later

## 8. Code Structure

The project follows a modular class-based structure.

```text
movie-ticket-booking-system/
│
├── docs/
│   └── Assignment.md
│
├── src/
│   ├── Movie.cpp
│   ├── Seat.cpp
│   ├── ShowSeat.cpp
│   ├── Screen.cpp
│   ├── Cinema.cpp
│   ├── Show.cpp
│   ├── Customer.cpp
│   ├── Booking.cpp
│   ├── Payment.cpp
│   ├── UpiPayment.cpp
│   ├── CardPayment.cpp
│   ├── CashPayment.cpp
│   ├── PriceCalculator.cpp
│   ├── TicketPrinter.cpp
│   ├── BookingService.cpp
│   └── main.cpp
│
└── uml/
    ├── class-diagram.puml
    └── sequence-diagram.puml