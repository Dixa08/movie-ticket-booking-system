# Movie Ticket Booking System — System Design Assignment

**Course:** System Design
**Subject Code:** TCS-504
**Semester:** 5th Semester
**Project:** Movie Ticket Booking System
**Language:** C++
**Type:** Menu-Driven Console Application

---

# 1. Requirement Analysis

The objective is to design and implement a small Movie Ticket Booking System for a single cinema.

The system allows customers to view movies and shows, check seat availability, book seats, make payments, print tickets, and cancel bookings.

## 1.1 Functional Requirements

### FR1 – List Movies

The system shall display all movies currently playing, including:

* Movie title
* Language
* Duration

### FR2 – View Shows

The system shall allow the customer to select a movie and view its available shows, including:

* Screen number
* Start time

### FR3 – View Seat Layout

The system shall allow the customer to select a show and display:

* Seat number
* Seat type
* Seat availability status

The status shall be either `AVAILABLE` or `BOOKED`.

### FR4 – Select Seats

The system shall allow the customer to select one or more available seats.

If a selected seat is already booked or does not exist, the system shall reject the selection without changing the existing seat status.

### FR5 – Calculate Price

The system shall calculate the total ticket price based on seat type.

| Seat Type | Price |
| --------- | ----: |
| SILVER    |  ₹150 |
| GOLD      |  ₹250 |
| PLATINUM  |  ₹400 |

### FR6 – Payment

The system shall support:

* UPI
* Card
* Cash

If payment fails:

* The booking shall not be confirmed.
* The selected seats shall be released.
* The seats shall become available again.

### FR7 – Print Ticket

After successful payment, the system shall print a ticket containing:

* Booking ID
* Movie name
* Screen number
* Show time
* Seat numbers
* Total amount
* Booking status

### FR8 – Cancel Booking

The system shall allow cancellation of a confirmed booking.

After cancellation, the seats associated with the booking shall become available again.

---

## 1.2 Non-Functional Requirements

### NFR1 – Modularity

The system should be divided into separate classes/modules, with each class having a clear responsibility.

### NFR2 – Extensibility

The payment system should allow new payment methods to be added without modifying existing payment implementations.

### NFR3 – Input Validation

Invalid menu choices, show selections, and seat numbers should be handled without crashing the program.

### NFR4 – Maintainability

The code should use meaningful names, clear class responsibilities, minimal duplication, and appropriate encapsulation.

---

# 2. Noun–Verb Analysis

Noun–Verb analysis is used to identify the important objects and behaviors in the system before designing the classes.

## 2.1 Noun Identification

| Noun        | Class? | Reason                                                                          |
| ----------- | :----: | ------------------------------------------------------------------------------- |
| Movie       |   Yes  | Stores title, language, and duration.                                           |
| Seat        |   Yes  | Represents a physical cinema seat.                                              |
| Screen      |   Yes  | Represents a cinema screen and owns physical seats.                             |
| Cinema      |   Yes  | Represents the cinema and owns screens.                                         |
| Show        |   Yes  | Represents a movie screening on a screen at a specific time.                    |
| ShowSeat    |   Yes  | Represents the status of a seat for a particular show.                          |
| Customer    |   Yes  | Stores customer information.                                                    |
| Booking     |   Yes  | Represents a customer's booking.                                                |
| Payment     |   Yes  | Defines the common payment contract.                                            |
| Ticket      |   No   | Ticket information is generated and printed by `TicketPrinter`.                 |
| Seat Layout |   No   | It is a representation of `ShowSeat` objects rather than an independent entity. |
| Price       |   No   | Price is calculated by `PriceCalculator`.                                       |

## 2.2 Verb / Behavior Identification

| Verb / Action   | Responsible Class  |
| --------------- | ------------------ |
| List movies     | Cinema / Main Menu |
| View shows      | Show / Main Menu   |
| Display seats   | Show               |
| Select seats    | BookingService     |
| Calculate price | PriceCalculator    |
| Pay             | Payment            |
| Book ticket     | BookingService     |
| Print ticket    | TicketPrinter      |
| Cancel booking  | BookingService     |
| Book a seat     | ShowSeat           |
| Release a seat  | ShowSeat           |

