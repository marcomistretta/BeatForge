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

class Drum: public Subject{
public:
    Drum();
    Drum(const Drum& drum);

    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notify() override;

    bool isChecked(int position);
    void editStep(int step);

    const STEP_STATUS *getGroove() const;
    const std::list<Observer *> &getObservers() const;
    void setObservers(const std::list<Observer *> &observers);

    QMediaPlayer *getMediaPlayer() const;
    void setMediaPlayer(QMediaPlayer *mediaPlayer);

    SOLO_STATUS getSoloState() const;

    MUTE_STATUS getMuteState() const;

    void setSoloState(SOLO_STATUS sStatus);

    void setMuteState(MUTE_STATUS mStatus);

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
