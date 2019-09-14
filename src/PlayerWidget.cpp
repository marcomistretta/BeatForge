//
// Created by misterm on 12/09/19.
//

#include "Player.h"
#include "PlayerWidget.h"


PlayerWidget::PlayerWidget(QWidget *parent) : Observer() {
    player = new Player;
    player->addObserver(this);
    //setting the icon
    QIcon icon;
    icon.addFile(QString("../res/icons/player1.png"));
    this->setIcon(icon);

    qDebug() << "Player Widget constructed";

    //connecting methods
    connect(this, SIGNAL(clicked()), this, SLOT(on_pressed()));
}

PlayerWidget::~PlayerWidget() {
    delete (player);
    qDebug() << "Player deleted";
}

void PlayerWidget::obsUpdate() {
    qDebug() << "Player Widget Updated";
    if (player->getStatus()) {
        //red
        qDebug() << "to Red";
        this->setBackground(QColor(217, 0, 0));
    } else {
        //light-green
        qDebug() << "to light green";
        this->setBackground(QColor(132, 176, 132));
    }
}

void PlayerWidget::setBackground(const QColor &color) {
    qDebug() << "Backgroud changed";
    this->setStyleSheet(QString("background-color: %1").arg(color.name()));
}

void PlayerWidget::on_pressed() {
    qDebug() << "Plyer pressed";
    obsUpdate();
    if (player->getStatus() == STATUS::ON) {
        //TODO
        //player->startStop();
    } else {
        //TODO
        //player->startStop();
    }
}

Player *PlayerWidget::getPlayer() const {
    return player;
}

void PlayerWidget::setPlayer(Player *play) {
    PlayerWidget::player = play;
}
