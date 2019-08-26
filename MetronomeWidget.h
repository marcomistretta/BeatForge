//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#ifndef DRUM_MACHINE_METRONOMEWIDGET_H
#define DRUM_MACHINE_METRONOMEWIDGET_H

#include <QPushButton>
#include "Subject.h"
class Metronome;

class MetronomeWidget: public QPushButton, public Observer {
    Q_OBJECT
public:
    MetronomeWidget( QWidget * parent = nullptr);
    ~MetronomeWidget();
    void obsUpdate() override;
    void setBackground(QColor color);

private slots:
    void on_pressed();

private:
    Metronome * metronome;
};


#endif //DRUM_MACHINE_METRONOMEWIDGET_H
