//
// Created by Guglielmo Fratticioli on 17/08/19.
//
#ifndef MYTEST_DRUM_H
#define MYTEST_DRUM_H

#include "Subject.h"
#include <QMetaType>
//FIXME
#include <QMediaPlayer>

class Observer;

enum STEP_STATUS{
    ON = 1,
    OFF = 0,
};
//FIXME con l'aggiunta di SOLO_STATUS, ho deciso di togliere "SOLO = 1" da qui
enum MUTE_STATUS{
    MUTED = 0,
    NORMAL = 1,
};

//TODO: Ho cambiato PLAY_STATUS in SOLO_STATUS
enum SOLO_STATUS{
    FALSE = 0,
    TRUE = 1,
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
    std::list<Observer*> getObservers() const {
        return observers;
    };




private:
    //FIXME come test ho usato uno stesso sample in tutte le drum

    std::list<Observer*> observers;
    STEP_STATUS groove[16];
    QMediaPlayer* mediaplayer; //FIXME


};
Q_DECLARE_METATYPE(Drum)
Q_DECLARE_METATYPE(Drum*)

#endif //MYTEST_DRUM_H
