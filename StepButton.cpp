//
// Created by Guglielmo Fratticioli on 03/08/19.
//

#include "StepButton.h"
#include "DrumWidget.h"

StepButton::StepButton(QWidget *parent): QPushButton(parent) {
    connect(this,SIGNAL(click()),this,SLOT(on_clicked()));
}

void StepButton::setBackground(QColor color) {
    this->setStyleSheet(QString("background-color: %1").arg(color.name()));
}

void StepButton::on_clicked() {
    static_cast<DrumWidget*>(parent())->getDrum()->editStep(position);
}
