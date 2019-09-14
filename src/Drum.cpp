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

const std::list<Observer *> &Drum::getObservers() const {
    return observers;
}

void Drum::setObservers(const std::list<Observer *> &obs) {
    Drum::observers = obs;
}

void Drum::setMediaPlayer(QMediaPlayer *mPlayer) {
    Drum::mediaPlayer = mPlayer;
}

const STEP_STATUS *Drum::getGroove() const {
    return groove;
}

QMediaPlayer *Drum::getMediaPlayer() const {
    return mediaPlayer;
}

SOLO_STATUS Drum::getSoloState() const {
    return SOLO;
}

MUTE_STATUS Drum::getMuteState() const {
    return NOMUTED;
}

void Drum::setSoloState(SOLO_STATUS sStatus) {
    soloState = sStatus;
}

void Drum::setMuteState(MUTE_STATUS mStatus) {
    muteState = mStatus;
}

