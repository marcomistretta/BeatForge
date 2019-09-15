//
// Created by Guglielmo Fratticioli on 17/08/19.
//
#ifndef MYTEST_DRUM_H
#define MYTEST_DRUM_H

#include "Subject.h"
#include "Enum.h"
#include <QMetaType>

class QMediaPlayer;

class Observer;

class Drum : public Subject {
public:
    Drum();

    Drum(const Drum &drum);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

    bool isChecked(int position);

    void editStep(int step);

    const std::list<Observer *> &getObservers() const {
        return observers;
    }

    const STEP_STATUS *getGroove() const {
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

    void setMediaPlayer(QMediaPlayer *mPlayer) {
        Drum::mediaplayer = mPlayer;
    }
    
    void setSoloState(SOLO_STATUS sStatus) {
        soloState = sStatus;
    }

    void setMuteState(MUTE_STATUS mStatus) {
        muteState = mStatus;
    }

    bool isActive(int step){
        return groove[step] == STEP;
    }

    void playDrum();

private:
    std::list<Observer *> observers;

    STEP_STATUS groove[16];
    SOLO_STATUS soloState;
    MUTE_STATUS muteState;

    QMediaPlayer *mediaplayer;
};


Q_DECLARE_METATYPE(Drum)

Q_DECLARE_METATYPE(Drum*)


#endif //MYTEST_DRUM_H
