//
// Created by Guglielmo Fratticioli on 15/09/19.
//

#ifndef MYTEST_TIMELINE_H
#define MYTEST_TIMELINE_H
class QHBoxLayout;
class Player;
#include "Observer.h"
#include <QWidget>
#include "Player.h"


class Timeline: public QWidget, public Observer {
public:
    ~Timeline() override;
    void obsUpdate() override;
    Timeline(Player* player, QWidget* parent);

    void setPlayer(Player* player){
        this->player = player;
    }
private:
    Player* player;
    QHBoxLayout * boxLayout;
    std::vector<QWidget*> steps;

};


#endif //MYTEST_TIMELINE_H
