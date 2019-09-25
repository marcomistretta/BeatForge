//
// Created by misterm on 12/09/19.
//

#include "Player.h"
#include "PlayerWidget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>

PlayerWidget::PlayerWidget(Player *player, QWidget *parent) : QWidget(parent), player(player) {

    dir = new QDir(QDir::currentPath());
    path = dir->absoluteFilePath("res/icons/");

    setStyleSheet(QString("*{background: transparent}"));
    player->addObserver(this);
    boxLayout = new QHBoxLayout(this);
    playButton = new QPushButton(this);
    stopButton = new QPushButton(this);
    playButton->setFixedSize(width()/2,height()*1.5);
    stopButton->setFixedSize(width()/2,height()*1.5);
    boxLayout->addWidget(playButton);
    boxLayout->addWidget(stopButton);

    //SETTING DEFAULT STATUS
    player->setStatus(OFF);

    QIcon stopIcon;
    stopIcon.addFile(QString(path + "StopButton.png"));
    stopButton->setIcon(stopIcon);
    stopButton->setIconSize(stopButton->size());
    //CONNECTING METHODS
    connect(playButton, SIGNAL(clicked()), this, SLOT(on_Play_pressed()));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(on_Stop_pressed()));
    obsUpdate();
}

PlayerWidget::~PlayerWidget() {
    player->removeObserver(this);
    delete dir;
    delete player;
    delete playButton;
    delete stopButton;
    delete boxLayout;
    qDebug() << "Player deleted";
}

void PlayerWidget::obsUpdate() {
    QIcon playicon;
    if (player->getStatus() == OFF) {
        //red
        playicon.addFile(QString(path + "Play.png"));
        qDebug() << "Player GUI to ON ";

    } else {
        //light-green
        playicon.addFile(QString(path + "Pause.png"));
        qDebug() << "Player GUI to OFF ";
    }
    playButton->setIcon(playicon);
    playButton->setIconSize(playButton->size());
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

