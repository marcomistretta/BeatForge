//
// Created by misterm on 12/09/19.
//

#ifndef MYTEST_PLAYERWIDGET_H
#define MYTEST_PLAYERWIDGET_H

#include <QPushButton>
#include "Subject.h"

class Player;

class PlayerWidget : public QPushButton {
Q_OBJECT
public:
    explicit PlayerWidget(QWidget *parent = nullptr);

    ~PlayerWidget();

    void obsUpdate();

    void setBackground(const QColor &color);

private slots:

    void on_pressed();

private:
    Player *player;
};


#endif //DRUM_MACHINE_METRONOMEWIDGET_H
