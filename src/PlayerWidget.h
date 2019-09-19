//
// Created by misterm on 12/09/19.
//

#ifndef MYTEST_PLAYERWIDGET_H
#define MYTEST_PLAYERWIDGET_H

class QHBoxLayout;
class QPushButton;
class Player;

#include "Observer.h"
#include <QWidget>

class PlayerWidget : public QWidget, public Observer {
Q_OBJECT
public:
    //CONSTRUCTOR & DESTRUCTOR
    explicit PlayerWidget(Player* player, QWidget *parent = nullptr);
    ~PlayerWidget();

    //OBSERVER
    void obsUpdate();

    //GETTER
    Player *getPlayer() const {
        return player;
    }
    QPushButton * getplayButton() const {
        return  playButton;
    }
    QPushButton * getstopButton() const {
        return stopButton;
    };

    //SETTEDR
    void setPlayer(Player *play) {
        PlayerWidget::player = play;
    }

    //SLOTS
private slots:
    void on_Play_pressed();
    void on_Stop_pressed();

private:
    Player *player;
    QPushButton * playButton;
    QPushButton * stopButton;
    QHBoxLayout *boxLayout;
};


#endif //DRUM_MACHINE_METRONOMEWIDGET_H
