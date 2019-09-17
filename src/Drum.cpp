//
// Created by Guglielmo Fratticioli on 17/08/19.
//

#include "Drum.h"
#include "Observer.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QAction>
#include <QMenu>

Drum::Drum() : drumType(KICK), drumStyle(POP), mediaplayer(new QMediaPlayer()), muteState(NOMUTED), soloState(NOSOLO),
               volume(100) {
    for (auto &i : groove)
        i = OFF;
    qDebug() << "Drum constructed";
    mediaplayer->setMedia(QUrl::fromLocalFile("/home/misterm/Scrivania/DrumMachine/1709/res/samples/KICK-POP.wav"));
    mediaplayer->setVolume(getVolume());
    notify();
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
    if (getMuteState() == NOMUTED) {
        //DOVREBBE ESSERE SUPERFLUO
        mediaplayer->stop();
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
            //strType = QString("KICK");
            //mediaplayer->stop();
            mediaplayer->setMedia(
                    QUrl::fromLocalFile("/home/misterm/Scrivania/DrumMachine/1709/res/samples/KICK-POP.wav"));
            break;
        }
        case SNARE: {
            strType = QString("SNARE");
            //mediaplayer->stop();
            //mediaplayer->setMedia(QUrl::fromLocalFile("/home/misterm/Scrivania/DrumMachine/1709/res/samples/SNARE-POP.wav"));
            break;
        }
        case HAT: {
            strType = QString("HAT");
            //mediaplayer->stop();
            //mediaplayer->setMedia(QUrl::fromLocalFile("/home/misterm/Scrivania/DrumMachine/1709/res/samples/HAT-POP.wav"));
            break;
        }
        case TOM: {
            strType = QString("TOM");
            //mediaplayer->stop();
            //mediaplayer->setMedia(QUrl::fromLocalFile("/home/misterm/Scrivania/DrumMachine/1709/res/samples/TOM-POP.wav"));
            break;
        }
    }

    switch (drumStyle) {
        case POP: {
            strStyle = QString("POP");
            break;
        }
    }
    mediaplayer->setMedia(QUrl::fromLocalFile(QString("/home/misterm/Scrivania/DrumMachine/1709/res/samples/%1-%2.wav").arg(strType).arg(strStyle)));
}
//mediaplayer->setMedia(QUrl::fromLocalFile("/home/misterm/Scrivania/DrumMachine/1709/res/samples/"+strType+"-"+strStyle+".waw"));
/*QString path1 = "/home/misterm/Scrivania/DrumMachine/1709/res/samples/";
QString path2 = strType +"-"+ strStyle;
QString path = path1+path2+".waw";
 mediaplayer->setMedia(QUrl::fromLocalFile(path));*/

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
    }

    void Drum::setDrumType(DRUM_TYPE type) {
        drumType = type;
        updatePath();
        notify();
        qDebug() << "Type changed";
        qDebug() << drumType;
    }

    void Drum::setVolume(int volume) {
        this->volume = volume;
        mediaplayer->setVolume(volume);
        notify();
    }