//
// Created by misterm on 11/05/19.
//

#include <QtMultimedia/QSound>
#include "Metronome.h"
#include <QDebug>

class MetronomeWidget;

Metronome::Metronome(): status(OFF) {
    mediaplayer = new QMediaPlayer;
    //TODO PATH
    mediaplayer->setMedia(QUrl::fromLocalFile("/home/misterm/Scrivania/DrumMachine/1709/res/beeps/start.wav"));
    qDebug() << "Metronome constructed";
}

void Metronome::notify() {
    for (Observer *observer : observers)
        observer->obsUpdate();
    qDebug() << "MetroWidget notified";
}

void Metronome::addObserver(Observer *o) {
    qDebug() << "Observer added";
    observers.push_back(o);
}

void Metronome::removeObserver(Observer *o) {
    qDebug() << "Observer removed";
    observers.remove(o);
}

ACTIVE_STATUS Metronome::getStatus() const {
    return status;
}

void Metronome::setStatus(ACTIVE_STATUS status) {
    Metronome::status = status;
    notify();
}

void Metronome::doBeep() {
    mediaplayer->play();
    qDebug() << "Beep";
    qDebug() << "Metronome played";
}
