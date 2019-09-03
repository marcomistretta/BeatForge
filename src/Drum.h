//
// Created by Guglielmo Fratticioli on 17/08/19.
//
#ifndef MYTEST_DRUM_H
#define MYTEST_DRUM_H

#include "Subject.h"
#include <QMetaType>

class Observer;

enum STEP_STATUS{
    ON = 1,
    OFF = 0,
};
enum MUTE_STATUS{
    MUTED = 0,
    SOLO = 1,
    NORMAL = 2,
};
enum PLAY_STATUS{
    PLAYING = 1,
    STOPPED = 0,
};

class Drum: public Subject{
public:
    Drum();
    Drum(const Drum& drum);

    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notify() override;
    bool isChecked(int position);
    void editStep(int step);

    const STEP_STATUS *getGroove() const {
        return groove;
    }
    std::list<Observer*> getObservers() const {
        return observers;
    };

private:
    std::list<Observer*> observers;
    STEP_STATUS groove[16];

};
Q_DECLARE_METATYPE(Drum)
Q_DECLARE_METATYPE(Drum*)

#endif //MYTEST_DRUM_H
