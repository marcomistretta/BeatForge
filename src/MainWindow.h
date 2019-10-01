//
// Created by Guglielmo Fratticioli on 09/07/19.
//

#ifndef MYTEST_MAINWINDOW_H
#define MYTEST_MAINWINDOW_H

#include <QMainWindow>

class QGridLayout;

class QWidget;

class DrumKit;

class DrumKitWidget;

class Metronome;

class MetronomeWidget;

class Player;

class PlayerWidget;

class Timeline;

class DisplayWidget;

class QHBoxLayout;

class QVBoxLayout;

class MainWindow : public QMainWindow {
public:
    //CONSTRUCTOR
    explicit MainWindow(QWidget *parent = nullptr);

    void setUpGui();

    //DESTRUCTOR
    virtual ~MainWindow();

    DrumKit *getDrumKit() const {
        return drumKit;
    }

    DrumKitWidget *getDrumKitWidget() const {
        return drumKitWidget;
    }

    QWidget *getUpperWidget() const {
        return upperWidget;
    }

    QWidget *getMidWidget() const {
        return midWidget;
    }

    QWidget *getBottomWidget() const {
        return bottomWidget;
    }

    Metronome *getMetronome() const {
        return metronome;
    }

    MetronomeWidget *getMetronomeWidget() const {
        return metronomeWidget;
    }

    Player *getPlayer() const {
        return player;
    }

    PlayerWidget *getPlayerWidget() const {
        return playerWidget;
    }

    DisplayWidget *getDisplayWidget() const {
        return displayWidget;
    }

    Timeline *getTimeline() const {
        return timeline;
    }

    QHBoxLayout *getUpperLayout() const {
        return upperLayout;
    }

    QHBoxLayout *getMidLayout() const {
        return midLayout;
    }

    QHBoxLayout *getBottomLayout() const {
        return bottomLayout;
    }

    QVBoxLayout *getVerticalLayout() const {
        return verticalLayout;
    }

    QWidget *getMainWidget() const {
        return mainWidget;
    }

private:
    int height;
    int width;
    DrumKit *drumKit;
    DrumKitWidget *drumKitWidget;
    Metronome *metronome;
    MetronomeWidget *metronomeWidget;
    Player *player;
    PlayerWidget *playerWidget;
    DisplayWidget *displayWidget;

    Timeline *timeline;
    QHBoxLayout *upperLayout;
    QHBoxLayout *midLayout;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *verticalLayout;

    QWidget *upperWidget;
    QWidget *midWidget;
    QWidget *bottomWidget;
    QWidget *mainWidget;


};


#endif //MYTEST_MAINWINDOW_H
