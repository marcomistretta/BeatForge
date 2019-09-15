//
// Created by misterm on 11/05/19.
//

#include "Player.h"
#include <QTimer>
#include <QMediaPlayer>

Player::Player(): QObject(), timer(new QTimer()), mediaPlayer(new QMediaPlayer()), actualStep(0) {

    timer->stop();
    state = OFF;
    setBpm(60);
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

/*
void Player::PLAY() {
}*/



