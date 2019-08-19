//
// Created by Guglielmo Fratticioli on 17/08/19.
//

#ifndef MYTEST_DRUM_H
#define MYTEST_DRUM_H


#include "Subject.h"
#include "Observer.h"
#include <QWidget>


enum STEP_STATUS{
    ON = 1,
    OFF = 0,
};
enum MUTE_STATUS{
    MUTED = 0,
    SOLO = 1,
    NORMAL = 2,
};
enum PLAY_STATUS{
    PLAYING = 1,
    STOPPED = 0,
};

class Drum: public Subject {

public:
    Drum(QWidget* parent);
    Drum(QWidget* parent , QString sample_Path);

    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notify() override;
    bool isChecked(int position);
    void editStep(int step);

    QString getName() const {
        return name;
    }
    void setName(QString name) {
        Drum::name = name;
    }
    QString getSamplePath() const {
        return sample_Path;
    }
    void setSamplePath(QString samplePath) {
        sample_Path = samplePath;
    }
    int getVolume() const {
        return volume;
    }
    void setVolume(int volume) {
        Drum::volume = volume;
    }
    const STEP_STATUS *getGroove() const {
        return groove;
    }
    MUTE_STATUS getMuteStatus() const {
        return muteStatus;
    }
    void setMuteStatus(MUTE_STATUS muteStatus) {
        Drum::muteStatus = muteStatus;
    }
    PLAY_STATUS getPlayStatus() const {
        return playStatus;
    }
    void setPlayStatus(PLAY_STATUS playStatus) {
        Drum::playStatus = playStatus;
    }

private:

    QString name;
    QString sample_Path;
    int volume;
    std::list<Observer*> Observers;

    STEP_STATUS groove[16];
    MUTE_STATUS muteStatus;
    PLAY_STATUS playStatus;

};


#endif //MYTEST_DRUM_H
