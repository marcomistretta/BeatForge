//
// Created by misterm on 11/05/19.
//

#include <QtMultimedia/QSound>
#include "Metronome.h"
#include <QDebug>


Metronome::Metronome() {
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(doBeep()));
    state = OFF;
    bpm = 60;
    qDebug() << "Metronome constructed";
    timer = new QTimer;
    mediaPlayer = new QMediaPlayer;
    mute = NOMUTED;


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

void Metronome::startStop() {
    if (!getState()) {
        setState(ON);
        qDebug() << "State to ON";
        timer->start(fromBpmToMillisec());
        qDebug() << "Timer Start";
    } else {
        setState(OFF);
        qDebug() << "State to OFF";
        timer->stop();
        qDebug() << "Timer Stop";
    }
}

int Metronome::fromBpmToMillisec() {
    return (60000 / getBpm());
}

void Metronome::doBeep() {
    mediaPlayer->setMedia(QUrl::fromLocalFile("/home/misterm/Scrivania/DrumMachine/0609/res/beeps/start.wav"));
    mediaPlayer->play();
    qDebug() << "Metronome played";
}
