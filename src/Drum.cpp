//
// Created by Guglielmo Fratticioli on 17/08/19.
//

#include "Drum.h"
#include "Observer.h"
#include <QDebug>
#include <QMediaPlayer>

Drum::Drum() {
    qDebug() << "Drum constructed";
    for (auto & i : groove)
        i = NOSTEP;
    mediaPlayer = new QMediaPlayer;
    soloState = NOSOLO;
    muteState = NOMUTED;
}

Drum::Drum(const Drum &drum) {
    for (int i = 0; i < 16; i++)
        groove[i] = drum.getGroove()[i];
    observers = drum.getObservers();
    mediaPlayer = drum.getMediaPlayer();
    soloState = drum.getSoloState();
    muteState = drum.getMuteState();
}

void Drum::addObserver(Observer *o) {
    observers.push_back(o);
    qDebug() << "Observer pushed";
}

void Drum::removeObserver(Observer *o) {
    observers.remove(o);
    qDebug() << "Observer removed";
}

void Drum::notify() {
    for (Observer *observer : observers)
        observer->obsUpdate();
    qDebug() << "Observer notified";
}

bool Drum::isChecked(int position) {
    return groove[position] == STEP;
}

void Drum::editStep(int step) {
    qDebug() << "editStep";
    if (groove[step] == STEP)
        groove[step] = NOSTEP;
    else
        groove[step] = STEP;
    notify();
}



