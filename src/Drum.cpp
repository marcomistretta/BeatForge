//
// Created by Guglielmo Fratticioli on 17/08/19.
//

#include "Drum.h"
#include "Observer.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QAction>
#include <QMenu>
Drum::Drum(): drumStyle(POP),mediaplayer(new QMediaPlayer()), muteState(NOMUTED),soloState(NOSOLO), volume(100){

    for (auto & i : groove)
        i = OFF;

    qDebug() << "Drum constructed";
}

Drum::Drum(const Drum &drum) {
    for (int i = 0; i < 16; i++)
        groove[i] = drum.getGroove()[i];
    observers = drum.getObservers();
    mediaplayer = drum.getMediaPlayer();
    soloState = drum.getSoloState();
    muteState = drum.getMuteState();
}

void Drum::addObserver(Observer *o) {
    observers.push_back(o);
    qDebug() << "Observer pushed";
}
void Drum::removeObserver(Observer *o) {
    observers.remove(o);
    qDebug() << "Observer removed";
}
void Drum::notify() {
    for (Observer *observer : observers)
        observer->obsUpdate();
    qDebug() << "Observer notified";
}

void Drum::editStep(int step) {
    qDebug() << "editStep";
    if (groove[step] == ON)
        groove[step] = OFF;
    else
        groove[step] = ON;
    notify();
}
void Drum::playDrum() {
    if(getMuteState() == NOMUTED) {
        mediaplayer->play();
        qDebug() << "Drum played";
    } else qDebug() << "Drum is muted";
}
void Drum::updatePath() {
    QString strType;
    QString strStyle;
    switch (drumType){
        case KICK: {strType = QString("KICK");}
        //.......
    }
    switch(drumStyle){
        case POP: {strStyle = QString("POP");}
        //.......
    }
    mediaplayer->setMedia(QUrl::fromLocalFile(QString("/home/gege/Scrivania/Drum-Machine/res/samples/%1-%2.wav").arg(strType).arg(strStyle)));
} //TODO GENERAL PATH
//NB Uso di %1 e %2 per composizione del nome del file


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
}
void Drum::setDrumType(DRUM_TYPE type) {
    drumType = type;
    updatePath();
    this->notify();
    qDebug()<< "Type changed";
}
void Drum::setVolume(int volume) {
    this->volume = volume;
    notify();
}