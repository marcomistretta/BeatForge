//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_METRONOME_H
#define DRUMMACHINE_METRONOME_H

#include <QtGui/QtGui>
#include <QtMultimedia/QMediaPlayer>
#include "Subject.h"
#include "Enum.h"

class Metronome : public QTimer, public Subject {
Q_OBJECT

public:
    //CONSTRUCTOR
    Metronome();

    //SUBJECT
    void notify() override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;

    //GETTER & SETTER
    ACTIVE_STATUS getStatus() const;
    void setStatus(ACTIVE_STATUS state);

public slots:
    void doBeep();

private:
    std::list<Observer *> observers;
    ACTIVE_STATUS status;
    QMediaPlayer *mediaplayer;
};


#endif //DRUMMACHINE_METRONOME_H
