# 🎬 Movie Ticket Booking System

> A modular, menu-driven **Movie Ticket Booking System** built in **C++** as a System Design project.

<p align="center">

**🎟️ Book Seats • 💳 Pay • 🧾 Get Ticket • ❌ Cancel**

</p>

---

## 🚀 Project Overview

This project simulates a **single-cinema movie ticket booking system** similar to a simplified PVR/INOX workflow.

The system demonstrates how **Object-Oriented Programming, UML, SOLID principles, abstraction, inheritance, polymorphism, composition, aggregation, and association** can be applied to design a real-world software system.

### 🎯 Main Workflow

```text
Customer
   │
   ▼
Select Movie
   │
   ▼
Select Show
   │
   ▼
View Seat Layout
   │
   ▼
Select Seats
   │
   ▼
Calculate Price
   │
   ▼
Choose Payment
   │
   ├───────────────┐
   ▼               ▼
Success          Failed
   │               │
   ▼               ▼
Confirm         Release Seats
Booking         Booking Failed
   │
   ▼
Print Ticket
```

---

## ✨ Features

| Feature                             | Status |
| ----------------------------------- | :----: |
| 🎬 List currently playing movies    |    ✅   |
| 🕐 View movie shows                 |    ✅   |
| 💺 Display seat availability        |    ✅   |
| 🎟️ Book one or multiple seats      |    ✅   |
| 💰 Seat-type based pricing          |    ✅   |
| 📱 UPI Payment                      |    ✅   |
| 💳 Card Payment                     |    ✅   |
| 💵 Cash Payment                     |    ✅   |
| ⚠️ Payment failure handling         |    ✅   |
| 🧾 Ticket generation                |    ✅   |
| 🔢 Automatic Booking ID             |    ✅   |
| ❌ Cancel booking                    |    ✅   |
| 🔄 Release seats after cancellation |    ✅   |

---

## 💰 Seat Pricing

| Seat Type   | Price |
| ----------- | ----: |
| 🩶 SILVER   |  ₹150 |
| 🟨 GOLD     |  ₹250 |
| 🟪 PLATINUM |  ₹400 |

---

## 🎬 Demo Movies

The current demo contains:

| Movie           | Language | Duration |   Screen | Show    |
| --------------- | -------- | -------: | -------: | ------- |
| 🚀 Interstellar | English  |  169 min | Screen 1 | 6:00 PM |
| 🎥 Kantara      | Kannada  |  148 min | Screen 2 | 7:30 PM |

---

## 🧠 System Design

### Core Entities

```text
Cinema
  │
  ├── Screen
  │     └── Seat
  │
  └── Show
        ├── Movie
        └── ShowSeat
              │
              └── Seat
```

### Booking Layer

```text
Customer
    │
    ▼
BookingService
    │
    ├── PriceCalculator
    │
    ├── Payment
    │      ├── UpiPayment
    │      ├── CardPayment
    │      └── CashPayment
    │
    ├── Booking
    │
    └── TicketPrinter
```

---

## 🏗️ Architecture

The system is divided into three logical layers:

### 1️⃣ Entity Layer

Responsible for representing the core objects.

```text
Movie
Seat
Screen
Cinema
Show
ShowSeat
Customer
Booking
```

### 2️⃣ Service Layer

Responsible for business operations.

```text
BookingService
PriceCalculator
TicketPrinter
```

### 3️⃣ Payment Layer

Uses abstraction and runtime polymorphism.

```text
          Payment
             ▲
     ┌───────┼────────┐
     │       │        │
   UPI     Card      Cash
```

---

## 📐 UML Diagrams

### Class Diagram

<p align="center">

![Class Diagram](uml/class-diagram.png)

</p>

### Sequence Diagram

<p align="center">

![Sequence Diagram](uml/sequence-diagram.png)

</p>

---

<details>
<summary>🔍 Click to see the main class responsibilities</summary>

| Class             | Responsibility                |
| ----------------- | ----------------------------- |
| `Movie`           | Stores movie information      |
| `Seat`            | Represents a physical seat    |
| `Screen`          | Owns physical seats           |
| `Cinema`          | Owns screens                  |
| `Show`            | Represents a movie screening  |
| `ShowSeat`        | Tracks seat status for a show |
| `Customer`        | Stores customer information   |
| `Booking`         | Represents a ticket booking   |
| `Payment`         | Abstract payment contract     |
| `UpiPayment`      | UPI payment implementation    |
| `CardPayment`     | Card payment implementation   |
| `CashPayment`     | Cash payment implementation   |
| `PriceCalculator` | Calculates ticket price       |
| `TicketPrinter`   | Prints ticket                 |
| `BookingService`  | Coordinates booking workflow  |

</details>

---

## 🧩 OOP Concepts Demonstrated

<details>
<summary>Click to expand</summary>

### 🔒 Encapsulation

Important data members are private and accessed through controlled methods.

```cpp
private:
    string status;
```

---

### 🎭 Abstraction

