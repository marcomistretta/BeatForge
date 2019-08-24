//
// Created by Guglielmo Fratticioli on 17/08/19.
//

#include "Drum.h"
#include "Observer.h"
#include <QDebug>

Drum::Drum() {
    qDebug() << "Drum constructed";
    for (int i = 0; i < 16; i++)
        groove[i] = OFF;
    mediaplayer = new QMediaPlayer;
    soloing = NOSOLO;
    muting = NOMUTED;

}

//TODO copy mediaplayer solo mute
Drum::Drum(const Drum &drum) {
    for (int i = 0; i < 16; i++)
        groove[i] = drum.getGroove()[i];
    observers = drum.getObservers();
}

void Drum::addObserver(Observer *o) {
    observers.push_back(o);
    qDebug() << "Observer pushed";
}

void Drum::removeObserver(Observer *o) {
    observers.remove(o);
}

void Drum::notify() {
    for (Observer *observer : observers)
        observer->obsUpdate();
}

bool Drum::isChecked(int position) {
    if (groove[position] == OFF)
        return false;
    else
        return true;
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

void Drum::setSoloing(SOLO_STATUS soloing) {
    Drum::soloing = soloing;
}

void Drum::setMuting(MUTE_STATUS muting) {
    Drum::muting = muting;
}

