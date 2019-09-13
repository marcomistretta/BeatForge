//
// Created by misterm on 12/09/19.
//

#include "PlayerWidget.h"

PlayerWidget::PlayerWidget(QWidget *parent) : QAbstractButton(parent) {
    //adding observer
    player->addObserver(this);

    //setting the icon
    QIcon icon;
    icon.addFile(QString("../res/icons/player1.png"));
    this->setIcon(icon);

    qDebug() << "Player Widget constructed";

}

PlayerWidget::~PlayerWidget() {
    delete (player);
    qDebug() << "Player deleted";

}

void PlayerWidget::obsUpdate() {
    qDebug() << "Player Widget Updated";
    if (player->getState()) {
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
    qDebug() << "PLayer pressed";
    obsUpdate();
    if (player->getState() == STATE::ON) {
        player->startStop();
    } else {
        player->startStop();
    }
}

}
