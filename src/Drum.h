//
// Created by Guglielmo Fratticioli on 17/08/19.
//
#ifndef MYTEST_DRUM_H
#define MYTEST_DRUM_H

#include "Subject.h"

#include <QMetaType>
#include <QMediaPlayer>

class Observer;

enum STEP_STATUS{
    OFF = 0,
    ON = 1,
};

enum MUTE_STATUS{
    NOMUTED = 0,
    MUTED = 1,
};

enum SOLO_STATUS{
    NOSOLO = 0,
    SOLO = 1,
};

class Drum: public Subject{
public:
    Drum();
    Drum(const Drum& drum);

    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notify() override;
    const std::list<Observer *> &getObservers() const;

    bool isChecked(int position);
    void editStep(int step);

    const STEP_STATUS *getGroove() const;
    SOLO_STATUS getSoloing() const;
    MUTE_STATUS getMuting() const;
    void setSoloing(SOLO_STATUS sStatus);
    void setMuting(MUTE_STATUS mStatus);

private:
    std::list<Observer*> observers;

    STEP_STATUS groove[16]{};
    SOLO_STATUS soloing;
    MUTE_STATUS muting;

    QMediaPlayer* mediaplayer; //FIXME
};
Q_DECLARE_METATYPE(Drum)
Q_DECLARE_METATYPE(Drum*)

#endif //MYTEST_DRUM_H