## 2.3 Final Classes Identified

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

* `main()` — provides the menu and handles user input.

---

# 3. Relationship Analysis

The relationships between classes are identified based on ownership, lifetime, and interaction.

| Class A        | Relationship | Class B         | Justification                                                                   |
| -------------- | ------------ | --------------- | ------------------------------------------------------------------------------- |
| Cinema         | Composition  | Screen          | Cinema owns its screens.                                                        |
| Screen         | Composition  | Seat            | Screen owns its physical seats.                                                 |
| Show           | Aggregation  | Movie           | A movie exists independently of a particular show.                              |
| Show           | Aggregation  | Screen          | A screen exists independently and can be used for different shows.              |
| Show           | Composition  | ShowSeat        | ShowSeats are created specifically for a show.                                  |
| ShowSeat       | Association  | Seat            | ShowSeat represents a physical Seat.                                            |
| Booking        | Association  | Customer        | Customer exists independently of a booking.                                     |
| Booking        | Association  | Show            | A booking is made for a particular show.                                        |
| Booking        | Aggregation  | ShowSeat        | Booking uses selected ShowSeats; the ShowSeats remain associated with the Show. |
| Payment        | Inheritance  | UpiPayment      | UpiPayment is a type of Payment.                                                |
| Payment        | Inheritance  | CardPayment     | CardPayment is a type of Payment.                                               |
| Payment        | Inheritance  | CashPayment     | CashPayment is a type of Payment.                                               |
| BookingService | Dependency   | Booking         | BookingService creates and manages bookings.                                    |
| BookingService | Dependency   | PriceCalculator | BookingService uses it to calculate the total price.                            |
| BookingService | Dependency   | Payment         | BookingService uses the Payment abstraction.                                    |
| BookingService | Dependency   | TicketPrinter   | BookingService uses it to print tickets.                                        |

## 3.1 Relationship Notation

### Composition — `◆`

Strong ownership relationship.

The child object is owned by the parent.

Examples:

```text
Cinema ◆── Screen
Screen ◆── Seat
Show ◆── ShowSeat
```

### Aggregation — `◇`

Weak ownership relationship.

The related object can exist independently.

Examples:

```text
Show ◇── Movie
Show ◇── Screen
Booking ◇── ShowSeat
```

### Association — `──▶`

Shows that two classes interact or are related without ownership.

Examples:

```text
Booking ──▶ Customer
Booking ──▶ Show
ShowSeat ──▶ Seat
```

### Dependency — `⇢`

Shows that one class temporarily uses another class.

Examples:

```text
BookingService ⇢ Payment
BookingService ⇢ PriceCalculator
BookingService ⇢ TicketPrinter
```

### Inheritance — `──▷`

Shows an "is-a" relationship.

```text
Payment
   △
   ├── UpiPayment
   ├── CardPayment
   └── CashPayment
```

---

# 4. Class Diagram

The class diagram represents the static structure of the Movie Ticket Booking System.

It shows:

* Classes
* Attributes
* Methods
* Visibility
* Relationships
* Multiplicity

## 4.1 Core Entity Classes

### Movie

Stores basic movie information:

* Title
* Language
* Duration

### Seat

Represents a physical seat in the cinema.

### Screen

Represents a cinema screen and owns its physical seats.

### Cinema

Represents the cinema and owns its screens.

### Show

Represents a movie being shown on a particular screen at a particular time.

### ShowSeat

Represents the status of a physical seat for one particular show.

### Customer

Stores customer information.

### Booking

Stores booking information such as booking ID, selected seats, total amount, and status.

## 4.2 Service Classes

### Payment

An abstract class that defines the common payment operation.

```cpp
virtual bool pay(double amount) = 0;
```

### UpiPayment, CardPayment, CashPayment

These classes inherit from `Payment` and provide different payment implementations.

