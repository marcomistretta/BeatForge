//
// Created by Guglielmo Fratticioli on 17/08/19.
//
#ifndef MYTEST_DRUM_H
#define MYTEST_DRUM_H

#include "Subject.h"

#include <QMetaType>

class QMediaPlayer;
class Observer;

enum STEP_STATUS{
    OFF = 0,
    ON = 1,
};

enum MUTE_STATUS{
    NOMUTED = 0,
    MUTED = 1,
};

enum SOLO_STATUS{
    NOSOLO = 0,
    SOLO = 1,
};

class Drum: public Subject{
public:
    Drum();
    Drum(const Drum& drum);

    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notify() override;



    bool isChecked(int position);
    void editStep(int step);

    const STEP_STATUS *getGroove() const {
        return groove;
    }

    //GETTER & SETTER
    const std::list<Observer *> &getObservers() const;

    void setObservers(const std::list<Observer *> &observers);

    QMediaPlayer *getMediaPlayer() const {
        return mediaPlayer;
    }

    void setMediaPlayer(QMediaPlayer *mediaPlayer);

    SOLO_STATUS getSoloState() const {
         return soloState;
    };
    MUTE_STATUS getMuteState() const{
         return muteState; 
    };
    void setSoloState(SOLO_STATUS sStatus){
         soloState = sStatus;
    };
    void setMuteState(MUTE_STATUS mStatus){
         muteState = mStatus;
    };

private:
    std::list<Observer*> observers;

    STEP_STATUS groove[16]{};
    SOLO_STATUS soloState;
    MUTE_STATUS muteState;

    QMediaPlayer *mediaPlayer;
};

Q_DECLARE_METATYPE(Drum)
Q_DECLARE_METATYPE(Drum*)

#endif //MYTEST_DRUM_H
