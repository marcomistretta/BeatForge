//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#include "MetronomeWidget.h"
#include "Metronome.h"
#include <QDir>
#include <QDebug>

MetronomeWidget::MetronomeWidget(Metronome* metronome,QWidget *parent) : Observer(), metronome(metronome) {
    //SETTING DEFAULT BACKGROUND
    this->setStyleSheet(QString("{background: transparent}"));

    //CONNECTING SUBJECT-OBSERVER
    metronome->addObserver(this);
    qDebug() << "Metronome Widget constructed";

    //CONNECTING METHODS
    connect(this, SIGNAL(clicked()), this, SLOT(on_pressed()));

    //UPDATE VIEW
    obsUpdate();
}

MetronomeWidget::~MetronomeWidget() {
    //TODO IMPLEMENT destructor
    delete (metronome);
    qDebug() << "Metronome deleted";
}

void MetronomeWidget::obsUpdate() {
    qDebug() << "MetronomeWidget Updated";
    QIcon metronomeicon;
    if (metronome->getStatus() == ON) {
        //red
        metronomeicon.addFile(QString("../res/icons/Metronome-ON"));
        qDebug() << "to Red";
    } else {
        //light-green
        metronomeicon.addFile(QString("../res/icons/Metronome-OFF"));
        qDebug() << "to Green";
    }
    this->setIcon(metronomeicon);
    this->setIconSize(this->size());
}


void MetronomeWidget::on_pressed() {
    qDebug() << "Metronome pressed";
    if (metronome->getStatus() == ACTIVE_STATUS::ON) {
        metronome->setStatus(OFF);
    } else {
        metronome->setStatus(ON);
    }
}


