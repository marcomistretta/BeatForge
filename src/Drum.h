//
// Created by Guglielmo Fratticioli on 17/08/19.
//
#ifndef MYTEST_DRUM_H
#define MYTEST_DRUM_H

#include "Subject.h"
#include "Enum.h"
#include <QMetaType>
#include <QObject>

class QMediaPlayer;
class Observer;

class Drum :public Subject{

public:
    Drum();

    Drum(const Drum &drum);

    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notify() override;

    bool isActive(int step){
        return groove[step] == ON;
    }
    void playDrum();
    void editStep(int step);
    void updatePath();

    const std::list<Observer *> &getObservers() const {
        return observers;
    }
    const ACTIVE_STATUS *getGroove() const {
        return groove;
    }
    QMediaPlayer *getMediaPlayer() const {
        return mediaplayer;
    }
    SOLO_STATUS getSoloState() const {
        return soloState;
    }
    MUTE_STATUS getMuteState() const {
        return muteState;
    }
    DRUM_STYLE getDrumStyle() const {
        return drumStyle;
    }
    DRUM_TYPE getDrumType() const {
        return drumType;
    }
    int getVolume() const{
        return volume;
    }
    void setMediaPlayer(QMediaPlayer *mPlayer) {
        Drum::mediaplayer = mPlayer;
    }
    void setSoloState(SOLO_STATUS sStatus);
    void setMuteState(MUTE_STATUS mStatus);
    void  setDrumStyle(DRUM_STYLE style);
    void setDrumType(DRUM_TYPE type);
    void setVolume(int volume);

private:
    std::list<Observer *> observers;

    int volume;
    ACTIVE_STATUS groove[16];
    SOLO_STATUS soloState;
    MUTE_STATUS muteState;
    DRUM_STYLE drumStyle;
    DRUM_TYPE drumType;
    QMediaPlayer *mediaplayer;

};


Q_DECLARE_METATYPE(Drum)

Q_DECLARE_METATYPE(Drum*)


#endif //MYTEST_DRUM_H
