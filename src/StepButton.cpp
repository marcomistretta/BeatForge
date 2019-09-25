//
// Created by Guglielmo Fratticioli on 03/08/19.
//

#include "StepButton.h"
#include "DrumWidget.h"
#include "Drum.h"
#include <QDebug>

StepButton::StepButton(QWidget *parent): QPushButton(parent) {
    this->setStyleSheet(QString("background: rgb(255,255,255);"));
    //CONNECTING METHODS
    connect(this,SIGNAL(clicked()),this,SLOT(on_clicked()));
}

void StepButton::setBackground(QColor color) {
    this->setStyleSheet(QString("background-color: %1").arg(color.name()));
}

void StepButton::on_clicked() {
    qDebug()<<"clicked";
    static_cast<DrumWidget*>(parent())->getDrum()->editStep(position);
}

StepButton::~StepButton() {
}
