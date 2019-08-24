//
// Created by Guglielmo Fratticioli on 17/08/19.
//

#include "Drum.h"
#include "Observer.h"

#include <QDebug>

Drum::Drum() {
    qDebug() << "Drum constructed";
    //ho messo auto
    for (auto & i : groove)
        i = OFF;
    mediaplayer = new QMediaPlayer;
    soloing = NOSOLO;
    muting = NOMUTED;
}

//TODO copy mediaplayer
Drum::Drum(const Drum &drum) {
    for (int i = 0; i < 16; i++)
        groove[i] = drum.getGroove()[i];
    observers = drum.getObservers();

    soloing = drum.getSoloing();
    muting = drum.getMuting();
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

//FIXME ho semplificato la funzione isChecked
bool Drum::isChecked(int position) {
    return groove[position] == ON;
}

void Drum::editStep(int step) {
    qDebug() << "editStep";
    if (groove[step] == ON)
        groove[step] = OFF;
    else
        groove[step] = ON;
    notify();
}

SOLO_STATUS Drum::getSoloing() const {
    return soloing;
}

MUTE_STATUS Drum::getMuting() const {
    return muting;
}

void Drum::setSoloing(SOLO_STATUS sStatus) {
    Drum::soloing = sStatus;
}

void Drum::setMuting(MUTE_STATUS mStatus) {
    Drum::muting = mStatus;
}

const std::list<Observer *> &Drum::getObservers() const {
    return observers;
}

const STEP_STATUS *Drum::getGroove() const {
    return groove;
}