### PriceCalculator

Calculates the total ticket price based on the selected seat types.

### TicketPrinter

Prints the ticket details.

### BookingService

Coordinates the complete booking and cancellation workflow.

## 4.3 Important Design Decision — Seat vs ShowSeat

`Seat` and `ShowSeat` are separate classes because they represent different concepts.

**Seat** represents the physical seat.

Example:

```text
A1
```

**ShowSeat** represents the status of that seat for a particular show.

For example:

```text
Interstellar Show → A1 → BOOKED
Kantara Show      → A1 → AVAILABLE
```

Therefore, the same physical seat can have a different availability status for different shows.

## 4.4 Class Diagram File

The PlantUML source is available at:

```text
uml/class-diagram.puml
```

The generated image is available at:

```text
uml/class-diagram.png
```

---

# 5. Sequence Diagram

The sequence diagram represents the interaction between the customer and system components during the ticket booking process.

## 5.1 Booking Flow

The main flow is:

```text
Customer
   ↓
BookingService
   ↓
Check Seat Availability
   ↓
Reserve Selected Seat
   ↓
PriceCalculator
   ↓
Payment
   ↓
Create Booking
   ↓
Confirm Booking
   ↓
TicketPrinter
   ↓
Customer
```

## 5.2 Successful Payment

When payment is successful:

1. The customer requests a booking.
2. `BookingService` checks seat availability.
3. The selected seats are temporarily booked.
4. `PriceCalculator` calculates the total amount.
5. `Payment` processes the payment.
6. A `Booking` object is created.
7. The booking is confirmed.
8. `TicketPrinter` prints the ticket.

## 5.3 Failed Payment

If payment fails:

1. Payment returns failure.
2. The booking is not confirmed.
3. The selected seats are released.
4. The seats become `AVAILABLE`.
5. The customer receives a booking failure message.

## 5.4 Sequence Diagram File

The PlantUML source is available at:

```text
uml/sequence-diagram.puml
```

The generated image is available at:

```text
uml/sequence-diagram.png
```

---

# 6. Modular Working Code

The project is implemented using separate C++ files for the major classes.

## 6.1 Project Structure

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
    ├── class-diagram.png
    ├── sequence-diagram.puml
    └── sequence-diagram.png
```

## 6.2 Compilation

The program can be compiled using:

```bash
g++ src/main.cpp -o movie_booking
```

## 6.3 Execution

On Windows PowerShell:

```bash
.\movie_booking
```

## 6.4 Main Menu

```text
===== MOVIE TICKET BOOKING =====

1. List Movies
2. View Shows
3. View Seats
4. Book Ticket
5. Cancel Booking
6. Exit

Enter your choice:
```

---

# 7. OOP Concepts Demonstrated

## 7.1 Encapsulation

Important data members are declared private and accessed through public methods.

Example:

```cpp
class ShowSeat {
private:
    string status;

public:
    bool isAvailable();
    void book();
    void release();
};
```

This prevents direct modification of the seat status from outside the class.

## 7.2 Abstraction

The `Payment` class is abstract and defines a common payment operation.

```cpp
class Payment {
public:
    virtual bool pay(double amount) = 0;
};
```

The actual payment implementation is provided by the derived classes.

## 7.3 Inheritance

The concrete payment classes inherit from `Payment`.

```text
Payment
   ▲
   ├── UpiPayment
   ├── CardPayment
   └── CashPayment
