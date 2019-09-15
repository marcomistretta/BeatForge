//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#include "MetronomeWidget.h"
#include "Metronome.h"
#include <QDir>
#include <QDebug>

MetronomeWidget::MetronomeWidget(Metronome* metronome,QWidget *parent) : Observer(), metronome(metronome) {
    metronome->addObserver(this);
    this->setStyleSheet(QString("background: transparent"));
    metronome->setStatus(OFF);
    qDebug() << "Metronome Widget constructed";

    //connecting methods
    connect(this, SIGNAL(clicked()), this, SLOT(on_pressed()));
}

MetronomeWidget::~MetronomeWidget() {
    delete (metronome);
    qDebug() << "Metronome deleted";
}

void MetronomeWidget::obsUpdate() {
    qDebug() << "MetroWidget Updated";
    QIcon metronomeicon;
    if (metronome->getStatus()) {
        //red
        metronomeicon.addFile(QString("../res/icons/Metronome-ON"));
        qDebug() << "to Red";
    } else {
        //light-green
        metronomeicon.addFile(QString("../res/icons/Metronome-OFF"));
        qDebug() << "to light green";
    }
    this->setIcon(metronomeicon);
    this->setIconSize(this->size());
}


void MetronomeWidget::on_pressed() {
    qDebug() << "Metronome pressed";
    obsUpdate();
    if (metronome->getStatus() == STATUS::ON) {
        metronome->setStatus(OFF);
    } else {
        metronome->setStatus(ON);
    }
}


