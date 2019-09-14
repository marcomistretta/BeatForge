//
// Created by misterm on 11/05/19.
//

#include <QtMultimedia/QSound>
#include "Metronome.h"
#include <QDebug>

class MetronomeWidget;

Metronome::Metronome() {
    status = OFF;
    mediaplayer = new QMediaPlayer;
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

STATUS Metronome::getStatus() const {
    return status;
}

void Metronome::setStatus(STATUS status) {
    Metronome::status = status;
}

void Metronome::doBeep() {
    mediaplayer->setMedia(QUrl::fromLocalFile("../res/beeps/start.wav"));
    mediaplayer->play();
    qDebug() << "Beep";
    qDebug() << "Metronome played";
}
