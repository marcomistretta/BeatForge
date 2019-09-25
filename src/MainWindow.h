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
