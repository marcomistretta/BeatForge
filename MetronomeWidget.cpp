//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#include "MetronomeWidget.h"
#include "Metronome.h"
#include <QDir>
#include <QDebug>
MetronomeWidget::MetronomeWidget( QWidget *parent): Observer(), metronome(new Metronome()) {
    metronome->addObserver(this);                                                                          //adding observer
    QString currentPath = QDir::currentPath();                                                             //Setting the icon
    QIcon icon;
    icon.addFile(QString("/home/gege/Scrivania/Drum_Machine/res/icons/metronome.png"));
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
        this->setBackground(Qt::red);
    else
        this->setBackground(Qt::white);
}
void MetronomeWidget::setBackground(QColor color) {
    qDebug()<<"Backgroud changed";
    this->setStyleSheet(QString("background-color: %1").arg(color.name()));
}
void MetronomeWidget::on_pressed() {
    qDebug()<<"Metronome pressed";
    if(metronome->getState() == State::ON)
        metronome->setState(OFF);
    else
        metronome->setState(ON);
}