//
// Created by Guglielmo Fratticioli on 15/09/19.
//

#include "Timeline.h"
#include "Player.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QMainWindow>

Timeline::~Timeline() {
    player->removeObserver(this);
}

Timeline::Timeline(Player *player, QWidget *parent) : QWidget(parent), Observer(), player(player) {

    int mainWidth = static_cast<QMainWindow *>(this->parent())->size().width();
    int mainHeight = static_cast<QMainWindow *>(this->parent())->size().height();

    this->setFixedSize(mainHeight * 36, mainWidth / 4);

    player->addObserver(this);
    boxLayout = new QHBoxLayout(this);

    QWidget *space = new QWidget(this);
    space->setFixedWidth(mainWidth / 1.2);
    space->setFixedHeight(mainHeight / 4);
    boxLayout->addWidget(space);

    for (int i = 0; i < 16; i++) {
        QWidget *step = new QWidget(this);
        step->setStyleSheet(QString("*{image: url(../res/icons/Led-OFF.png);}"));
        step->setFixedWidth(mainWidth / 4);
        step->setFixedHeight(mainHeight / 3);
        steps.push_back(step);
        boxLayout->addWidget(step, Qt::AlignBottom);
    }
    this->setLayout(boxLayout);
    obsUpdate();
    qDebug() << "Timeline Constructed";
}

void Timeline::obsUpdate() {
    for (QWidget *step : steps) {
        step->setStyleSheet(QString("*{image: url(../res/icons/Led-OFF.png);}"));
    }
    if (player->isFirstStep()) {
        steps[player->getActualStep()]->setStyleSheet(QString("*{image: url(../res/icons/Led-ON.png);}"));
        player->setFirstStep(false);
        //steps[(player->getActualStep()-1+16)%16]->setStyleSheet(QString("*{image: url(../res/icons/Led-OFF.png);}"));
    } else
        steps[(player->getActualStep() - 1 + 16) % 16]->setStyleSheet(
                QString("*{image: url(../res/icons/Led-ON.png);}"));
    qDebug() << "Led Updated";

}

