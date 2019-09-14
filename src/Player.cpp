//
// Created by misterm on 11/05/19.
//

#include "Player.h"


Player::Player() {
    timer = new QTimer;
    timer->stop();
    state = OFF;
    setBpm(60);
    mediaPlayer = new QMediaPlayer;
    connect(timer, SIGNAL(timeout()), this, SLOT(PLAY()));
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


int Player::fromBpmToMillisec() {
    return 60000 / getBpm();
}

/*
void Player::startStopTimer() {
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
}*/

int Player::getBpm() const {
    return bpm;
}

void Player::setBpm(int bpm) {
    Player::bpm = bpm;
}

STATUS Player::getStatus() const {
    return state;
}

void Player::setStatus(STATUS state) {
    Player::state = state;
}

/*
void Player::PLAY() {
}*/

Metronome *Player::getMetronome() const {
    return metronome;
}

void Player::setMetronome(Metronome *metronome) {
    Player::metronome = metronome;
}

DrumKit *Player::getDrumKit() const {
    return drumKit;
}

void Player::setDrumKit(DrumKit *drumKit) {
    Player::drumKit = drumKit;
}
