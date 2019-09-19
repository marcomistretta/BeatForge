//
// Created by Guglielmo Fratticioli on 17/08/19.
//
//sono arrivato a main window.h escluso

#include "Drum.h"
#include "Observer.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QAction>
#include <QMenu>

//CONSTRUCTOR
Drum::Drum() : drumType(KICK), drumStyle(POP), mediaplayer(new QMediaPlayer()), muteState(NOMUTED), soloState(NOSOLO),
               volume(100) {
    for (auto &i : groove)
        i = OFF;
    qDebug() << "Drum constructed";

    updatePath();
    mediaplayer->setVolume(getVolume());
    notify();
}

//COPY CONSTRUCTOR
Drum::Drum(const Drum &drum) {
    for (int i = 0; i < 16; i++)
        groove[i] = drum.getGroove()[i];
    observers = drum.getObservers();
    mediaplayer = drum.getMediaPlayer();
    soloState = drum.getSoloState();
    muteState = drum.getMuteState();
    volume = drum.getVolume();
    drumStyle = getDrumStyle();
    drumType = getDrumType();
}

void Drum::addObserver(Observer *o) {
    observers.push_back(o);
    qDebug() << "Drum Observer pushed";
}

void Drum::removeObserver(Observer *o) {
    observers.remove(o);
    qDebug() << "Drum Observer removed";
}

void Drum::notify() {
    for (Observer *observer : observers)
        observer->obsUpdate();
    qDebug() << "Drum Observer notified";
}

void Drum::editStep(int step) {
    qDebug() << "Drum:: Step edited";
    if (groove[step] == ON)
        groove[step] = OFF;
    else
        groove[step] = ON;
    notify();
}

void Drum::playDrum() {
    //HELP DECREASING LATENCY
    mediaplayer->stop();
    if (getMuteState() == NOMUTED) {
        mediaplayer->play();
        qDebug() << "Drum played";
    } else
        qDebug() << "Drum is muted";
}

void Drum::updatePath() {
    QString strType;
    QString strStyle;
    switch (drumType) {
        case KICK: {
            strType = QString("KICK");
            break;
        }
        case SNARE: {
            strType = QString("SNARE");
            break;
        }
        case HAT: {
            strType = QString("HAT");
            break;
        }
        case TOM: {
            strType = QString("TOM");
            break;
        }
    }
    switch (drumStyle) {
        case POP: {
            strStyle = QString("POP");
            break;
        }
    }
    //LOAD AUDIO.WAW
    mediaplayer->setMedia(QUrl::fromLocalFile(
            QString("/home/misterm/Scrivania/DrumMachine/1709/res/samples/%1-%2.wav").arg(strType).arg(strStyle)));
}

//SETTER (NOTIFY THE OBSERVER)
void Drum::setMuteState(MUTE_STATUS mStatus) {
    muteState = mStatus;
    notify();
}

void Drum::setSoloState(SOLO_STATUS sStatus) {
    soloState = sStatus;
    notify();
}

void Drum::setDrumStyle(DRUM_STYLE style) {
    drumStyle = style;
    updatePath();
    notify();
    qDebug() << "DrumStyle changed to: " << drumStyle;
}

void Drum::setDrumType(DRUM_TYPE type) {
    drumType = type;
    updatePath();
    notify();
    qDebug() << "DrumType changed to: " << drumType;
}

void Drum::setVolume(int volume) {
    this->volume = volume;
    mediaplayer->setVolume(volume);
    notify();
}

Drum::~Drum() {
    delete (mediaplayer);
}
