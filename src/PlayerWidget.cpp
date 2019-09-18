//
// Created by misterm on 12/09/19.
//

#include "Player.h"
#include "PlayerWidget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>

PlayerWidget::PlayerWidget(Player *player, QWidget *parent) : QWidget(parent), player(player) {
    setStyleSheet(QString("*{background: transparent}"));
    player->addObserver(this);
    boxLayout = new QHBoxLayout(this);
    playButton = new QPushButton(this);
    stopButton = new QPushButton(this);
    boxLayout->addWidget(playButton);
    boxLayout->addWidget(stopButton);


    //setting the Status
    player->setStatus(OFF);

    QIcon stopIcon;
    stopIcon.addFile(QString("../res/icons/StopButton.png"));
    stopButton->setIcon(stopIcon);


    connect(playButton, SIGNAL(clicked()), this, SLOT(on_Play_pressed()));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(on_Stop_pressed()));
    obsUpdate();
}

PlayerWidget::~PlayerWidget() {
    delete (player);
    qDebug() << "Player deleted";
}

void PlayerWidget::obsUpdate() {
    QIcon playicon;
    if (player->getStatus() == OFF) {
        //red
        playicon.addFile(QString("../res/icons/Play.png"));
        qDebug() << "Player GUI to ON ";

    } else {
        //light-green
        playicon.addFile(QString("../res/icons/Pause.png"));
        qDebug() << "Player GUI to OFF ";
    }
    playButton->setIcon(playicon);
    qDebug() << "Player Widget Updated";
}

void PlayerWidget::on_Play_pressed() {
    qDebug() << "Play/Pause pressed";
    player->playPauseTimer();
    obsUpdate();
}

void PlayerWidget::on_Stop_pressed() {
    qDebug() << "Stop pressed";
    player->stopTimer();
    obsUpdate();
}

