//
// Created by misterm on 11/05/19.
//

#include <QtMultimedia/QSound>
#include "Metronome.h"

void Metronome::beep() {
    QString path = QString("/home/gege/samples/Ragers_Lofi Noiiz/Single Hit/Hi Hats/Hat01.wav");
    QSound::play(path);
}

void Metronome::timerEvent(QTimerEvent *event) {
    beep();
}

