//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_METRONOME_H
#define DRUMMACHINE_METRONOME_H

#include "Subject.h"

enum State{
    ON = 1,
    OFF = 0,
};

class Metronome: public Subject {
public:
    Metronome();

    void notify() override;
    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    bool isActive();
    void setState(State state) {
        Metronome::state = state;
        notify();
    }
    State getState() const {
        return state;
    }

private:
    std::list<Observer*> observers;
    State state;
};


#endif //DRUMMACHINE_METRONOME_H
