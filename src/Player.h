//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_PLAYER_H
#define DRUMMACHINE_PLAYER_H

#include "Metronome.h"
#include "Pattern.h"

//OLD VERSION
/*
class Player {
public:
    short getBpm() const {
        return BPM;
    }

    void setBpm(short bpm) {
        BPM = bpm;
    }

    short getVolume() const {
        return volume;
    }

    void setVolume(short volume) {
        Player::volume = volume;
    }

    short getActualBeat() const {
        return actualBeat;
    }

    void setActualBeat(short actualBeat) {
        Player::actualBeat = actualBeat;
    }

    void play(const Metronome& metronome); //play del metronomo
    void play(const Pattern& pattern); //play totale
    void play(const Pattern& pattern, int index); //play di una riga
    void play(const Percussions& percussions); //play del sample

    void stop(const Metronome& metronome); // stop del metronomo
    void stop(const Pattern& pattern); //stop totale
    void stop(const Pattern& pattern, int index); //stop di una riga
    void stop(const Percussions& percussions); //stop del sample

    void pause();

    void scroll();

private:
    short int BPM;
    short int volume;
    short int actualBeat;
};
*/


#include <QtGui/QtGui>
#include <QtMultimedia/QMediaPlayer>
#include "Subject.h"


enum isPlaying {
    YES = 1,
    NO = 0,
};

class Player : public Subject {
Q_OBJECT

public:
    Player();

    void notify() override;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    //GETTER & SETTER
    STATE getState() const;

    void setState(STATE state);

    int getBpm() const;

    void setBpm(int bpm);

    int fromBpmToMillisec();

public slots:

    void PLAY(); /*Global*/
    void startStop();   /*for instruments*/
    void startStopMetronome();  /*for Metronome*/


private:
    std::list<Observer *> observers;
    isPlaying state;

    int bpm;
    QTimer *timer;
    QMediaPlayer *mediaPlayer;

};



#endif //DRUMMACHINE_PLAYER_H