```

## 7.4 Runtime Polymorphism

A `Payment*` pointer can refer to different payment implementations.

```cpp
Payment* selectedPayment = &upiPayment;
```

The appropriate `pay()` implementation is called at runtime.

## 7.5 Compile-Time Polymorphism

The system uses overloaded methods/constructors where required to support different forms of object creation or operations.

## 7.6 Static Member

`Booking` uses a static member to generate booking IDs.

```cpp
static int nextBookingId;
```

Each new booking receives a new booking ID.

## 7.7 `this` Keyword

The `this` keyword is used in constructors to distinguish class attributes from parameters.

```cpp
this->title = title;
```

## 7.8 Composition

Composition represents strong ownership.

Examples:

```text
Cinema ◆── Screen
Screen ◆── Seat
Show ◆── ShowSeat
```

## 7.9 Aggregation

Aggregation represents a weaker relationship where the related object can exist independently.

Examples:

```text
Show ◇── Movie
Show ◇── Screen
Booking ◇── ShowSeat
```

## 7.10 Association

Association represents interaction between independent objects.

Examples:

```text
Booking ──▶ Customer
Booking ──▶ Show
ShowSeat ──▶ Seat
```

---

# 8. SOLID Principles Mapping

## 8.1 Single Responsibility Principle — SRP

Each class has one major responsibility.

Examples:

* `Movie` → stores movie information
* `Seat` → represents a physical seat
* `ShowSeat` → manages seat status
* `PriceCalculator` → calculates price
* `Payment` → defines payment contract
* `TicketPrinter` → prints tickets
* `BookingService` → coordinates booking operations

## 8.2 Open/Closed Principle — OCP

The payment system can be extended with new payment methods without modifying existing payment implementations.

For example:

```text
Payment
 ├── UpiPayment
 ├── CardPayment
 ├── CashPayment
 └── NetBankingPayment
```

A future `NetBankingPayment` class can inherit from `Payment`.

## 8.3 Liskov Substitution Principle — LSP

Every payment subclass can be used wherever a `Payment` object is expected.

```cpp
Payment* payment;
```

The pointer can refer to UPI, Card, or Cash payment objects.

## 8.4 Interface Segregation Principle — ISP

The `Payment` abstraction contains only the common operation required by all payment methods:

```cpp
virtual bool pay(double amount) = 0;
```

Unnecessary operations are not forced on the payment classes.

## 8.5 Dependency Inversion Principle — DIP

`BookingService` depends on the `Payment` abstraction rather than directly depending on a particular payment implementation.

```cpp
Payment* selectedPayment;
```

Therefore, different payment implementations can be used without changing the booking workflow.

## 8.6 Deliberately Omitted Feature

### Refund System

Refund processing is deliberately omitted because it is outside the scope of this assignment.

The system supports booking cancellation and seat release, but does not implement actual monetary refunds.

---

# 9. Testing and Demo

The system was tested for the major functional scenarios.

| Test Case                | Expected Result                     | Status |
| ------------------------ | ----------------------------------- | :----: |
| List movies              | Movies displayed                    |    ✅   |
| View shows               | Shows displayed                     |    ✅   |
| View seats               | Seat status displayed               |    ✅   |
| Book one seat            | Seat becomes booked                 |    ✅   |
| Book multiple seats      | All selected seats booked           |    ✅   |
| Book already-booked seat | Booking rejected                    |    ✅   |
| SILVER pricing           | ₹150                                |    ✅   |
| GOLD pricing             | ₹250                                |    ✅   |
| PLATINUM pricing         | ₹400                                |    ✅   |
| UPI payment              | Payment processed                   |    ✅   |
| Card payment             | Payment processed                   |    ✅   |
| Cash payment             | Payment processed                   |    ✅   |
| Failed payment           | Booking rejected and seats released |    ✅   |
| Ticket printing          | Ticket displayed                    |    ✅   |
| Cancel booking           | Booking cancelled                   |    ✅   |
| Cancelled seats          | Seats become available              |    ✅   |

---

# 10. Conclusion

The Movie Ticket Booking System demonstrates how a real-world problem can be converted into a structured software design before implementation.

The project applies **requirement analysis, noun–verb analysis, UML class and sequence diagrams, object-oriented programming, relationships between classes, SOLID principles, and modular C++ implementation**.

The final system successfully demonstrates the complete booking workflow from **movie selection to payment, ticket generation, and cancellation**.

The project also helped in understanding how concepts such as **composition, aggregation, abstraction, inheritance, and polymorphism** can be applied to a practical software system.
