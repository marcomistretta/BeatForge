//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#include "MetronomeWidget.h"
#include "Metronome.h"
#include <QDir>
#include <QDebug>

MetronomeWidget::MetronomeWidget(Metronome* metronome,QWidget *parent) : Observer(), metronome(metronome) {
    this->setStyleSheet(QString("background: transparent"));
    metronome->addObserver(this);
    metronome->setStatus(ON);
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
        metronomeicon.addFile(QString("../res/icons/Metronome-OFF"));
        qDebug() << "to Red";
    } else {
        //light-green
        metronomeicon.addFile(QString("../res/icons/Metronome-ON"));
        qDebug() << "to Green";
    }
    this->setIcon(metronomeicon);
    this->setIconSize(this->size());
}


void MetronomeWidget::on_pressed() {
    qDebug() << "Metronome pressed";
    if (metronome->getStatus() == STATUS::ON) {
        metronome->setStatus(OFF);
    } else {
        metronome->setStatus(ON);
    }
}


