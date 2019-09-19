//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#ifndef DRUM_MACHINE_METRONOMEWIDGET_H
#define DRUM_MACHINE_METRONOMEWIDGET_H

#include <QPushButton>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QSlider>
#include <QDir>
#include "Subject.h"
#include "Metronome.h"

class MetronomeWidget: public QPushButton, public Observer {
    Q_OBJECT
public:
    //CONSTRUCTOR
    explicit MetronomeWidget(Metronome* metronome, QWidget *parent = nullptr);

    //DESTRUCTOR
    virtual ~MetronomeWidget();

    //OBSERVER
    void obsUpdate() override;

    //GETTER
    Metronome *getMetronome() const {
        return metronome;
    }

private slots:
    void on_pressed();

private:
    Metronome *metronome;
    QDir *dir;
    QString path;
};

#endif //DRUM_MACHINE_METRONOMEWIDGET_H
