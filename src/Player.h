//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_PLAYER_H
#define DRUMMACHINE_PLAYER_H

#include "Metronome.h"
#include "Pattern.h"


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

    void play(const Metronome& metronome); /* play del metronomo*/
    void play(const Pattern& pattern); /*play totale*/
    void play(const Pattern& pattern, int index); /*play di una riga*/
    void play(const Percussions& percussions); /*play del sample*/

    void stop(const Metronome& metronome); /* stop del metronomo*/
    void stop(const Pattern& pattern); /*stop totale*/
    void stop(const Pattern& pattern, int index); /*stop di una riga*/
    void stop(const Percussions& percussions); /*stop del sample*/

    void pause();

    void scroll();

private:
    short int BPM;
    short int volume;
    short int actualBeat;
};


#endif //DRUMMACHINE_PLAYER_H