Payment is represented using an abstract class.

```cpp
class Payment {
public:
    virtual bool pay(double amount) = 0;
};
```

---

### 🧬 Inheritance

```text
Payment
   ▲
   ├── UpiPayment
   ├── CardPayment
   └── CashPayment
```

---

### 🔄 Runtime Polymorphism

```cpp
Payment* selectedPayment;
```

The actual payment implementation is selected at runtime.

---

### 🏗️ Static Members

Booking IDs are generated using a static member.

```cpp
static int nextBookingId;
```

---

### 👉 `this` Keyword

Used to distinguish class attributes from constructor parameters.

```cpp
this->title = title;
```

---

### 💠 Composition

Strong ownership relationships:

```text
Cinema ◆── Screen
Screen ◆── Seat
Show ◆── ShowSeat
```

---

### ◇ Aggregation

Objects can exist independently:

```text
Show ◇── Movie
Show ◇── Screen
Booking ◇── ShowSeat
```

</details>

---

## 🧱 SOLID Principles

<details>
<summary>Click to expand SOLID mapping</summary>

| Principle   | Implementation                                                             |
| ----------- | -------------------------------------------------------------------------- |
| **S — SRP** | Each class has a focused responsibility                                    |
| **O — OCP** | New payment methods can be added without changing existing payment classes |
| **L — LSP** | Payment subclasses can replace `Payment`                                   |
| **I — ISP** | Payment exposes only the common `pay()` operation                          |
| **D — DIP** | `BookingService` depends on `Payment` abstraction                          |

### Example: Adding a New Payment Method

A new payment method such as:

```text
NetBankingPayment
```

can inherit from:

```text
Payment
```

without modifying the existing payment implementations.

### Deliberately Omitted

💸 **Refund System**

Refund processing is outside the scope of this assignment. Cancellation releases the seats but does not process monetary refunds.

</details>

---

## 📂 Project Structure

```text
movie-ticket-booking-system/
│
├── 📄 README.md
│
├── 📁 docs/
│   └── Assignment.md
│
├── 📁 src/
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
└── 📁 uml/
    ├── class-diagram.puml
    ├── class-diagram.png
    ├── sequence-diagram.puml
    └── sequence-diagram.png
```

---

## ▶️ How to Run

### Prerequisites

* C++ compiler
* Git
* VS Code or any C++ IDE

### Compile

```bash
g++ src/main.cpp -o movie_booking
```

### Run — Windows

```bash
.\movie_booking
```

---

## 🖥️ Menu

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

## 🎟️ Sample Booking

```text
===== BOOK TICKET =====

Choose show: 1
Enter number of seats: 2
Enter seat 1: A2
Enter seat 2: B2

===== PAYMENT METHOD =====
1. UPI
2. Card
3. Cash

Choose payment method: 2

Processing Card payment of Rs. 400...
```

### Generated Ticket

```text
========== MOVIE TICKET ==========

Booking ID: 1001
Movie: Interstellar
Screen: 1
Time: 6:00 PM
Seats: A2 B2
Total Amount: Rs. 400
Status: CONFIRMED

==================================
```

---

## 🧪 Tested Scenarios

| Scenario                         |       Result       |
| -------------------------------- | :----------------: |
| Valid single-seat booking        |          ✅         |
| Multiple-seat booking            |          ✅         |
| Silver pricing                   |          ✅         |
| Gold pricing                     |          ✅         |
| Platinum pricing                 |          ✅         |
| Already-booked seat              |     ✅ Rejected     |
| Successful UPI payment           |          ✅         |
| Successful Card payment          |          ✅         |
| Successful Cash payment          |          ✅         |
| Failed payment                   | ✅ Booking rejected |
| Failed payment releases seats    |          ✅         |
| Booking cancellation             |          ✅         |
| Cancelled seats become available |          ✅         |

---

## 🛡️ Design Decisions

### Why `Seat` and `ShowSeat` are separate?

A `Seat` represents the **physical chair**.

A `ShowSeat` represents that chair's **status for a particular show**.

For example:

```text
Physical Seat: A1

Interstellar → A1 → BOOKED
Kantara      → A1 → AVAILABLE
```

The same physical seat can therefore have different availability for different shows.

---

## 🔮 Future Improvements

Possible extensions include:

* 🔐 User authentication
* 💳 Real payment gateway integration
* 💸 Refund processing
* 🗄️ Database persistence
* 🎫 QR-code tickets
* 📧 Email ticket delivery
* 🌐 Web interface
* 📱 Mobile application
* 🏢 Multiple cinema support
* 📊 Admin dashboard

---

## 📚 Documentation

Detailed assignment documentation is available here:

➡️ [`docs/Assignment.md`](docs/Assignment.md)

---

## 👩‍💻 Author

**Dixa**

B.Tech CSE — AI & ML

---

## ⭐ If you found this project interesting

Feel free to explore the code, UML diagrams, and system design documentation.

**Built with C++ • OOP • UML • SOLID Principles**

---
