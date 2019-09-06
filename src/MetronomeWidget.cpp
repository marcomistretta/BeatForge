//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#include "MetronomeWidget.h"
#include "Metronome.h"
#include <QDir>
#include <QDebug>

MetronomeWidget::MetronomeWidget( QWidget *parent): Observer(), metronome(new Metronome()) {
    //adding observer
    metronome->addObserver(this);
    //Setting the icon
    QString currentPath = QDir::currentPath();
    QIcon icon;
    icon.addFile(QString("../res/icons/metronome.png"));
    this->setIcon(icon);
    //connecting methods
    connect(this,SIGNAL(clicked()), this, SLOT(on_pressed()));
    qDebug()<<"Metronome Widget constructed";
}
MetronomeWidget::~MetronomeWidget() {
    delete(metronome);
    qDebug()<<"Metronome deleted";
}
void MetronomeWidget::obsUpdate() {
    qDebug()<<"MetroWidget Updated";
    if(metronome->isActive())
        //red
        this->setBackground(QColor(217, 0, 0));
    else
        //light-green
        this->setBackground(QColor(132, 176, 132));
}
void MetronomeWidget::setBackground(QColor color) {
    qDebug()<<"Backgroud changed";
    this->setStyleSheet(QString("background-color: %1").arg(color.name()));
}
void MetronomeWidget::on_pressed() {
    qDebug()<<"Metronome pressed";
    if (metronome->getState() == STATE::ON)
        metronome->setState(OFF);
    else
        metronome->setState(ON);
}