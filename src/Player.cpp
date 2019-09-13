//
// Created by misterm on 11/05/19.
//

#include "Player.h"


Player::Player() {
    timer = new QTimer();
    timer->stop();
    state = NO;
    bpm = 60;
    mediaPlayer = new QMediaPlayer;
    connect(timer, SIGNAL(timeout()), this, SLOT(PLAY()));
    qDebug() << "Metronome constructed";

}

void Player::notify() {
    for (Observer *observer : observers)
        observer->obsUpdate();
    qDebug() << "MetroWidget notified";
}

void Player::addObserver(Observer *o) {
    qDebug() << "Observer added";
    observers.push_back(o);
}

void Player::removeObserver(Observer *o) {
    qDebug() << "Observer removed";
    observers.remove(o);
}

STATE Player::getState() const {
    return OFF;
}

void Player::setState(state) {
    Player::state = state;
}

int Player::fromBpmToMillisec() {
    return 0;
}


void Player::startStop() {
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
