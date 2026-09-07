#ifndef CINEMA_CPP
#define CINEMA_CPP

#include <string>
#include <vector>
using namespace std;

class Screen;

class Cinema {
private:
    string name;
    vector<Screen> screens;

public:
    Cinema(string name) {
        this->name = name;
    }

    void addScreen(Screen screen) {
        screens.push_back(screen);
    }

    string getName() {
        return this->name;
    }

    vector<Screen> getScreens() {
        return this->screens;
    }
};

#endif