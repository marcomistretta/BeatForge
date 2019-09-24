//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#ifndef DRUM_MACHINE_METRONOMEWIDGET_H
#define DRUM_MACHINE_METRONOMEWIDGET_H

#include <QPushButton>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QSlider>
#include <QWidget>

#include "Subject.h"
#include "Metronome.h"
class MyDial;
class QHBoxLayout;
class MetronomeWidget: public QWidget, public Observer {
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
    void on_volume_changed();

private:
    Metronome *metronome;
    MyDial* volumeDial;
    QHBoxLayout* boxLayout;
    QPushButton* metronomeButton;

};


#endif //DRUM_MACHINE_METRONOMEWIDGET_H
