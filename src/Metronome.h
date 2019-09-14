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
    Metronome();

    void notify() override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;

    STATUS getStatus() const;

    void setStatus(STATUS state);

public slots:
    void doBeep();

private:
    std::list<Observer *> observers;
    STATUS status;
    QMediaPlayer *mediaplayer;
};


#endif //DRUMMACHINE_METRONOME_H
