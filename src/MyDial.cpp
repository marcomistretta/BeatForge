//
// Created by Guglielmo Fratticioli on 22/09/19.
//

#include "MyDial.h"
#include <QtWidgets>

MyDial::MyDial(QWidget *parent) : QDial(parent) {
    this->setStyleSheet(QString("{color: red;}"));
    this->setNotchesVisible(true);
    volumeLabel = new QLabel(this);
    volumeLabel->setStyleSheet(QString("*{background: rgba(255,255,255,210);}"));
    volumeLabel->hide();
}

void MyDial::mousePressEvent(QMouseEvent *me) {
    volumeLabel->show();
}

void MyDial::mouseReleaseEvent(QMouseEvent *me) {
    volumeLabel->hide();
}

MyDial::~MyDial() {
    delete volumeLabel;

}
