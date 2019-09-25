//
// Created by misterm on 11/05/19.
//

#include "Player.h"
#include <QTimer>
#include <QMediaPlayer>

Player::Player()
        : QObject(), metronome(new Metronome()), timer(new QTimer()), mediaPlayer(new QMediaPlayer()) {
    firstStep = true;
    timer->stop();
    setStatus(OFF);
    setActualStep(0);
    setBpm(120);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(PLAY()));
    qDebug() << "Player constructed";
}

void Player::notify() {
    for (Observer *observer : observers)
        observer->obsUpdate();
    qDebug() << "PlayerWidget notified";
}

void Player::addObserver(Observer *o) {
    qDebug() << "Observer added";
    observers.push_back(o);
}

void Player::removeObserver(Observer *o) {
    qDebug() << "Observer removed";
    observers.remove(o);
}

void Player::setBpm(int bpm) {
    this->bpm = bpm;
    notify();
    qDebug()<< bpm;
}

int Player::fromBpmToMillisec() {
    return (60000 / getBpm()) / 4;
}


void Player::playPauseTimer() {
    if (!getStatus()) {
        setStatus(ON);
        qDebug() << "State to ON";
        timer->start(fromBpmToMillisec());
        qDebug() << "Timer Start";
    } else {
        setStatus(OFF);
        qDebug() << "State to OFF";
        timer->stop();
        qDebug() << "Timer Stop";
    }
}

void Player::stopTimer() {
    setStatus(OFF);
    qDebug() << "State to OFF";
    timer->stop();
    setFirstStep(true);
    setActualStep(0);
}

void Player::PLAY() {

    bool foundSolo = false;
    for (auto i : drumKit->getDrums()) {
        if (i->getSoloState() == SOLO) {
            foundSolo = true;
            break;
        }
    }

    if (foundSolo) {
        for (auto i : drumKit->getDrums()) {
            if (i->isActive(actualStep) && (i->getSoloState() == SOLO))
                i->playDrum();
        }
    } else {
        for (auto i : drumKit->getDrums()) {
            if (i->isActive(actualStep))
                i->playDrum();
        }

        if ((actualStep % 4) == 0 && metronome->getStatus())
            metronome->doBeep();
    }

    setActualStep(((this->actualStep + 1) % 16));
}

Player::~Player() {
    //TODO IMPLEMENT destructor
    delete (timer);
    delete (mediaPlayer);
    delete (metronome);
    delete (drumKit);
}




