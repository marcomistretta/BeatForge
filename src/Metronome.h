//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_METRONOME_H
#define DRUMMACHINE_METRONOME_H

#include <QtGui/QtGui>
#include "Subject.h"

enum STATE {
    ON = 1,
    OFF = 0,
};

class Metronome: public Subject {

/*TODO
signals
    void updateLCD(int);
    */

public:
    Metronome();

    void notify() override;
    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;

    //GETTER & SETTER
    STATE getState() const;

    void setState(STATE state);

    int getBpm() const;

    void setBpm(int bpm);

private:
    std::list<Observer*> observers;
    STATE state;
    //TODO
    int bpm;
    QTimer *timer;


};


#endif //DRUMMACHINE_METRONOME_H
