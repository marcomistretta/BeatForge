//
// Created by misterm on 11/05/19.
//

#include <QtMultimedia/QSound>
#include "Metronome.h"
#include <QDebug>


Metronome::Metronome() {
    timer = new QTimer;
    state = OFF;
    bpm = 60;
    qDebug()<<"Metronome constructed";
}

void Metronome::notify() {
    for(Observer * observer : observers)
        observer->obsUpdate();
    qDebug() << "MetroWidget notified";

}
void Metronome::addObserver(Observer *o) {
    qDebug()<<"Observer added";
    observers.push_back(o);
}
void Metronome::removeObserver(Observer *o) {
    qDebug()<<"Observer removed";
    observers.remove(o);
}

STATE Metronome::getState() const {
    return state;
}

void Metronome::setState(STATE state) {
    Metronome::state = state;
}

int Metronome::getBpm() const {
    return bpm;
}

void Metronome::setBpm(int bpm) {
    Metronome::bpm = bpm;
}

int Metronome::getBpm() const {
    return bpm;
}

void Metronome::setBpm(int bpm) {
    Metronome::bpm = bpm;
}
