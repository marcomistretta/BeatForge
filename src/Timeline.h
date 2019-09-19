//
// Created by Guglielmo Fratticioli on 15/09/19.
//

#ifndef MYTEST_TIMELINE_H
#define MYTEST_TIMELINE_H

#include "Observer.h"
#include "Player.h"
#include <QWidget>

class QHBoxLayout;

class Player;

class Timeline: public QWidget, public Observer {
public:
    //CONSTRUCTOR
    Timeline(Player *player, QWidget *parent);

    //DESTRUCTOR
    ~Timeline() override;

    //OBSERVER
    void obsUpdate() override;

    //SETTER
    void setPlayer(Player* player){
        this->player = player;
    }
private:
    Player* player;
    QHBoxLayout * boxLayout;
    std::vector<QWidget*> steps;

};


#endif //MYTEST_TIMELINE_H
