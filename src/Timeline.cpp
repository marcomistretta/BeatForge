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

    player->addObserver(this);
    //BOXLAYOUT
    boxLayout = new QHBoxLayout(this);

    //SETTING LED OFF
    for (int i = 0; i < 16; i++) {
        QWidget *step = new QWidget(this);
        step->setStyleSheet(QString("*{image: url(../res/icons/Led-OFF.png);}"));

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
    } else
        steps[(player->getActualStep() - 1 + 16) % 16]->setStyleSheet(
                QString("*{image: url(../res/icons/Led-ON.png);}"));
    qDebug() << "Led Updated";

}

Timeline::~Timeline() {
    //TODO IMPLEMENT destructor
    player->removeObserver(this);
    delete (player);
    delete (boxLayout);
}