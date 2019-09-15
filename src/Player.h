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

    STATUS getStatus() const {
        return state;
    }
    int getactualStep() const {
        return actualStep;
    }

    void setActualStep(int actualStep) {
        this->actualStep = actualStep;
        notify();
    }

    void setStatus(STATUS state) {
        this->state = state;
    }
    void setMetronome(Metronome *metronome) {
        this->metronome = metronome;
    }
    void setDrumKit(DrumKit *drumKit) {
        this->drumKit = drumKit;
    }

public slots:
    void stopTimer();
    void playPauseTimer();
    void PLAY(); /*Global*/
    void startStop() {}; /*for instruments*/
    void startStopMetronome() {}; /*for Metronome*/

private:
    std::list<Observer *> observers;
    STATUS state;

    int bpm;
    int actualStep;
    QTimer *timer;
    QMediaPlayer *mediaPlayer;

    Metronome *metronome;
    DrumKit *drumKit;
};
#endif //DRUMMACHINE_PLAYER_H
