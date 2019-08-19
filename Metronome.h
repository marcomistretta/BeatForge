//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_METRONOME_H
#define DRUMMACHINE_METRONOME_H

#include <vector>
#include <QtCore/QTimer>

class Metronome : public QTimer {
public:

    bool isMute1() const {
        return isMute;
    }

    void setIsMute(bool isMute) {
        Metronome::isMute = isMute;
    }

    const std::vector<int> &getAccents() const {
        return accents;
    }

    void setAccents(const std::vector<int> &accents) {
        Metronome::accents = accents;
    }

    int getBpm() const {
        return Bpm;
    }

    void setBpm(int bpm) {
        Bpm = bpm;
    }

    void timerEvent(QTimerEvent *event) override;

    void beep();

private:
    bool isMute;
    std::vector<int> accents;
    int Bpm;


};


#endif //DRUMMACHINE_METRONOME_H
