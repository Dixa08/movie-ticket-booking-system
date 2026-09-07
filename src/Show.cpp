#ifndef SHOW_CPP
#define SHOW_CPP

#include <string>
#include <vector>
using namespace std;

class Movie;
class Screen;
class ShowSeat;

class Show {
private:
    Movie* movie;
    Screen* screen;
    string startTime;
    vector<ShowSeat*> showSeats;

public:
    Show(Movie* movie, Screen* screen, string startTime) {
        this->movie = movie;
        this->screen = screen;
        this->startTime = startTime;
    }

    void addShowSeat(ShowSeat* showSeat) {
        showSeats.push_back(showSeat);
    }

    Movie* getMovie() {
        return this->movie;
    }

    Screen* getScreen() {
        return this->screen;
    }

    string getStartTime() {
        return this->startTime;
    }

    vector<ShowSeat*> getShowSeats() {
        return this->showSeats;
    }
};

#endif