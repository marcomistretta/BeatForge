//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_PLAYER_H
#define DRUMMACHINE_PLAYER_H

#include <QtGui/QtGui>
#include <QtMultimedia/QMediaPlayer>
#include "Subject.h"
#include "Enum.h"

#include "Metronome.h"
#include "DrumKit.h"

class Player : public Subject, public QTimer {
Q_OBJECT

public:
    Player();

    void notify() override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;


    STATUS getStatus() const;

    void setStatus(STATUS state);

    int getBpm() const;
    void setBpm(int bpm);
    int fromBpmToMillisec();

    static const QMetaObject &getStaticMetaObject();

    Metronome *getMetronome() const;

    void setMetronome(Metronome *metronome);

    DrumKit *getDrumKit() const;

    void setDrumKit(DrumKit *drumKit);



public slots:

    void startStopTimer();
    void PLAY(); /*Global*/
    void startStop(); /*for instruments*/
    void startStopMetronome(); /*for Metronome*/


private:
    std::list<Observer *> observers;
    STATUS state;

    int bpm;
    QTimer *timer;
    QMediaPlayer *mediaPlayer;

    Metronome *metronome;
    DrumKit *drumKit;
};



#endif //DRUMMACHINE_PLAYER_H
