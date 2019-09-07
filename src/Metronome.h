//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_METRONOME_H
#define DRUMMACHINE_METRONOME_H

#include <QtGui/QtGui>
#include <QtMultimedia/QMediaPlayer>
#include "Subject.h"


enum STATE {
    ON = 1,
    OFF = 0,
};

enum MUTE_STATUS {
    NOMUTED = 0,
    MUTED = 1,
};

class Metronome : public QTimer, public Subject {
Q_OBJECT

public:
    Metronome();

    void notify() override;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    //GETTER & SETTER
    STATE getState() const;

    void setState(STATE state);

    int getBpm() const;

    void setBpm(int bpm);

    int fromBpmToMillisec();

public slots:

    void doBeep();

    void startStop();



private:
    std::list<Observer *> observers;
    STATE state;

    //TODO
    int bpm;
    QTimer *timer;
    MUTE_STATUS mute;
    QMediaPlayer *mediaPlayer;

};


#endif //DRUMMACHINE_METRONOME_H
