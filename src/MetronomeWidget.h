//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#ifndef DRUM_MACHINE_METRONOMEWIDGET_H
#define DRUM_MACHINE_METRONOMEWIDGET_H

#include <QPushButton>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QSlider>
#include "Subject.h"
#include "Metronome.h"

class MetronomeWidget: public QPushButton, public Observer {
    Q_OBJECT
public:
    explicit MetronomeWidget(Metronome* metronome, QWidget *parent = nullptr);
    ~MetronomeWidget();

    void obsUpdate() override;


    Metronome *getMetronome() const {
        return metronome;
    }


private slots:
    void on_pressed();


private:
    Metronome *metronome;

};


#endif //DRUM_MACHINE_METRONOMEWIDGET_H
