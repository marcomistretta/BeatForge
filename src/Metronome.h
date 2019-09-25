//
// Created by misterm on 11/05/19.
//

#ifndef DRUMMACHINE_METRONOME_H
#define DRUMMACHINE_METRONOME_H

#include <QtGui/QtGui>
#include <QtMultimedia/QMediaPlayer>
#include <QDir>
#include "Subject.h"
#include "Enum.h"

class Metronome : public QTimer, public Subject {
Q_OBJECT

public:
    //CONSTRUCTOR
    Metronome();

    //DESTRUCTOR
    virtual ~Metronome();

    //SUBJECT
    void notify() override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;

    //GETTER & SETTER
    int getVolume() const {
        return volume;
    }
    void setVolume(int volume);
    ACTIVE_STATUS getStatus() const;
    void setStatus(ACTIVE_STATUS state);

public slots:
    void doBeep();

private:
    std::list<Observer *> observers;
    ACTIVE_STATUS status;
    QMediaPlayer *mediaplayer;
    QDir *dir;
    QString path;
    int volume;
};


#endif //DRUMMACHINE_METRONOME_H
