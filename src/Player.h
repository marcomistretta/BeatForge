//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_PLAYER_H
#define DRUMMACHINE_PLAYER_H
#include "Drum.h"
#include "DrumKit.h"
class QMediaPlayer;
class QTimer;

#include "Metronome.h"
#include "Subject.h"
#include "Enum.h"
#include <QObject>

class Player: public QObject, public Subject {

Q_OBJECT
public:
    Player();

    void notify() override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;

    int getBpm() const {
        return bpm;
    }
    void setBpm(int bpm) {
        this->bpm = bpm;
    }
    int fromBpmToMillisec();

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
    void playDrumSolo();

public slots:
    void stopTimer();
    void playPauseTimer();
    void PLAY(); /*Global*/
    //void startStop() {}; for instruments
    //void startStopMetronome() {}; for Metronome

private:
    std::list<Observer *> observers;
    ACTIVE_STATUS state;

    int bpm;
    int actualStep;
    QTimer *timer;
    QMediaPlayer *mediaPlayer;
    bool firstStep;

    Metronome *metronome;
    DrumKit *drumKit;
};
#endif //DRUMMACHINE_PLAYER_H
