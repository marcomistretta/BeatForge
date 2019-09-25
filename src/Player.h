//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_PLAYER_H
#define DRUMMACHINE_PLAYER_H

#include "Drum.h"
#include "DrumKit.h"
#include "Metronome.h"
#include "Subject.h"
#include "Enum.h"
#include <QObject>

class QMediaPlayer;

class QTimer;

class Player: public QObject, public Subject {

Q_OBJECT
public:
    //CONSTRUCTOR
    Player();

    //DESTRUCTOR
    virtual ~Player();

    //SUBJECT
    void notify() override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;

    //GETTER & SETTER
    int getBpm() const {
        return bpm;
    }

    short getActualBeat() const {
        return actualBeat;
    }
    ACTIVE_STATUS getStatus() const {
        return state;
    }
    int getActualStep() const {
        return actualStep;
    }
    void setStatus(ACTIVE_STATUS state) {
        this->state = state;
    }
    void setMetronome(Metronome *metronome) {
        this->metronome = metronome;
    }
    void setDrumKit(DrumKit *drumKit) {
        this->drumKit = drumKit;
    }
    void setActualStep(int actualStep) {
        this->actualStep = actualStep;
        notify();
    }
    bool isFirstStep() const {
        return firstStep;
    }
    void setFirstStep(bool firstStep) {
        Player::firstStep = firstStep;
    }

    //CONVERT BPM IN MILLISECONDS
    int fromBpmToMillisec();

public slots:
    void stopTimer();
    void playPauseTimer();
    void PLAY(); /*Global*/

private:
    std::list<Observer *> observers;
    ACTIVE_STATUS state;
    QTimer *timer;
    QMediaPlayer *mediaPlayer;
    Metronome *metronome;
    DrumKit *drumKit;

    int bpm;
    int actualStep;
    bool firstStep;
};
#endif //DRUMMACHINE_PLAYER_H
