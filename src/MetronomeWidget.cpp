//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#include "MetronomeWidget.h"
#include "Metronome.h"
#include "MyDial.h"
#include <QLabel>
#include <QDir>
#include <QDebug>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QMainWindow>
MetronomeWidget::MetronomeWidget(Metronome* metronome,QWidget *parent) :QWidget(parent), Observer(),metronome(metronome),
volumeDial(new MyDial(this)), boxLayout(new QHBoxLayout(this)), metronomeButton(new QPushButton(this))
{
    //TODO PATH
    dir = new QDir(QDir::currentPath());
    dir->cdUp();
    path = dir->absoluteFilePath("res/icons/");

    metronome->addObserver(this);
    metronomeButton->setFixedSize(this->width(),this->height()*2.8);
    connect(metronomeButton, SIGNAL(clicked()), this, SLOT(on_pressed()));
    obsUpdate();
    connect(volumeDial,SIGNAL(valueChanged(int)),this,SLOT(on_volume_changed()));
    boxLayout->addWidget(metronomeButton);
    boxLayout->addItem(new QSpacerItem(this->width()*20/100,height()));
    volumeDial->setFixedSize(this->width()*40/100,this->width()*40/100);
    boxLayout->addWidget(volumeDial);

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
        //TODO CHECK
        /*metronomeicon.addFile(QString("../res/icons/Metronome-ON"));*/
        metronomeicon.addFile(QString(path + "Metronome-ON.png"));
        qDebug() << "to Red";
    } else {
        //light-green
        //TODO CHECK
        /*metronomeicon.addFile(QString("../res/icons/Metronome-OFF"));*/
        metronomeicon.addFile(QString(path + "Metronome-OFF.png"));
        qDebug() << "to Green";
    }
    metronomeButton->setIcon(metronomeicon);
    metronomeButton->setIconSize(this->size());
    volumeDial->setValue(metronome->getVolume());

    volumeDial->getvolumeLabel()->setText(QString("%1").arg(metronome->getVolume()));
}


void MetronomeWidget::on_pressed() {
    qDebug() << "Metronome pressed";
    if (metronome->getStatus() == ACTIVE_STATUS::ON) {
        metronome->setStatus(OFF);
    } else {
        metronome->setStatus(ON);
    }
}

void MetronomeWidget::on_volume_changed() {
    metronome->setVolume(volumeDial->value());
}
