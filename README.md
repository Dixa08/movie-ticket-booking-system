# Movie Ticket Booking System

A menu-driven Movie Ticket Booking System developed in C++ as a System Design assignment.

## Features

- List currently playing movies
- View available shows
- Display seat layout and availability
- Book one or multiple seats
- Seat-based pricing
- UPI, Card, and Cash payment
- Payment failure handling
- Automatic booking ID generation
- Ticket printing
- Booking cancellation
- Seat availability restored after cancellation

## Seat Pricing

| Seat Type | Price |
|-----------|------:|
| SILVER | ₹150 |
| GOLD | ₹250 |
| PLATINUM | ₹400 |

## System Design

The project demonstrates:

- Encapsulation
- Abstraction
- Inheritance
- Runtime Polymorphism
- Compile-Time Polymorphism
- Static Members
- Composition
- Aggregation
- Association
- SOLID Principles

## Main Classes

### Core Entities

- Movie
- Seat
- Screen
- Cinema
- Show
- ShowSeat
- Customer
- Booking

### Services

- Payment
- UpiPayment
- CardPayment
- CashPayment
- PriceCalculator
- TicketPrinter
- BookingService

## Project Structure

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
