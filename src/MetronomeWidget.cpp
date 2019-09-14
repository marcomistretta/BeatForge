//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#include "MetronomeWidget.h"
#include "Metronome.h"
#include <QDir>
#include <QDebug>

MetronomeWidget::MetronomeWidget(QWidget *parent) : Observer() {
    metronome = new Metronome;
    metronome->addObserver(this);
    //setting the icon
    QIcon icon;
    icon.addFile(QString("../res/icons/metronome.png"));
    this->setIcon(icon);

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
    if (metronome->getStatus()) {
        //red
        qDebug() << "to Red";
        this->setBackground(QColor(217, 0, 0));
    } else {
        //light-green
        qDebug() << "to light green";
        this->setBackground(QColor(132, 176, 132));
    }
}

void MetronomeWidget::setBackground(const QColor &color) {
    qDebug() << "Backgroud changed";
    this->setStyleSheet(QString("background-color: %1").arg(color.name()));


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

Metronome *MetronomeWidget::getMetronome() const {
    return metronome;
}

void MetronomeWidget::setMetronome(Metronome *metronome) {
    MetronomeWidget::metronome = metronome;
}

