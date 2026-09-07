#ifndef PRICECALCULATOR_CPP
#define PRICECALCULATOR_CPP

#include <vector>
using namespace std;

#include "ShowSeat.cpp"

class PriceCalculator {
public:
    double calculate(vector<ShowSeat*> seats) {
        double total = 0;

        for (ShowSeat* seat : seats) {
            if (seat->getSeatType() == "SILVER") {
                total += 150;
            }
            else if (seat->getSeatType() == "GOLD") {
                total += 250;
            }
            else if (seat->getSeatType() == "PLATINUM") {
                total += 400;
            }
        }

        return total;
    }
};

#endif